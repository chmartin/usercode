#ifndef SCALAR_PDF_FACTORY
#define SCALAR_PDF_FACTORY

#include "RooSpinZero_7DComplex_withAccep.h"
//#include "AngularPdfFactory.cc"
#include "TF1.h"
#include "TMath.h"

class ScalarPdfFactory{

public:

  RooSpinZero_7DComplex_withAccep::measurables _measurables;
  RooSpinZero_7DComplex_withAccep::modelParameters _modelParams;
  RooSpinZero_7DComplex_withAccep::accepParameters _accepParams;
    
  RooSpinZero_7DComplex_withAccep* PDF;

  ScalarPdfFactory(){};
    
  ScalarPdfFactory(RooRealVar* m1,RooRealVar* m2,RooRealVar* hs,RooRealVar* h1,RooRealVar* h2,RooRealVar* Phi,RooRealVar* Phi1,RooRealVar* mZZ, int para) {

    _measurables.m1   = m1;
    _measurables.m2   = m2;
    _measurables.h1   = h1;
    _measurables.h2   = h2;
    _measurables.hs   = hs;
    _measurables.Phi  = Phi;
    _measurables.Phi1 = Phi1;
    _modelParams.mX   = mZZ;
    
    // model parameters
    _modelParams.mZ = new RooRealVar("mZ","mZ",91.188);
    _modelParams.gamZ= new RooRealVar("gamZ","gamZ",2.5);

    _modelParams.a1Val = new RooRealVar("a1Val","a1Val",0.);
    _modelParams.phi1Val = new RooRealVar("phi1Val","phi1Val",0.);
    _modelParams.a2Val = new RooRealVar("a2Val","a2Val",0.);
    _modelParams.phi2Val = new RooRealVar("phi2Val","phi2Val",0.);
    _modelParams.a3Val = new RooRealVar("a3Val","a3Val",0.);
    _modelParams.phi3Val = new RooRealVar("phi3Val","phi3Val",0.);
           
    _modelParams.parameterization = para;
    
    _modelParams.g1Val = new RooRealVar("g1Val","g1Val",1.);
    _modelParams.g2Val = new RooRealVar("g2Val","g2Val",0.);
    _modelParams.g3Val = new RooRealVar("g3Val","g3Val",0.);
    _modelParams.g4Val = new RooRealVar("g4Val","g4Val",0.);

    _modelParams.g1ValIm = new RooRealVar("g1ValIm","g1ValIm",0.);
    _modelParams.g2ValIm = new RooRealVar("g2ValIm","g2ValIm",0.);
    _modelParams.g3ValIm = new RooRealVar("g3ValIm","g3ValIm",0.);
    _modelParams.g4ValIm = new RooRealVar("g4ValIm","g4ValIm",0.);

    _modelParams.fa2 = new RooRealVar("fa2","f_{g2}",0.,0.,1.0);
    _modelParams.fa3 = new RooRealVar("fa3","f_{g4}",0.,0.,1.0);
    _modelParams.phia2 = new RooRealVar("phia2","#phi_{g2}",0.,-2.*TMath::Pi(),2*TMath::Pi());
    _modelParams.phia3 = new RooRealVar("phia3","#phi_{g4}",0.,-2.*TMath::Pi(),2*TMath::Pi());
    _modelParams.R1Val = new RooRealVar("R1Val","R1Val",0.15);
    _modelParams.R2Val = new RooRealVar("R2Val","R2Val",0.15);

   1  bH1          2.64540e-02   1.64519e-02   3.58402e-04   2.64540e-02
   2  bH2         -3.73167e-01   1.20492e-02   2.62500e-04  -3.73167e-01
   3  bHs         -1.55528e-01   1.31512e-02   2.88520e-04  -1.55528e-01
   4  bPhi         4.88199e-03   6.26353e-03   1.37408e-04   4.88199e-03
   5  bPhi1       -1.27958e-02   6.08110e-03   1.33408e-04  -1.27958e-02
   6  cPhi         3.69579e-02   6.41775e-03   1.40728e-04   3.69579e-02
   7  cPhi1       -1.64892e-01   6.35915e-03   1.36425e-04  -1.64892e-01


    // acceptance parameters
     _accepParams.aPhi = new RooRealVar("aPhi","aPhi",1.);
   _accepParams.bPhi = new RooRealVar("bPhi","bPhi",4.88199e-03);
    _accepParams.cPhi = new RooRealVar("cPhi","cPhi",3.69579e-02);
    _accepParams.dPhi = new RooRealVar("dPhi","dPhi",0.);
    _accepParams.ePhi = new RooRealVar("ePhi","ePhi",0.);

    _accepParams.aPhi1 = new RooRealVar("aPhi1","aPhi1",1.); 
    _accepParams.bPhi1 = new RooRealVar("bPhi1","bPhi1",-1.27958e-02);
    _accepParams.cPhi1 = new RooRealVar("cPhi1","cPhi1",-1.64892e-01);
    _accepParams.dPhi1 = new RooRealVar("dPhi1","dPhi1",0.);
    _accepParams.ePhi1 = new RooRealVar("ePhi1","ePhi1",0.);

    _accepParams.aH1 = new RooRealVar("aH1","aH1",1.);
    _accepParams.bH1 = new RooRealVar("bH1","bH1",2.64540e-02);
    _accepParams.cH1 = new RooRealVar("cH1","cH1",0.);
    _accepParams.dH1 = new RooRealVar("dH1","dH1",0.);
    _accepParams.eH1 = new RooRealVar("eH1","eH1",0.);

    _accepParams.aH2 = new RooRealVar("aH2","aH2",1.);
    _accepParams.bH2 = new RooRealVar("bH2","bH2",-3.73167e-01);
    _accepParams.cH2 = new RooRealVar("cH2","cH2",0.);
    _accepParams.dH2 = new RooRealVar("dH2","dH2",0.);
    _accepParams.eH2 = new RooRealVar("eH2","eH2",0.);

    _accepParams.aHs = new RooRealVar("aHs","aHs",1.);
    _accepParams.bHs = new RooRealVar("bHs","bHs",-1.55528e-01);
    _accepParams.cHs = new RooRealVar("cHs","cHs",0.);
    _accepParams.dHs = new RooRealVar("dHs","dHs",0.);
    _accepParams.eHs = new RooRealVar("eHs","eHs",0.);

    PDF = new RooSpinZero_7DComplex_withAccep("PDF","PDF",
					      _measurables,
					      _modelParams,
					      _accepParams);

    //std::cout << "ScalarPdfFactory::ScalarPdfFactory - done " << std::endl;

  };

  ~ScalarPdfFactory(){

    //std::cout << "~ScalarPdfFactory" << std::endl;

    delete PDF;

    delete _modelParams.a1Val;
    delete _modelParams.phi1Val;
    delete _modelParams.a2Val;
    delete _modelParams.phi2Val;
    delete _modelParams.a3Val;
    delete _modelParams.phi3Val;
    delete _modelParams.g1Val;
    delete _modelParams.g2Val;
    delete _modelParams.g3Val;
    delete _modelParams.g4Val;
    delete _modelParams.g1ValIm;
    delete _modelParams.g2ValIm;
    delete _modelParams.g3ValIm;
    delete _modelParams.g4ValIm;			
    delete _modelParams.fa2;
    delete _modelParams.fa3;
    delete _modelParams.phia2;
    delete _modelParams.phia3;

    delete _modelParams.R1Val;
    delete _modelParams.R2Val;

    delete _modelParams.mZ;
    delete _modelParams.gamZ;

    delete _accepParams.aPhi;
    delete _accepParams.bPhi;
    delete _accepParams.cPhi;
    delete _accepParams.dPhi;
    delete _accepParams.ePhi;
    delete _accepParams.aPhi1;
    delete _accepParams.bPhi1;
    delete _accepParams.cPhi1;
    delete _accepParams.dPhi1;
    delete _accepParams.ePhi1;
    delete _accepParams.aH1;
    delete _accepParams.bH1;
    delete _accepParams.cH1;
    delete _accepParams.dH1;
    delete _accepParams.eH1;
    delete _accepParams.aH2;
    delete _accepParams.bH2;
    delete _accepParams.cH2;
    delete _accepParams.dH2;
    delete _accepParams.eH2;
    delete _accepParams.aHs;
    delete _accepParams.bHs;
    delete _accepParams.cHs;
    delete _accepParams.dHs;
    delete _accepParams.eHs;

    //std::cout << "~ScalarPdfFactory - end " << std::endl;

  };

  void makeSMHiggs(){

    //std::cout << "ScalarPdfFactory::makeSMHiggs()" << std::endl;

    _modelParams.parameterization=1;

    _modelParams.g1Val->setVal(1.0);
    _modelParams.g2Val->setVal(0.0);
    _modelParams.g3Val->setVal(0.0);
    _modelParams.g4Val->setVal(0.0);
    
    _modelParams.g1ValIm->setVal(0.0);
    _modelParams.g2ValIm->setVal(0.0);
    _modelParams.g3ValIm->setVal(0.0);
    _modelParams.g4ValIm->setVal(0.0);

  };

  void makeLGHiggs(){          

    //std::cout << "ScalarPdfFactory::makeLGHiggs()" << std::endl;

    _modelParams.parameterization=1;

    _modelParams.g1Val->setVal(0.0);        // need to calculate the proper normalizations
    _modelParams.g2Val->setVal(1.0);
    _modelParams.g3Val->setVal(0.0);
    _modelParams.g4Val->setVal(0.0);
    
    _modelParams.g1ValIm->setVal(0.0);        // need to calculate the proper normalizations
    _modelParams.g2ValIm->setVal(0.0);
    _modelParams.g3ValIm->setVal(0.0);
    _modelParams.g4ValIm->setVal(0.0);

    };


  void makePSHiggs(){

    //std::cout << "ScalarPdfFactory::makePSHiggs()" << std::endl;

    _modelParams.parameterization=1;

    _modelParams.g1Val->setVal(0.0);
    _modelParams.g2Val->setVal(0.0);
    _modelParams.g3Val->setVal(0.0);
    _modelParams.g4Val->setVal(1.0);
    
    _modelParams.g1ValIm->setVal(0.0);
    _modelParams.g2ValIm->setVal(0.0);
    _modelParams.g3ValIm->setVal(0.0);
    _modelParams.g4ValIm->setVal(0.0);
    
    
  };

  void makeCustom(double a1, double a2, double a3,
		  double phi1, double phi2, double phi3){

    //std::cout << "ScalarPdfFactory::makeCustom()" << std::endl;

    _modelParams.parameterization=0;

    _modelParams.a1Val->setVal(a1);
    _modelParams.phi1Val->setVal(phi1);
    _modelParams.a2Val->setVal(a2);
    _modelParams.phi2Val->setVal(phi2);
    _modelParams.a3Val->setVal(a3);
    _modelParams.phi3Val->setVal(phi3);
    
  };

  void makeParamsConst(bool yesNo=true){
   
    //std::cout << "ScalarPdfFactory::makeParamsConst()" << std::endl;

    if(yesNo){
      _modelParams.a1Val->setConstant(kTRUE);
      _modelParams.phi1Val->setConstant(kTRUE);
      _modelParams.a2Val->setConstant(kTRUE);
      _modelParams.phi2Val->setConstant(kTRUE);
      _modelParams.a3Val->setConstant(kTRUE);
      _modelParams.phi3Val->setConstant(kTRUE);
      _modelParams.g1Val->setConstant(kTRUE);
      _modelParams.g2Val->setConstant(kTRUE);
      _modelParams.g3Val->setConstant(kTRUE);
      _modelParams.g4Val->setConstant(kTRUE);
      _modelParams.g1ValIm->setConstant(kTRUE);
      _modelParams.g2ValIm->setConstant(kTRUE);
      _modelParams.g3ValIm->setConstant(kTRUE);
      _modelParams.g4ValIm->setConstant(kTRUE);
      _modelParams.fa2->setConstant(kTRUE);
      _modelParams.fa3->setConstant(kTRUE);
      _modelParams.phia2->setConstant(kTRUE);
      _modelParams.phia3->setConstant(kTRUE);
      _modelParams.gamZ->setConstant(kTRUE);
      _modelParams.mZ->setConstant(kTRUE);
      _modelParams.R1Val->setConstant(kTRUE);
      _modelParams.R2Val->setConstant(kTRUE);

      _accepParams.aPhi->setConstant(kTRUE);
      _accepParams.bPhi->setConstant(kTRUE);
      _accepParams.cPhi->setConstant(kTRUE);
      _accepParams.dPhi->setConstant(kTRUE);
      _accepParams.ePhi->setConstant(kTRUE);

      _accepParams.aPhi1->setConstant(kTRUE);
      _accepParams.bPhi1->setConstant(kTRUE);
      _accepParams.cPhi1->setConstant(kTRUE);
      _accepParams.dPhi1->setConstant(kTRUE);
      _accepParams.ePhi1->setConstant(kTRUE);

      _accepParams.aH1->setConstant(kTRUE);
      _accepParams.bH1->setConstant(kTRUE);
      _accepParams.cH1->setConstant(kTRUE);
      _accepParams.dH1->setConstant(kTRUE);
      _accepParams.eH1->setConstant(kTRUE);

      _accepParams.aH2->setConstant(kTRUE);
      _accepParams.bH2->setConstant(kTRUE);
      _accepParams.cH2->setConstant(kTRUE);
      _accepParams.dH2->setConstant(kTRUE);
      _accepParams.eH2->setConstant(kTRUE);

      _accepParams.aHs->setConstant(kTRUE);
      _accepParams.bHs->setConstant(kTRUE);
      _accepParams.cHs->setConstant(kTRUE);
      _accepParams.dHs->setConstant(kTRUE);
      _accepParams.eHs->setConstant(kTRUE);

    }else{
      _modelParams.a1Val->setConstant(kFALSE);
      _modelParams.phi1Val->setConstant(kFALSE);
      _modelParams.a2Val->setConstant(kFALSE);
      _modelParams.phi2Val->setConstant(kFALSE);
      _modelParams.a3Val->setConstant(kFALSE);
      _modelParams.phi3Val->setConstant(kFALSE);
      _modelParams.g1Val->setConstant(kFALSE);
      _modelParams.g2Val->setConstant(kFALSE);
      _modelParams.g3Val->setConstant(kFALSE);
      _modelParams.g4Val->setConstant(kFALSE);
      _modelParams.g1ValIm->setConstant(kFALSE);
      _modelParams.g2ValIm->setConstant(kFALSE);
      _modelParams.g3ValIm->setConstant(kFALSE);
      _modelParams.g4ValIm->setConstant(kFALSE);
      _modelParams.fa2->setConstant(kFALSE);
      _modelParams.fa3->setConstant(kFALSE);
      _modelParams.phia2->setConstant(kFALSE);
      _modelParams.phia3->setConstant(kFALSE);
      _modelParams.gamZ->setConstant(kFALSE);
      _modelParams.mZ->setConstant(kFALSE);
      _modelParams.R1Val->setConstant(kFALSE);
      _modelParams.R2Val->setConstant(kFALSE);

      _accepParams.aPhi->setConstant(kFALSE);
      _accepParams.bPhi->setConstant(kFALSE);
      _accepParams.cPhi->setConstant(kFALSE);
      _accepParams.dPhi->setConstant(kFALSE);
      _accepParams.ePhi->setConstant(kFALSE);

      _accepParams.aPhi1->setConstant(kFALSE);
      _accepParams.bPhi1->setConstant(kFALSE);
      _accepParams.cPhi1->setConstant(kFALSE);
      _accepParams.dPhi1->setConstant(kFALSE);
      _accepParams.ePhi1->setConstant(kFALSE);

      _accepParams.aH1->setConstant(kFALSE);
      _accepParams.bH1->setConstant(kFALSE);
      _accepParams.cH1->setConstant(kFALSE);
      _accepParams.dH1->setConstant(kFALSE);
      _accepParams.eH1->setConstant(kFALSE);

      _accepParams.aH2->setConstant(kFALSE);
      _accepParams.bH2->setConstant(kFALSE);
      _accepParams.cH2->setConstant(kFALSE);
      _accepParams.dH2->setConstant(kFALSE);
      _accepParams.eH2->setConstant(kFALSE);

      _accepParams.aHs->setConstant(kFALSE);
      _accepParams.bHs->setConstant(kFALSE);
      _accepParams.cHs->setConstant(kFALSE);
      _accepParams.dHs->setConstant(kFALSE);
      _accepParams.eHs->setConstant(kFALSE);

    }
  };

};




#endif



