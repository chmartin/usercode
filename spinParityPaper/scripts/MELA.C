#include "RooRealVar.h"
#include "TFile.h"
#include "TChain.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TF1.h"
#include "TLorentzVector.h"
#include "TCanvas.h"
#include <sstream>
#include <vector>
#include "../src/AngularPdfFactory.cc"
#include "../src/ScalarPdfFactory.cc"
#include "../src/VectorPdfFactory.cc"
#include "../src/TensorPdfFactory.cc"
#include "../PDFs/RooqqZZ_JHU.h"

#include "MELA.h"

/* - - - - - - - - - - - - - - - - - - - - - - - 
================================================

be sure to compile/load everything:

gSystem->AddIncludePath("-I/$ROOFITSYS/include/");

.L ../PDFs/RooXZsZs_5D.cxx+
.L ../PDFs/RooSpinOne_7D.cxx+
.L ../PDFs/RooSpinTwo_7D.cxx+
.L ../src/AngularPdfFactory.cc+
.L ../src/ScalarPdfFactory.cc+
.L ../src/VectorPdfFactory.cc+
.L ../src/TensorPdfFactory.cc+
.L ../PDFs/RooqqZZ_JHU.cxx+

.L MELA.C+
 - -  - - - - - - - - - - - - - - -  - - -  -  -
===============================================*/

using namespace RooFit ;

int mZZbins=350;
int lowMzz=100;
int highMzz=800;
int lowM2=12;

TFile *tempf = new TFile("../datafiles/my8DTemplateNotNorm.root","READ");

void setTemplate(char* file){
  if (tempf !=0)
    delete tempf;

  tempf= new TFile(file,"READ");
  tempf->Print("v");
}

template <typename U>
void checkZorder(U& z1mass, U& z2mass,
                 U& costhetastar, U& costheta1,
                 U& costheta2, U& phi,
                 U& phistar1){

  U tempZ1mass=z1mass;
  U tempZ2mass=z2mass;
  U tempH1=costheta1;
  U tempH2=costheta2;
  U tempHs=costhetastar;
  U tempPhi1=phistar1;
  U tempPhi=phi;

  if(z2mass>z1mass){

    z1mass=tempZ2mass;
    z2mass=tempZ1mass;
    costhetastar=-tempHs;
    costheta1=tempH2;
    costheta2=tempH1;
    phi=tempPhi;
    phistar1=-tempPhi1-tempPhi;
    if(phistar1>3.1415)
      phistar1=phistar1-2*3.1415;
    if(phistar1<-3.1415)
      phistar1=phistar1+2*3.1415;

  }else
    return;

}

vector<double> my8DTemplate(bool normalized,double mZZ, double m1, double m2, double costhetastar, double costheta1, double costheta2, double phi, double phi1){

  //read from a file the 3D and 2D template
  TH1F *h_mzz= (TH1F*)(tempf->Get("h_mzz"));
  TH3F *h_mzzm1m2= (TH3F*)(tempf->Get("h_mzzm1m2"));
  TH2F *h_mzzcosthetastar= (TH2F*)(tempf->Get("h_mzzcosthetastar"));
  TH2F *h_mzzcostheta1= (TH2F*)(tempf->Get("h_mzzcostheta1"));
  TH2F *h_mzzcostheta2= (TH2F*)(tempf->Get("h_mzzcostheta2"));
  TH2F *h_mzzphi1= (TH2F*)(tempf->Get("h_mzzphi1"));
  TH2F *h_mzzphi= (TH2F*)(tempf->Get("h_mzzphi"));

  //multiply the P values
  double n = h_mzz->GetBinContent(h_mzz->FindBin(mZZ));
  double Pmzzm1m2 = h_mzzm1m2->GetBinContent(h_mzzm1m2->FindBin(mZZ,m1,m2));

  // - - - - - - - - - - - - - - - whitbeck
  // if bin has no events: add 1
  // safety feature to prevent LD = 1 as a
  // result of low statistics

  if(Pmzzm1m2==0){
    Pmzzm1m2++;
    }
  // - - - - - - - - - - - - - - - 

  double Pmzzcosthetastar = h_mzzcosthetastar->GetBinContent(h_mzzcosthetastar->FindBin(mZZ,costhetastar));
  double Pmzzcostheta2 = h_mzzcostheta2->GetBinContent(h_mzzcostheta2->FindBin(mZZ,costheta2));
  double Pmzzcostheta1 = h_mzzcostheta1->GetBinContent(h_mzzcostheta1->FindBin(mZZ,costheta1));
  double Pmzzphi1 = h_mzzphi1->GetBinContent(h_mzzphi1->FindBin(mZZ,phi1));
  double Pmzzphi = h_mzzphi->GetBinContent(h_mzzphi->FindBin(mZZ,phi));

  //normalization
  double binwidth_mzzm1m2 = h_mzzm1m2->GetYaxis()->GetBinWidth(1) * h_mzzm1m2->GetZaxis()->GetBinWidth(1);
  double binwidth_mzzcosthetastar = h_mzzcosthetastar->GetYaxis()->GetBinWidth(1);
  double binwidth_mzzcostheta1 = h_mzzcostheta1->GetYaxis()->GetBinWidth(1);
  double binwidth_mzzcostheta2 = h_mzzcostheta1->GetYaxis()->GetBinWidth(1);
  double binwidth_mzzphi1 = h_mzzphi1->GetYaxis()->GetBinWidth(1);
  double binwidth_mzzphi = h_mzzphi->GetYaxis()->GetBinWidth(1);

  double Pmzzm1m2_norm = Pmzzm1m2/(n*binwidth_mzzm1m2); 
  double Pmzzcosthetastar_norm = Pmzzcosthetastar/(n*binwidth_mzzcosthetastar);
  double Pmzzcostheta1_norm = Pmzzcostheta1/(n*binwidth_mzzcostheta1);
  double Pmzzcostheta2_norm = Pmzzcostheta2/(n*binwidth_mzzcostheta2);
  double Pmzzphi1_norm = Pmzzphi1/(n*binwidth_mzzphi1);
  double Pmzzphi_norm = Pmzzphi/(n*binwidth_mzzphi);

  vector <double> P;
  P.push_back(Pmzzm1m2);
  P.push_back(Pmzzcosthetastar);
  P.push_back(Pmzzcostheta1);
  P.push_back(Pmzzcostheta2);
  P.push_back(Pmzzphi);
  P.push_back(Pmzzphi1);

  vector <double> P_norm;
  P_norm.push_back(Pmzzm1m2_norm);
  P_norm.push_back(Pmzzcosthetastar_norm);
  P_norm.push_back(Pmzzcostheta1_norm);
  P_norm.push_back(Pmzzcostheta2_norm);
  P_norm.push_back(Pmzzphi_norm);
  P_norm.push_back(Pmzzphi1_norm);

  if(normalized)
    return P_norm;
  else
    return P;
}

//=======================================================================

pair<double,double> likelihoodDiscriminant (double mZZ, double m1, double m2, double costhetastar, double costheta1, double costheta2, double phi, double phi1,double scaleFactor){

  RooRealVar* z1mass_rrv = new RooRealVar("z1mass","m_{Z1}",0,180);
  RooRealVar* z2mass_rrv = new RooRealVar("z2mass","m_{Z2}",0,120); 
  RooRealVar* costheta1_rrv = new RooRealVar("costheta1","cos#theta_{1}",-1,1);  
  RooRealVar* costheta2_rrv = new RooRealVar("costheta2","cos#theta_{2}",-1,1);
  RooRealVar* phi_rrv= new RooRealVar("phi","#Phi",-3.1415,3.1415);
  RooRealVar* costhetastar_rrv = new RooRealVar("costhetastar","cos#theta^{*}",-1,1); 
  RooRealVar* phi1_rrv= new RooRealVar("phi1","#Phi^{*}_{1}",-3.1415,3.1415);
  RooRealVar* mzz_rrv= new RooRealVar("mzz","mZZ",80,1000);

  ScalarPdfFactory *SMHiggs = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  SMHiggs->makeSMHiggs();
  SMHiggs->makeParamsConst(true);
  RooqqZZ_JHU* SMZZ = new RooqqZZ_JHU("SMZZ","SMZZ",*z1mass_rrv,*z2mass_rrv,*costheta1_rrv,*costheta2_rrv,*phi_rrv,*costhetastar_rrv,*phi1_rrv,*mzz_rrv);

  checkZorder<double>(m1,m2,costhetastar,costheta1,costheta2,phi,phi1);

  z1mass_rrv->setVal(m1);  
  z2mass_rrv->setVal(m2);
  costheta1_rrv->setVal(costheta1);
  costheta2_rrv->setVal(costheta2);
  phi_rrv->setVal(phi);
  costhetastar_rrv->setVal(costhetastar);
  phi1_rrv->setVal(phi1);
  mzz_rrv->setVal(mZZ);

  vector <double> P=my8DTemplate(1, mZZ,  m1,  m2,  costhetastar,  costheta1,  costheta2,  phi,  phi1);

  double Pbackg=0.;
  double Psig=0.;

  if(mZZ>80 && mZZ<180){
    Pbackg = P[0]*P[1]*P[2]*P[3]*P[4]*P[5]*10.0;
    Psig = SMHiggs->getVal(mZZ);
  }if(mZZ>180&&mZZ<=2*91.188){
    z1mass_rrv->setVal(mZZ/2. - 1e-9);
    z2mass_rrv->setVal(mZZ/2. - 1e-9);
    Pbackg = SMZZ->getVal()/(SMZZ->createIntegral(RooArgSet(*costhetastar_rrv,*costheta1_rrv,*costheta2_rrv,*phi_rrv,*phi1_rrv))->getVal())*10.0;
    Psig = SMHiggs->PDF->getVal()/(SMHiggs->PDF->createIntegral(RooArgSet(*costheta1_rrv,*costheta2_rrv,*phi_rrv))->getVal());
  }if(mZZ>2*91.188){
    z1mass_rrv->setVal(91.188);
    z2mass_rrv->setVal(91.188);
    Pbackg = SMZZ->getVal()/(SMZZ->createIntegral(RooArgSet(*costhetastar_rrv,*costheta1_rrv,*costheta2_rrv,*phi_rrv,*phi1_rrv))->getVal())*10.0;
    Psig = SMHiggs->PDF->getVal()/(SMHiggs->PDF->createIntegral(RooArgSet(*costheta1_rrv,*costheta2_rrv,*phi_rrv))->getVal());
  }

  // - - - - - - - - - - - - - - - - - - - - - Whitbeck 
  // check whether P[i] is zero and print warning
  // message if so

  const char* varName[6]={"m1/m2","costhetastar","costheta1","coshteta2","phi","phi1"};
  for(int iVar=0; iVar<6; iVar++){

    if(P[iVar]==0 && (m1+m2)<mZZ && m2>4 && mZZ>80 && mZZ<180)
	cout << " uh oh... Probability of " << varName[iVar] << " is zero." << endl;
  }
  // - - - - - - - - - - - - - - - - - - - - - 
 
  delete z1mass_rrv; 
  delete z2mass_rrv; 
  delete costheta1_rrv;
  delete costheta2_rrv;
  delete phi_rrv;
  delete costhetastar_rrv;
  delete phi1_rrv;
  delete mzz_rrv; 
  delete SMZZ;
  delete SMHiggs;

  return make_pair(Psig,Pbackg);
}

//=======================================================================

double pseudoMELAcalculator(double zzmass, double z1mass, 
			    double z2mass, double costhetastar, 
			    double costheta1, double costheta2, 
			    double phi, double phistar1){
  
  RooRealVar* z1mass_rrv	= new RooRealVar("z1mass","m_{Z1}",0,180);
  RooRealVar* z2mass_rrv	= new RooRealVar("z2mass","m_{Z2}",0,120);
  RooRealVar* costheta1_rrv	= new RooRealVar("costheta1","cos#theta_{1}",-1,1);
  RooRealVar* costheta2_rrv	= new RooRealVar("costheta2","cos#theta_{2}",-1,1);
  RooRealVar* phi_rrv		= new RooRealVar("phi","#Phi",-3.1415,3.1415);
  RooRealVar* costhetastar_rrv	= new RooRealVar("costhetastar","cos#theta^{*}",-1,1);
  RooRealVar* phistar1_rrv	= new RooRealVar("phistar1","#Phi^{*}_{1}",-3.1415,3.1415);
  RooRealVar* mzz_rrv           = new RooRealVar("mzz","mZZ",80,1000);
  
  ScalarPdfFactory* model = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  model->makeSMHiggs();
  model->makeParamsConst(true);

  ScalarPdfFactory* altModel = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  altModel->makePSHiggs();
  altModel->makeParamsConst(true);

  checkZorder(z1mass,z2mass,costhetastar,costheta1,costheta2,phi,phistar1);
  
  z1mass_rrv->setVal(z1mass);
  z2mass_rrv->setVal(z2mass);
  costhetastar_rrv->setVal(costhetastar);
  costheta1_rrv->setVal(costheta1);
  costheta2_rrv->setVal(costheta2);
  phi_rrv->setVal(phi);
  phistar1_rrv->setVal(phistar1);
  
  mzz_rrv->setVal(zzmass);
  
  //double result = 1/(1+altModel->getVal(zzmass)/(1e1*model->getVal(zzmass)));
  double result = 1/(1+altModel->getVal(zzmass)/(model->getVal(zzmass)));
  
  delete z1mass_rrv;
  delete z2mass_rrv;
  delete costheta1_rrv;
  delete costheta2_rrv;
  delete phi_rrv;
  delete costhetastar_rrv;
  delete phistar1_rrv;
  delete mzz_rrv;

  delete model;
  delete altModel;

  return result;

}

double graviMELAcalculator(double zzmass, double z1mass, 
			   double z2mass, double costhetastar, 
			   double costheta1, double costheta2, 
			   double phi, double phistar1){

  RooRealVar* z1mass_rrv	= new RooRealVar("z1mass","m_{Z1}",0,180);
  RooRealVar* z2mass_rrv	= new RooRealVar("z2mass","m_{Z2}",0,120);
  RooRealVar* costheta1_rrv	= new RooRealVar("costheta1","cos#theta_{1}",-1,1);
  RooRealVar* costheta2_rrv	= new RooRealVar("costheta2","cos#theta_{2}",-1,1);
  RooRealVar* phi_rrv		= new RooRealVar("phi","#Phi",-3.1415,3.1415);
  RooRealVar* costhetastar_rrv	= new RooRealVar("costhetastar","cos#theta^{*}",-1,1);
  RooRealVar* phistar1_rrv	= new RooRealVar("phistar1","#Phi^{*}_{1}",-3.1415,3.1415);
  RooRealVar* mzz_rrv           = new RooRealVar("mzz","mZZ",80,1000);
  
  ScalarPdfFactory* model = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  model->makeSMHiggs();
  model->makeParamsConst(true);

  TensorPdfFactory* altModel = new TensorPdfFactory(z1mass_rrv,z2mass_rrv,costhetastar_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,phistar1_rrv,mzz_rrv);
  altModel->makeMinGrav();
  altModel->makeParamsConst(true);

  checkZorder(z1mass,z2mass,costhetastar,costheta1,costheta2,phi,phistar1);
  
  z1mass_rrv->setVal(z1mass);
  z2mass_rrv->setVal(z2mass);
  costhetastar_rrv->setVal(costhetastar);
  costheta1_rrv->setVal(costheta1);
  costheta2_rrv->setVal(costheta2);
  phi_rrv->setVal(phi);
  phistar1_rrv->setVal(phistar1);
  
  mzz_rrv->setVal(zzmass);
  
  //double result = 1/(1+altModel->getVal(zzmass)/(1*model->getVal(zzmass)));
  double result = 1/(1+altModel->getVal(zzmass)/(model->getVal(zzmass)));
  
  delete z1mass_rrv;
  delete z2mass_rrv;
  delete costheta1_rrv;
  delete costheta2_rrv;
  delete phi_rrv;
  delete costhetastar_rrv;
  delete phistar1_rrv;
  delete mzz_rrv;

  delete model;
  delete altModel;

  return result;

}

double vectorMELAcalculator(double zzmass, double z1mass, 
			    double z2mass, double costhetastar, 
			    double costheta1, double costheta2, 
			    double phi, double phistar1){
  
  RooRealVar* z1mass_rrv	= new RooRealVar("z1mass","m_{Z1}",0,180);
  RooRealVar* z2mass_rrv	= new RooRealVar("z2mass","m_{Z2}",0,120);
  RooRealVar* costheta1_rrv	= new RooRealVar("costheta1","cos#theta_{1}",-1,1);
  RooRealVar* costheta2_rrv	= new RooRealVar("costheta2","cos#theta_{2}",-1,1);
  RooRealVar* phi_rrv		= new RooRealVar("phi","#Phi",-3.1415,3.1415);
  RooRealVar* costhetastar_rrv	= new RooRealVar("costhetastar","cos#theta^{*}",-1,1);
  RooRealVar* phistar1_rrv	= new RooRealVar("phistar1","#Phi^{*}_{1}",-3.1415,3.1415);
  RooRealVar* mzz_rrv           = new RooRealVar("mzz","mZZ",80,1000);
  
  ScalarPdfFactory* model = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  model->makeSMHiggs();
  model->makeParamsConst(true);

  VectorPdfFactory* altModel = new VectorPdfFactory(z1mass_rrv,z2mass_rrv,costhetastar_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,phistar1_rrv,mzz_rrv);
  altModel->makeZprime();
  altModel->makeParamsConst(true);

  checkZorder(z1mass,z2mass,costhetastar,costheta1,costheta2,phi,phistar1);
  
  z1mass_rrv->setVal(z1mass);
  z2mass_rrv->setVal(z2mass);
  costhetastar_rrv->setVal(costhetastar);
  costheta1_rrv->setVal(costheta1);
  costheta2_rrv->setVal(costheta2);
  phi_rrv->setVal(phi);
  phistar1_rrv->setVal(phistar1);
  
  mzz_rrv->setVal(zzmass);
  
  //double result = 1/(1+altModel->getVal(zzmass)/(1e-3*model->getVal(zzmass)));
  double result = 1/(1+altModel->getVal(zzmass)/(model->getVal(zzmass)));
  
  delete z1mass_rrv;
  delete z2mass_rrv;
  delete costheta1_rrv;
  delete costheta2_rrv;
  delete phi_rrv;
  delete costhetastar_rrv;
  delete phistar1_rrv;
  delete mzz_rrv;

  delete model;
  delete altModel;

  return result;


}

double psVectorMELAcalculator(double zzmass, double z1mass, 
			      double z2mass, double costhetastar, 
			      double costheta1, double costheta2, 
			      double phi, double phistar1){
  
  RooRealVar* z1mass_rrv	= new RooRealVar("z1mass","m_{Z1}",0,180);
  RooRealVar* z2mass_rrv	= new RooRealVar("z2mass","m_{Z2}",0,120);
  RooRealVar* costheta1_rrv	= new RooRealVar("costheta1","cos#theta_{1}",-1,1);
  RooRealVar* costheta2_rrv	= new RooRealVar("costheta2","cos#theta_{2}",-1,1);
  RooRealVar* phi_rrv		= new RooRealVar("phi","#Phi",-3.1415,3.1415);
  RooRealVar* costhetastar_rrv	= new RooRealVar("costhetastar","cos#theta^{*}",-1,1);
  RooRealVar* phistar1_rrv	= new RooRealVar("phistar1","#Phi^{*}_{1}",-3.1415,3.1415);
  RooRealVar* mzz_rrv           = new RooRealVar("mzz","mZZ",80,1000);
  
  ScalarPdfFactory* model = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  model->makeSMHiggs();
  model->makeParamsConst(true);

  VectorPdfFactory* altModel = new VectorPdfFactory(z1mass_rrv,z2mass_rrv,costhetastar_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,phistar1_rrv,mzz_rrv);
  altModel->makePseudoZprime();
  altModel->makeParamsConst(true);

  checkZorder(z1mass,z2mass,costhetastar,costheta1,costheta2,phi,phistar1);
  
  z1mass_rrv->setVal(z1mass);
  z2mass_rrv->setVal(z2mass);
  costhetastar_rrv->setVal(costhetastar);
  costheta1_rrv->setVal(costheta1);
  costheta2_rrv->setVal(costheta2);
  phi_rrv->setVal(phi);
  phistar1_rrv->setVal(phistar1);
  
  mzz_rrv->setVal(zzmass);
  
  //double result = 1/(1+altModel->getVal(zzmass)/(1e-3*model->getVal(zzmass)));
  double result = 1/(1+altModel->getVal(zzmass)/(model->getVal(zzmass)));
  
  delete z1mass_rrv;
  delete z2mass_rrv;
  delete costheta1_rrv;
  delete costheta2_rrv;
  delete phi_rrv;
  delete costhetastar_rrv;
  delete phistar1_rrv;
  delete mzz_rrv;

  delete model;
  delete altModel;

  return result;

}

double ZerohPlusMELAcalculator(double zzmass, double z1mass, 
			      double z2mass, double costhetastar, 
			      double costheta1, double costheta2, 
			      double phi, double phistar1){
  
  RooRealVar* z1mass_rrv	= new RooRealVar("z1mass","m_{Z1}",0,180);
  RooRealVar* z2mass_rrv	= new RooRealVar("z2mass","m_{Z2}",0,120);
  RooRealVar* costheta1_rrv	= new RooRealVar("costheta1","cos#theta_{1}",-1,1);
  RooRealVar* costheta2_rrv	= new RooRealVar("costheta2","cos#theta_{2}",-1,1);
  RooRealVar* phi_rrv		= new RooRealVar("phi","#Phi",-3.1415,3.1415);
  RooRealVar* costhetastar_rrv	= new RooRealVar("costhetastar","cos#theta^{*}",-1,1);
  RooRealVar* phistar1_rrv	= new RooRealVar("phistar1","#Phi^{*}_{1}",-3.1415,3.1415);
  RooRealVar* mzz_rrv           = new RooRealVar("mzz","mZZ",80,1000);
  
  ScalarPdfFactory* model = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  model->makeSMHiggs();
  model->makeParamsConst(true);

  ScalarPdfFactory* altModel = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  altModel->makeLGHiggs();
  altModel->makeParamsConst(true);

  checkZorder(z1mass,z2mass,costhetastar,costheta1,costheta2,phi,phistar1);
  
  z1mass_rrv->setVal(z1mass);
  z2mass_rrv->setVal(z2mass);
  costhetastar_rrv->setVal(costhetastar);
  costheta1_rrv->setVal(costheta1);
  costheta2_rrv->setVal(costheta2);
  phi_rrv->setVal(phi);
  phistar1_rrv->setVal(phistar1);
  
  mzz_rrv->setVal(zzmass);
  
  //double result = 1/(1+altModel->getVal(zzmass)/(1e-3*model->getVal(zzmass)));
  double result = 1/(1+altModel->getVal(zzmass)/(model->getVal(zzmass)));
  
  delete z1mass_rrv;
  delete z2mass_rrv;
  delete costheta1_rrv;
  delete costheta2_rrv;
  delete phi_rrv;
  delete costhetastar_rrv;
  delete phistar1_rrv;
  delete mzz_rrv;

  delete model;
  delete altModel;

  return result;

}

double TwohPlusMELAcalculator(double zzmass, double z1mass, 
			      double z2mass, double costhetastar, 
			      double costheta1, double costheta2, 
			      double phi, double phistar1){
  
  RooRealVar* z1mass_rrv	= new RooRealVar("z1mass","m_{Z1}",0,180);
  RooRealVar* z2mass_rrv	= new RooRealVar("z2mass","m_{Z2}",0,120);
  RooRealVar* costheta1_rrv	= new RooRealVar("costheta1","cos#theta_{1}",-1,1);
  RooRealVar* costheta2_rrv	= new RooRealVar("costheta2","cos#theta_{2}",-1,1);
  RooRealVar* phi_rrv		= new RooRealVar("phi","#Phi",-3.1415,3.1415);
  RooRealVar* costhetastar_rrv	= new RooRealVar("costhetastar","cos#theta^{*}",-1,1);
  RooRealVar* phistar1_rrv	= new RooRealVar("phistar1","#Phi^{*}_{1}",-3.1415,3.1415);
  RooRealVar* mzz_rrv           = new RooRealVar("mzz","mZZ",80,1000);
  
  ScalarPdfFactory* model = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  model->makeSMHiggs();
  model->makeParamsConst(true);

  TensorPdfFactory* altModel = new TensorPdfFactory(z1mass_rrv,z2mass_rrv,costhetastar_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,phistar1_rrv,mzz_rrv);
  altModel->make2hPlus();
  altModel->makeParamsConst(true);

  checkZorder(z1mass,z2mass,costhetastar,costheta1,costheta2,phi,phistar1);
  
  z1mass_rrv->setVal(z1mass);
  z2mass_rrv->setVal(z2mass);
  costhetastar_rrv->setVal(costhetastar);
  costheta1_rrv->setVal(costheta1);
  costheta2_rrv->setVal(costheta2);
  phi_rrv->setVal(phi);
  phistar1_rrv->setVal(phistar1);
  
  mzz_rrv->setVal(zzmass);
  
  //double result = 1/(1+altModel->getVal(zzmass)/(1e-3*model->getVal(zzmass)));
  double result = 1/(1+altModel->getVal(zzmass)/(model->getVal(zzmass)));
  
  delete z1mass_rrv;
  delete z2mass_rrv;
  delete costheta1_rrv;
  delete costheta2_rrv;
  delete phi_rrv;
  delete costhetastar_rrv;
  delete phistar1_rrv;
  delete mzz_rrv;

  delete model;
  delete altModel;

  return result;

}

double TwohMinusMELAcalculator(double zzmass, double z1mass, 
			      double z2mass, double costhetastar, 
			      double costheta1, double costheta2, 
			      double phi, double phistar1){
  
  RooRealVar* z1mass_rrv	= new RooRealVar("z1mass","m_{Z1}",0,180);
  RooRealVar* z2mass_rrv	= new RooRealVar("z2mass","m_{Z2}",0,120);
  RooRealVar* costheta1_rrv	= new RooRealVar("costheta1","cos#theta_{1}",-1,1);
  RooRealVar* costheta2_rrv	= new RooRealVar("costheta2","cos#theta_{2}",-1,1);
  RooRealVar* phi_rrv		= new RooRealVar("phi","#Phi",-3.1415,3.1415);
  RooRealVar* costhetastar_rrv	= new RooRealVar("costhetastar","cos#theta^{*}",-1,1);
  RooRealVar* phistar1_rrv	= new RooRealVar("phistar1","#Phi^{*}_{1}",-3.1415,3.1415);
  RooRealVar* mzz_rrv           = new RooRealVar("mzz","mZZ",80,1000);
  
  ScalarPdfFactory* model = new ScalarPdfFactory(z1mass_rrv,z2mass_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,mzz_rrv);
  model->makeSMHiggs();
  model->makeParamsConst(true);

  TensorPdfFactory* altModel = new TensorPdfFactory(z1mass_rrv,z2mass_rrv,costhetastar_rrv,costheta1_rrv,costheta2_rrv,phi_rrv,phistar1_rrv,mzz_rrv);
  altModel->make2hMinus();
  altModel->makeParamsConst(true);

  checkZorder(z1mass,z2mass,costhetastar,costheta1,costheta2,phi,phistar1);
  
  z1mass_rrv->setVal(z1mass);
  z2mass_rrv->setVal(z2mass);
  costhetastar_rrv->setVal(costhetastar);
  costheta1_rrv->setVal(costheta1);
  costheta2_rrv->setVal(costheta2);
  phi_rrv->setVal(phi);
  phistar1_rrv->setVal(phistar1);
  
  mzz_rrv->setVal(zzmass);
  
  //double result = 1/(1+altModel->getVal(zzmass)/(1e-3*model->getVal(zzmass)));
  double result = 1/(1+altModel->getVal(zzmass)/(model->getVal(zzmass)));
  
  delete z1mass_rrv;
  delete z2mass_rrv;
  delete costheta1_rrv;
  delete costheta2_rrv;
  delete phi_rrv;
  delete costhetastar_rrv;
  delete phistar1_rrv;
  delete mzz_rrv;

  delete model;
  delete altModel;

  return result;

}

//=======================================================================

void addDtoTree(char* inputFile){

  RooMsgService::instance().getStream(1).removeTopic(NumIntegration);

  //  pseudoMELA pseudoMELAcalculator;
  //  graviMELA graviMELAcalculator;
  //  vectorMELA vectorMELAcalculator;
  //  psVectorMELA psVectorMELAcalculator;

  char inputFileName[100];
  char outputFileName[150];
  sprintf(inputFileName,"%s.root",inputFile);
  sprintf(outputFileName,"%s_withDiscriminants.root",inputFile);

  TFile* sigFile = new TFile(inputFileName);
  TTree* sigTree=0;
    if(sigFile)
        sigTree = (TTree*) sigFile->Get("angles");
    if(!sigTree){
      cout<<"ERROR could not find the tree!"<<endl;
      return;
    }

  TFile* newFile = new TFile(outputFileName,"RECREATE");
  TTree* newTree = new TTree("newTree","angles"); 

  double m1,m2,mzz,h1,h2,hs,phi,phi1,D,psD,grD,vcD,psvcD,ZerohPlusD,TwohMinusD,TwohPlusD;
  double l1p_pt,l1m_pt,l2p_pt,l2m_pt,l1p_eta,l1m_eta,l2p_eta,l2m_eta;

  sigTree->SetBranchAddress("z1mass",&m1);
  sigTree->SetBranchAddress("z2mass",&m2);
  sigTree->SetBranchAddress("zzmass",&mzz);
  sigTree->SetBranchAddress("costheta1",&h1); 
  sigTree->SetBranchAddress("costheta2",&h2);
  sigTree->SetBranchAddress("costhetastar",&hs);
  sigTree->SetBranchAddress("phi",&phi);  
  sigTree->SetBranchAddress("phistar1",&phi1);
  sigTree->SetBranchAddress("l1p_pT",&l1p_pt);  
  sigTree->SetBranchAddress("l1m_pT",&l1m_pt);  
  sigTree->SetBranchAddress("l2p_pT",&l2p_pt);  
  sigTree->SetBranchAddress("l2m_pT",&l2m_pt);  
  sigTree->SetBranchAddress("l1p_eta",&l1p_eta);  
  sigTree->SetBranchAddress("l1m_eta",&l1m_eta);  
  sigTree->SetBranchAddress("l2p_eta",&l2p_eta);  
  sigTree->SetBranchAddress("l2m_eta",&l2m_eta);  

  
  newTree->Branch("z1mass",&m1,"z1mass/D");
  newTree->Branch("z2mass",&m2,"z2mass/D");
  newTree->Branch("zzmass",&mzz,"zzmass/D");
  newTree->Branch("costheta1",&h1,"costheta1/D"); 
  newTree->Branch("costheta2",&h2,"costheta2/D");
  newTree->Branch("costhetastar",&hs,"costhetastar/D");
  newTree->Branch("phi",&phi,"phi/D");  
  newTree->Branch("phistar1",&phi1,"phistar1/D");
  newTree->Branch("l1p_pT",&l1p_pt,"l1p_pT/D");  
  newTree->Branch("l1m_pT",&l1m_pt,"l1m_pT/D");
  newTree->Branch("l2p_pT",&l2p_pt,"l2p_pT/D");  
  newTree->Branch("l2m_pT",&l2m_pt,"l2m_pT/D");  
  newTree->Branch("l1p_eta",&l1p_eta,"l1p_eta/D");  
  newTree->Branch("l1m_eta",&l1m_eta,"l1m_eta/D");
  newTree->Branch("l2p_eta",&l2p_eta,"l2p_eta/D");  
  newTree->Branch("l2m_eta",&l2m_eta,"l2m_eta/D");  
  newTree->Branch("melaLD",&D,"melaLD/D");  
  newTree->Branch("pseudomelaLD",&psD,"pseudomelaLD/D");  
  newTree->Branch("gravimelaLD",&grD,"gravimelaLD/D");  
  newTree->Branch("vectormelaLD",&vcD,"vectormelaLD/D");  
  newTree->Branch("psVectormelaLD",&psvcD,"psVectormelaLD/D");    
  newTree->Branch("2hPlusmelaLD",&TwohPlusD,"2hPlusmelaLD/D");  
  newTree->Branch("2hMinusmelaLD",&TwohMinusD,"2hMinusmelaLD/D");  
  newTree->Branch("0hPlusmelaLD",&ZerohPlusD,"0hPlusmelaLD/D");  
  
  vector<double> pT;

  for(int iEvt=0; iEvt<sigTree->GetEntries(); iEvt++){

    if(iEvt%10000==0) 
      cout << "event: " << iEvt << endl;

    sigTree->GetEntry(iEvt);

    //cout << "costheta1: " << h1 << " costheta2: " << h2 << endl;

    checkZorder<double>(m1,m2,hs,h1,h2,phi,phi1);

    //cout << "costheta1: " << h1 << " costheta2: " << h2 << endl;

    pT.push_back(l1p_pt);
    pT.push_back(l1m_pt);
    pT.push_back(l2p_pt);
    pT.push_back(l2m_pt);

    sort(pT.begin(),pT.end());

    //cout << pT[0] << " " << pT[1] << " " << pT[2] << " " << pT[3] << endl;

    if(mzz>100. && mzz<180. 
       /*
       && m2>12. && m1>50 && m2<120 && m1<120 
       && pT[3]>20. && pT[2]>10. && pT[1]>7. && pT[0]>7. 
       && fabs(l1m_eta)<2.4 && fabs(l2m_eta)<2.4 
       && fabs(l1p_eta)<2.4 && fabs(l2p_eta)<2.4 
       */
       ){

      //cout << "pass" << endl;
      
      //MELA LD
      pair<double,double> P = likelihoodDiscriminant(mzz, m1, m2, hs, h1, h2, phi, phi1);
      D = P.first/(P.first+P.second);
      //cout << "============" << endl;
      //cout << "Psig: " << P.first << endl;
      //cout << "Pbkg: " << P.second << endl;
      //cout << "D: " << D << endl;
      psD = pseudoMELAcalculator(mzz,m1,m2,hs,h1,h2,phi,phi1);
      //cout << "psD: " << psD << endl;
      psvcD = psVectorMELAcalculator(mzz,m1,m2,hs,h1,h2,phi,phi1);
      //cout << "psvcD: " << psvcD << endl;
      vcD = vectorMELAcalculator(mzz,m1,m2,hs,h1,h2,phi,phi1);
      //cout << "vcD: " << vcD << endl;
      grD = graviMELAcalculator(mzz,m1,m2,hs,h1,h2,phi,phi1);
      //cout << "grD: " << grD << endl;
      TwohPlusD = TwohPlusMELAcalculator(mzz,m1,m2,hs,h1,h2,phi,phi1);
      //cout << "2hPlusD: " << TwohPlusD << endl;
      TwohMinusD = TwohMinusMELAcalculator(mzz,m1,m2,hs,h1,h2,phi,phi1);
      //cout << "2hMinusD: " << TwohMinusD << endl;
      ZerohPlusD = ZerohPlusMELAcalculator(mzz,m1,m2,hs,h1,h2,phi,phi1);
      //cout << "0hPlusD: " << ZerohPlusD << endl;
      newTree->Fill();
      
    }

    pT.clear();

   }

  newFile->cd();
  newTree->Write("angles"); 
  newFile->Close();

}

//=======================================================================

void calculateAngles(TLorentzVector thep4H, TLorentzVector thep4Z1, TLorentzVector thep4Lep11, TLorentzVector thep4Lep12, TLorentzVector thep4Z2, TLorentzVector thep4Lep21, TLorentzVector thep4Lep22, double& costheta1, double& costheta2, double& phi, double& costhetastar, double& phistar1, double& phistar2, double& phistar12, double& phi1, double& phi2){
	
	
	//std::cout << "In calculate angles..." << std::endl;
	
	double norm;
	
	TVector3 boostX = -(thep4H.BoostVector());
	TLorentzVector thep4Z1inXFrame( thep4Z1 );
	TLorentzVector thep4Z2inXFrame( thep4Z2 );	
	thep4Z1inXFrame.Boost( boostX );
	thep4Z2inXFrame.Boost( boostX );
	TVector3 theZ1X_p3 = TVector3( thep4Z1inXFrame.X(), thep4Z1inXFrame.Y(), thep4Z1inXFrame.Z() );
	TVector3 theZ2X_p3 = TVector3( thep4Z2inXFrame.X(), thep4Z2inXFrame.Y(), thep4Z2inXFrame.Z() );
	
	// calculate phi1, phi2, costhetastar
	phi1 = theZ1X_p3.Phi();
	phi2 = theZ2X_p3.Phi();
	
	///////////////////////////////////////////////
	// check for z1/z2 convention, redefine all 4 vectors with convention
	///////////////////////////////////////////////	
	TLorentzVector p4H, p4Z1, p4M11, p4M12, p4Z2, p4M21, p4M22;

	/* old convention of choosing Z1 ------------------------------
	p4H = thep4H;
	if ((phi1 < 0)&&(phi1 >= -TMath::Pi())){
		p4Z1 = thep4Z2; p4M11 = thep4Lep21; p4M12 = thep4Lep22;
		p4Z2 = thep4Z1; p4M21 = thep4Lep11; p4M22 = thep4Lep12;		
		costhetastar = theZ2X_p3.CosTheta();
	}
	else{
		p4Z1 = thep4Z1; p4M11 = thep4Lep11; p4M12 = thep4Lep12;
		p4Z2 = thep4Z2; p4M21 = thep4Lep21; p4M22 = thep4Lep22;
		costhetastar = theZ1X_p3.CosTheta();
	} ---------------------------------------------- */

	p4Z1 = thep4Z1; p4M11 = thep4Lep11; p4M12 = thep4Lep12;
	p4Z2 = thep4Z2; p4M21 = thep4Lep21; p4M22 = thep4Lep22;
	costhetastar = theZ1X_p3.CosTheta();
	
	//std::cout << "phi1: " << phi1 << ", phi2: " << phi2 << std::endl;
	
	// now helicity angles................................
	// ...................................................
	TVector3 boostZ1 = -(p4Z1.BoostVector());
	TLorentzVector p4Z2Z1(p4Z2);
	p4Z2Z1.Boost(boostZ1);
	//find the decay axis
	/////TVector3 unitx_1 = -Hep3Vector(p4Z2Z1);
	TVector3 unitx_1( -p4Z2Z1.X(), -p4Z2Z1.Y(), -p4Z2Z1.Z() );
	norm = 1/(unitx_1.Mag());
	unitx_1*=norm;
	//boost daughters of z2
	TLorentzVector p4M21Z1(p4M21);
	TLorentzVector p4M22Z1(p4M22);
	p4M21Z1.Boost(boostZ1);
	p4M22Z1.Boost(boostZ1);
	//create z and y axes
	/////TVector3 unitz_1 = Hep3Vector(p4M21Z1).cross(Hep3Vector(p4M22Z1));
	TVector3 p4M21Z1_p3( p4M21Z1.X(), p4M21Z1.Y(), p4M21Z1.Z() );
	TVector3 p4M22Z1_p3( p4M22Z1.X(), p4M22Z1.Y(), p4M22Z1.Z() );
	TVector3 unitz_1 = p4M21Z1_p3.Cross( p4M22Z1_p3 );
	norm = 1/(unitz_1.Mag());
	unitz_1 *= norm;
	TVector3 unity_1 = unitz_1.Cross(unitx_1);
	
	//caculate theta1
	TLorentzVector p4M11Z1(p4M11);
	p4M11Z1.Boost(boostZ1);
	TVector3 p3M11( p4M11Z1.X(), p4M11Z1.Y(), p4M11Z1.Z() );
	TVector3 unitM11 = p3M11.Unit();
	double x_m11 = unitM11.Dot(unitx_1); double y_m11 = unitM11.Dot(unity_1); double z_m11 = unitM11.Dot(unitz_1);
	TVector3 M11_Z1frame(y_m11, z_m11, x_m11);
	costheta1 = M11_Z1frame.CosTheta();
	//std::cout << "theta1: " << M11_Z1frame.Theta() << std::endl;
	//////-----------------------old way of calculating phi---------------/////////
	phi = M11_Z1frame.Phi();
	
	//set axes for other system
	TVector3 boostZ2 = -(p4Z2.BoostVector());
	TLorentzVector p4Z1Z2(p4Z1);
	p4Z1Z2.Boost(boostZ2);
	TVector3 unitx_2( -p4Z1Z2.X(), -p4Z1Z2.Y(), -p4Z1Z2.Z() );
	norm = 1/(unitx_2.Mag());
	unitx_2*=norm;
	//boost daughters of z2
	TLorentzVector p4M11Z2(p4M11);
	TLorentzVector p4M12Z2(p4M12);
	p4M11Z2.Boost(boostZ2);
	p4M12Z2.Boost(boostZ2);
	TVector3 p4M11Z2_p3( p4M11Z2.X(), p4M11Z2.Y(), p4M11Z2.Z() );
	TVector3 p4M12Z2_p3( p4M12Z2.X(), p4M12Z2.Y(), p4M12Z2.Z() );
	TVector3 unitz_2 = p4M11Z2_p3.Cross( p4M12Z2_p3 );
	norm = 1/(unitz_2.Mag());
	unitz_2*=norm;
	TVector3 unity_2 = unitz_2.Cross(unitx_2);
	//calcuate theta2
	TLorentzVector p4M21Z2(p4M21);
	p4M21Z2.Boost(boostZ2);
	TVector3 p3M21( p4M21Z2.X(), p4M21Z2.Y(), p4M21Z2.Z() );
	TVector3 unitM21 = p3M21.Unit();
	double x_m21 = unitM21.Dot(unitx_2); double y_m21 = unitM21.Dot(unity_2); double z_m21 = unitM21.Dot(unitz_2);
	TVector3 M21_Z2frame(y_m21, z_m21, x_m21);
	costheta2 = M21_Z2frame.CosTheta();
	
	// calculate phi
	//calculating phi_n
	TLorentzVector n_p4Z1inXFrame( p4Z1 );
	TLorentzVector n_p4M11inXFrame( p4M11 );
	n_p4Z1inXFrame.Boost( boostX );
	n_p4M11inXFrame.Boost( boostX );        
	TVector3 n_p4Z1inXFrame_unit = n_p4Z1inXFrame.Vect().Unit();
	TVector3 n_p4M11inXFrame_unit = n_p4M11inXFrame.Vect().Unit();  
	TVector3 n_unitz_1( n_p4Z1inXFrame_unit );
	//// y-axis is defined by neg lepton cross z-axis
	//// the subtle part is here...
	//////////TVector3 n_unity_1 = n_p4M11inXFrame_unit.Cross( n_unitz_1 );
	TVector3 n_unity_1 = n_unitz_1.Cross( n_p4M11inXFrame_unit );
	TVector3 n_unitx_1 = n_unity_1.Cross( n_unitz_1 );
	
	TLorentzVector n_p4M21inXFrame( p4M21 );
	n_p4M21inXFrame.Boost( boostX );
	TVector3 n_p4M21inXFrame_unit = n_p4M21inXFrame.Vect().Unit();
	//rotate into other plane
	TVector3 n_p4M21inXFrame_unitprime( n_p4M21inXFrame_unit.Dot(n_unitx_1), n_p4M21inXFrame_unit.Dot(n_unity_1), n_p4M21inXFrame_unit.Dot(n_unitz_1) );
	
	///////-----------------new way of calculating phi-----------------///////
	//double phi_n =  n_p4M21inXFrame_unitprime.Phi();
	/// and then calculate phistar1
	TVector3 n_p4PartoninXFrame_unit( 0.0, 0.0, 1.0 );
	TVector3 n_p4PartoninXFrame_unitprime( n_p4PartoninXFrame_unit.Dot(n_unitx_1), n_p4PartoninXFrame_unit.Dot(n_unity_1), n_p4PartoninXFrame_unit.Dot(n_unitz_1) );
	// negative sign is for arrow convention in paper
	phistar1 = (n_p4PartoninXFrame_unitprime.Phi());
	
	// and the calculate phistar2
	TLorentzVector n_p4Z2inXFrame( p4Z2 );
	n_p4Z2inXFrame.Boost( boostX );
	TVector3 n_p4Z2inXFrame_unit = n_p4Z2inXFrame.Vect().Unit();
	///////TLorentzVector n_p4M21inXFrame( p4M21 );
	//////n_p4M21inXFrame.Boost( boostX );        
	////TVector3 n_p4M21inXFrame_unit = n_p4M21inXFrame.Vect().Unit();  
	TVector3 n_unitz_2( n_p4Z2inXFrame_unit );
	//// y-axis is defined by neg lepton cross z-axis
	//// the subtle part is here...
	//////TVector3 n_unity_2 = n_p4M21inXFrame_unit.Cross( n_unitz_2 );
	TVector3 n_unity_2 = n_unitz_2.Cross( n_p4M21inXFrame_unit );
	TVector3 n_unitx_2 = n_unity_2.Cross( n_unitz_2 );
	TVector3 n_p4PartoninZ2PlaneFrame_unitprime( n_p4PartoninXFrame_unit.Dot(n_unitx_2), n_p4PartoninXFrame_unit.Dot(n_unity_2), n_p4PartoninXFrame_unit.Dot(n_unitz_2) );
	phistar2 = (n_p4PartoninZ2PlaneFrame_unitprime.Phi());
	
	double phistar12_0 = phistar1 + phistar2;
	if (phistar12_0 > TMath::Pi()) phistar12 = phistar12_0 - 2*TMath::Pi();
	else if (phistar12_0 < (-1.)*TMath::Pi()) phistar12 = phistar12_0 + 2*TMath::Pi();
	else phistar12 = phistar12_0;
	
}
