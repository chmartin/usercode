// 
#include "TFile.h"
#include "TTree.h"
#include "TLeaf.h"
#include <iostream>
#include "TH2F.h"
#include "TH1F.h"
#include "TString.h"
#include "TRint.h"
#include "TChain.h"
#include "TROOT.h"
#include "TStopwatch.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLine.h"
#include "TLegend.h"
#include "TCut.h"
#include "THStack.h"
#include "TNtuple.h"
#include "TMath.h"

#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>

bool debug = false;


typedef enum {kILC, kLHCDECAY, kLHCZH} colliderType;
typedef enum{kF3, kFA3, kF3ACC} varLevel; 
typedef enum{kOneD, kTwoD, kALL} plotLevel; 
typedef enum{EMBED, PURE} toyLevel; 

void drawilcfitresult()
{

  int nBins = 40;
  colliderType collider = kLHCZH;
  plotLevel plot = kOneD;
  toyLevel toy = PURE;
  bool withAcceptance = false;
  
  TString accName = "false";
  if (withAcceptance )  accName = "true";
  
  TString toyMode = "pure";
  if ( toy == EMBED ) toyMode = "embd";

  
  if ( plot == kOneD || plot == kALL ) {
    
    // set the f3 value 
    double f2gen = 0.;
    double f3gen = 0.;
    
    // 
    // ILC plots 
    // 
    if ( collider == kILC ) {
      f2gen = 0.;
      f3gen = 0.1;
      
      vector<float> energies;
      energies.push_back(250.);
      /*
      energies.push_back(350.);
      energies.push_back(500.);
      energies.push_back(1000.);
      */
      //
      // 1D Plots
      // 
      
      for ( int i = 0; i < energies.size() ; i ++ ) {
	float sqrtsVal = energies.at(i);
	TString toyName = Form("%s_f_3_%.0fGeV_acc%s", toyMode.Data(), sqrtsVal, accName.Data());
	drawsingle(sqrtsVal, f2gen, f3gen, toyName, kF3, collider, Form("f_{3}"), nBins);
	//drawsingle(sqrtsVal, f2gen, f3gen, toyName, kFA3, collider, Form("f_{a3}"), nBins);
      }
    } // end of ILC plots

    if ( collider == kLHCZH ) {
      float sqrtsVal = 14000;
      float lumi = 3000; 
      TString toyName = Form("KD_%s_%.0fGeV_acctrue_%.0fifb", toyMode.Data(), sqrtsVal, lumi);
      if ( lumi == 3000. ) f3gen = 0.385797;
      if ( lumi == 300. ) f3gen = 0.5; 
      drawsingle(sqrtsVal, f2gen, f3gen, toyName, kF3, collider, Form("f_{3}"), nBins);
      drawsingle(sqrtsVal, f2gen, f3gen, toyName, kF3ACC, collider, Form("f_{3}"), nBins);
    }
  }

  

  if ( plot == kTwoD || plot == kALL ) {
    // 2D plots
    draw2dsingle("pure_f_2_p15_f_3_250GeV_accfalse", "fa2", "fa3", "f_{2}", "f_{3}", 50, 0, 0.4, 50, 0, 0.4, 0.15, 0.1);
    draw2dsingle("pure_f_3_250GeV_accfalse", "fa3", "phia3",  "f_{3}", "#phi_{3}", 50, 0, 0.4, 50, -1.6, 1.6, 0.1, 0);
  }
  
}


void drawsingle(float sqrtsVal, float f2gen, float f3gen, TString toyName, int variable, colliderType collider, TString varName, int nBins)
{

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle();");
  gROOT->ForceStyle();
  
  float fa2gen(0.);
  float fa3gen(0.);
  if ( collider == kLHCZH && ( variable == kF3ACC || variable == kF3 ) ) 
    f3gen = calcfacc(f3gen);
  calcgcoup(f2gen, f3gen, sqrtsVal, collider, fa2gen, fa3gen);

  float xgen = 0.;
  float xerr = 0.;
  TString var; 

  if ( variable == kF3 ) {
    var = "f3";
    xgen = f3gen;    
  }
  
  if ( variable == kFA3 ) {
    var = "fa3";
    xgen = fa3gen;
  }

  if ( variable == kF3ACC ) {
    var = "f3_aftercut";
    xgen = f3gen;    
  }
  
  // assume the expected err is 1/3 of the generated values
  xerr = xgen / 3.;
  float xMin = TMath::Max(xgen-6.*xerr,0.);
  float xMax = TMath::Min(xgen+6.*xerr,1.);
  
  std::cout << "xgen = " << xgen << "\n";
 
  TH1F *h_var = new TH1F("h_var", "h_var", nBins, xMin, xMax);
  TH1F *h_var_pull = new TH1F("h_var_pull", "h_var_pull", 40, -4, 4);

  TString toyDir = "toyresults_ilc/";
  
  if ( collider == kLHCZH ) 
    toyDir = "toyresults_ppzh";

  TString fileName = Form("%s/toyresults_%s.root", toyDir.Data(), toyName.Data());
  TFile *file = new TFile(fileName, "READ");
  gROOT->cd();
  std::cout << "Opening " << fileName << "\n";
  TTree *tree = (TTree*)file->Get("fittree");
  if ( ! tree ) return;

  // do an event loop
  float f2_ = 0.;
  float f2_err_ = 0.;
  float f2_pull_ = 0.;
  float f3_ = 0.;
  float f3_err_ = 0.;
  float f3_pull_ = 0.;
  float phi3_ = 0.;
  float phi3_err_ = 0.;
  float phi3_pull_ = 0.;

  if ( tree->GetBranchStatus("fa2") )
    tree->SetBranchAddress("fa2"        , &f2_        );
  if ( tree->GetBranchStatus("fa2_err") )
    tree->SetBranchAddress("fa2_err"    , &f2_err_    );
  if ( tree->GetBranchStatus("fa2_pull") )
    tree->SetBranchAddress("fa2_pull"   , &f2_pull_   );
  if ( tree->GetBranchStatus("fa3") )
    tree->SetBranchAddress("fa3"        , &f3_        );
  if ( tree->GetBranchStatus("fa3_err") )
    tree->SetBranchAddress("fa3_err"    , &f3_err_    );
  if ( tree->GetBranchStatus("fa3_pull") )
    tree->SetBranchAddress("fa3_pull"   , &f3_pull_   );
  if ( tree->GetBranchStatus("phia3") )
    tree->SetBranchAddress("phia3"      , &phi3_      );
  if ( tree->GetBranchStatus("phia3_err") )
    tree->SetBranchAddress("phia3_err"  , &phi3_err_  );
  if ( tree->GetBranchStatus("phia3_pull") )
  tree->SetBranchAddress("phia3_pull" , &phi3_pull_ );
  
  for(int ievt = 0; ievt < tree->GetEntries() ;ievt++){
    tree->GetEntry(ievt); 
    
    if ( collider == kLHCZH) {
      if ( variable == kF3 ) {
	double f3_bf_acc = calcfacc(f3_);
	h_var->Fill(f3_bf_acc);
	h_var_pull->Fill(f3_pull_);
      } else if ( variable == kF3ACC ) {
	h_var->Fill(f3_);
	h_var_pull->Fill(f3_pull_);
      }
    } else {
      if ( variable == kF3 ) {
	h_var->Fill(f3_);
	h_var_pull->Fill(f3_pull_);
      }
      
      if ( variable == kFA3 ) {
	float fa2_ = 0.;
	float fa3_ = 0.;
	calcgcoup(f2_, f3_, sqrtsVal, kILC, fa2_, fa3_);
	h_var->Fill(fa3_);
	h_var_pull->Fill(f3_pull_);
      }
    }
    
  }

  h_var->SetXTitle(varName);
  h_var->GetXaxis()->CenterTitle(true);
  h_var->GetYaxis()->CenterTitle(true);

  h_var_pull->SetXTitle(Form("%s(fit)-%s(in)/#sigma(%s)", varName.Data(), varName.Data(), varName.Data()));
  h_var_pull->GetXaxis()->CenterTitle(true);
  h_var_pull->GetYaxis()->CenterTitle(true);
  
  
  h_var->Scale(1./h_var->Integral());
  h_var_pull->Scale(1./h_var->Integral());

  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);
  c1->cd();
  if ( variable == kFA3 ) 
    c1->SetRightMargin(0.11);
  h_var->Draw("hist");
  double xfit_min = TMath::Max (h_var->GetMean() - 3*h_var->GetRMS(), 0.);
  double xfit_max = TMath::Min (h_var->GetMean() + 3*h_var->GetRMS(), 1.);
  h_var->Fit("gaus", "", "", xfit_min, xfit_max);
  c1->SaveAs(Form("%s/plots/%s_fitresults_%s.eps", toyDir.Data(), var.Data(), toyName.Data()));
  c1->SaveAs(Form("%s/plots//%s_fitresults_%s.png", toyDir.Data(), var.Data(), toyName.Data()));

  //
  // get the fit results and calculate the fa3 errors
  // 
  TF1 *gfit = (TF1 *)h_var->GetFunction("gaus");
  float fitmean = gfit->GetParameter(1); 
  float fitsigma = gfit->GetParameter(2); 


  float f3mean = fitmean; 
  float f3sigma = fitsigma; 
  std::cout << "-----------------------------------------------------\n";
  std::cout << Form("Results for sqrts = %.0f GeV\n", sqrtsVal) ;
  std::cout << Form("toy fit results : %.3f +/- %.3f\n", fitmean, fitsigma);
  float f3_p1sigma = f3mean + f3sigma;
  float f3_m1sigma = f3mean - f3sigma;  
  
  // special for the ppZH, need to convert the f3 after cut to before the cut
  if ( collider == kLHCZH && variable == kF3ACC) {
    f3mean = calcfacc(fitmean);
    f3_p1sigma = calcfacc(fitmean + fitsigma);
    f3_m1sigma = calcfacc(fitmean - fitsigma);
  }
  std::cout << Form("f3 (before cuts) generated: %.3f \n",  f3gen);
  std::cout << Form("f3 (before cuts) from toy fits: %.3f (+ %.3f, -%.3f)\n",  f3mean, f3_p1sigma-f3mean, f3mean-f3_m1sigma);
  std::cout << "-----------------------------------------------------\n";
  float fa2_mean = 0.; // dummy  
  float fa3_mean = 0.;
  calcgcoup(0, f3mean, sqrtsVal, collider, fa2_mean , fa3_mean);

  float fa3_p1sigma = 0.;
  float fa2_p1sigma = 0.; // dummy
  calcgcoup(0, f3_p1sigma, sqrtsVal, collider, fa2_p1sigma , fa3_p1sigma);

  float fa3_m1sigma = 0.;
  float fa2_m1sigma = 0.; // dummy
  calcgcoup(0, f3_m1sigma, sqrtsVal, collider, fa2_m1sigma , fa3_m1sigma);

  std::cout << Form("fa3 generator input : %.7f\n", fa3gen);   
  std::cout << Form("fa3 results from fit : %.7f (+%.7f, -%.7f)\n", fa3_mean, fa3_p1sigma-fa3_mean, fa3_mean-fa3_m1sigma); 
  std::cout << "-----------------------------------------------------\n";


  /*
  c1->Clear();
  h_var_pull->Draw("hist");
  h_var_pull->Fit("gaus");
  
  c1->SaveAs(Form("%s/plots/%s_pull_fitresults_%s.eps", toyDir.Data(), var.Data(), toyName.Data()));
  c1->SaveAs(Form("%s/plots/%s_pull_fitresults_%s.png", toyDir.Data(), var.Data(), toyName.Data()));

  */
  delete h_var;
  delete h_var_pull;
  delete c1;
  file->Close();
  
}


void draw2dsingle(TString toyName, TString xVar, TString yVar, TString xTitle, TString yTitle, 
		  int nBinsX, double xMin, double xMax, int nBinsY, double yMin, double yMax, double xgen, double ygen) 
{

  gROOT->ProcessLine(".L tdrstyle.C");
  gROOT->ProcessLine("setTDRStyle();");
  gROOT->ForceStyle();

  TString fileName = Form("toyresults_ilc/toyresults_%s.root", toyName.Data());
  TFile *file = new TFile(fileName, "READ");
  gROOT->cd();
  std::cout << "Opening " << fileName << "\n";
  TTree *tree = (TTree*)file->Get("fittree");
  if ( ! tree ) return;
  
  TString cut = "1";
   
  TH2F *h_var = new TH2F("h_var", "h_var", nBinsX, xMin, xMax, nBinsY, yMin, yMax); 
  tree->Project("h_var", Form("%s:%s", yVar.Data(), xVar.Data()), cut);
  h_var->SetXTitle(xTitle);
  h_var->SetYTitle(yTitle);
  h_var->GetXaxis()->CenterTitle(true);
  h_var->GetYaxis()->CenterTitle(true);
  
  TH2F *h_var_clone= (h_var->Clone("clone"));
  h_var_clone->SetXTitle(xTitle);
  h_var_clone->SetYTitle(yTitle);

  //code for 2D fancy plot
  int nx = h_var->GetNbinsX();
  int ny = h_var->GetNbinsY();

  Double_t Sum = h_var->Integral();
  h_var->Scale(1./Sum);
 
  vector<Double_t> conf; 
  conf.push_back(0.9999);
  conf.push_back(0.999);
  conf.push_back(0.997);
  conf.push_back(0.955);
  conf.push_back(0.683);

  Double_t level[5];
  Double_t area[5];
  for (int j=0; j<5; j++) {
    level[j] = 0.;
    area[j] = 0.;
  }

  vector< Double_t > OrderedGArray;
  for (int ix=1; ix<=nx; ix++) {
    for (int iy=1; iy<=ny; iy++) {
      OrderedGArray.push_back(h_var->GetCellContent(ix,iy));
    }
  }
  
  std::cout<<"before sort"<<std::endl;
  std::sort( OrderedGArray.begin(), OrderedGArray.end());
  std::reverse(OrderedGArray.begin(),OrderedGArray.end());
  std::cout<<"after sort"<<std::endl;

  vector< Double_t> SumArray;
  SumArray.push_back(OrderedGArray[0]);
  cout<<"ordered g array"<<endl;
  for (int i=1; i<= (int) OrderedGArray.size(); i++) {
    if((fabs(OrderedGArray[i])>0) && ((i%100)==1))
      cout<<OrderedGArray[i]<<endl;;
    SumArray.push_back(SumArray[i-1] + OrderedGArray[i]);
    for (int j=0; j<5; j++) {
      if (SumArray[i] <= conf[j]) {
	level[j] = OrderedGArray[i];
	area[j] = SumArray[i];
      }
    }
  }

  h_var->Smooth(2);

  for (int j=0; j<5; j++) {
    std::cout << "level: " << level[j] << std::endl;
    std::cout << "area: " << area[j] << std::endl;
  }

  TH2F *h_clone= (h_var->Clone("clone"));

  h_clone->SetContour(1);
  h_clone->SetContourLevel(0,level[3]);

  h_var->SetContour(1);
  h_var->SetContourLevel(0,level[4]);

  Int_t n=35;
  Int_t *colors = new Int_t[n];
  for (Int_t i =0; i < n; i++) {
    colors[i] = i+63;
  }
  gStyle->SetPalette(n, colors); 

  //
  // Add a marker to the generated value
  // 

  Double_t x[1]; 
  Double_t y[1];
  x[0] = xgen;
  y[0] = ygen;
  
  TGraph *gr = new TGraph(1, x, y);
  gr->SetMarkerStyle(34);
  gr->SetMarkerSize(2.5);

  TCanvas *c1 = new TCanvas("c1", "c1", 600, 600);
  c1->cd();
  c1->SetLeftMargin(0.17);
  //c1->SetRightMargin(0.14);
  h_var_clone->Draw("COL");
  h_var->SetLineColor(1);
  h_var->SetLineWidth(2);
  h_var->Draw("cont3same");
  h_clone->SetLineColor(1);
  h_clone->SetLineWidth(2);
  h_clone->SetLineStyle(2);
  h_clone->Draw("cont3same");
  gr->Draw("samep");
  
  c1->SaveAs(Form("toyresults_ilc/plots/%s_vs_%s_fitresults_%s.eps", yVar.Data(), xVar.Data(), toyName.Data()));
  c1->SaveAs(Form("toyresults_ilc/plots/%s_vs_%s_fitresults_%s.png", yVar.Data(), xVar.Data(), toyName.Data()));

  delete h_var;
  file->Close();
  delete c1;
}


void calcgcoup(double f2, double f3, double sqrts = 250., colliderType machine = kLHCZH, float &fa2, float &fa3){

  Double_t sigma1;
  Double_t sigma2;
  Double_t sigma4;
  

  // ILC numbers at 250 GeV at mH= 125 GeV (narrow Z width approximation)
  Double_t sigma1_e = 0.981396; // was 0.94696 at 126 GeV
  Double_t sigma2_e = 33.4674;  // was 32.1981 at 126 GeV
  Double_t sigma4_e = 7.9229;   // was 7.45502 at 126 GeV
  
  // ILC nubmers at 350 GeV at mH = 125 GeV
  if ( sqrts == 350. ) {
    sigma1_e = 1.48872; 
    sigma2_e = 125.387;  
    sigma4_e = 75.3199;
  }
  
  // ILC nubmers at 500 GeV at mH = 125 GeV
  if ( sqrts == 500. ) {
    sigma1_e = 2.57246; 
    sigma2_e = 516.556;  
    sigma4_e = 414.378;
  }
  
  // ILC nubmers at 1000 GeV at mH = 125 GeV
  if ( sqrts == 1000. ) {
    sigma1_e = 8.95721; 
    sigma2_e = 8208.91;  
    sigma4_e = 7800.2;
  }

  if (machine == kILC) {
    sigma1 = sigma1_e;
    sigma2 = sigma2_e;
    sigma4 = sigma4_e;
  }

  // For the decay
  Double_t sigma1_pdecay = 1.860351; // was 2.03971 at 126 GeV
  Double_t sigma2_pdecay = 0.672859; // was 0.77517 at 126 GeV
  Double_t sigma4_pdecay = 0.284353; // was 0.32689 at 126 GeV
  
  Double_t sigma1_p = 1.860351; // was 2.03971 at 126 GeV
  Double_t sigma2_p = 0.672859; // was 0.77517 at 126 GeV
  Double_t sigma4_p = 0.284353; // was 0.32689 at 126 GeV


 if ( machine == kLHCZH ) {
    sigma1_p = 198.7906;
    sigma2_p = 0.0000000001;
    // sigma4_p = 9493.1962;
    sigma4_p = 9000.;
  }

  if (machine == kLHCZH || machine == kLHCDECAY) {
    sigma1 = sigma1_p;
    sigma2 = sigma2_p;
    sigma4 = sigma4_p;
  }

  
  // get g2 and g4 

  double sigma_total = sigma1 / ( 1. - f2 - f3 ) ;
  double g1 = 1.;
  double g2 = sqrt(f2 * sigma_total  / sigma2);
  double g4 = sqrt(f3 * sigma_total  / sigma4);

  // calculate fa2 and fa3
  
 // calculate fa2 and fa3
  
  Double_t fg2_pdecay = sigma2_pdecay*g2*g2 / (  sigma1_pdecay*g1*g1 + sigma2_pdecay*g2*g2 + sigma4_pdecay*g4*g4 );
  Double_t fg4_pdecay = sigma4_pdecay*g4*g4 / (  sigma1_pdecay*g1*g1 + sigma2_pdecay*g2*g2 + sigma4_pdecay*g4*g4 );

  /*
  std::cout << "--- f2 = " << f2 << ", f3 = " << f3 << "\n"; 
  std::cout << "--- g1 = 1, g2 = " << g2 << ", g4 = " << g4 << "\n";
  std::cout << " --- LHC (mH=125 GeV):   fa2 = " << fg2_pdecay << "   fa3 = "<< fg4_pdecay << endl; 
  */  

  fa2 = fg2_pdecay;
  fa3 = fg4_pdecay;
  
}

double calcfacc(double f3_acc)
{
  // R = eff_0plus_vs_0minus 
  double R =  0.176893;
  //   double f3 = (R*f3_acc) / (1+(R-1)*f3_acc);
  double f3 = 1. / (1. + (1./f3_acc-1.)/R);
  return f3;
  
}
