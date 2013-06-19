/*****************************************************************************
* Project: RooFit                                                           *
*                                                                           *
* This code was autogenerated by RooClassFactory                            *
*****************************************************************************/

// Your description goes here...

#include "Riostream.h"

#include "RooSpinZero_7DComplex_withAccep.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include <math.h>
#include "TMath.h"

using namespace TMath;

enum parameterizationList {kMagPhase_As=0,kRealImag_Gs=1,kFracPhase_Gs=2,kNUMparameterizations=3};

RooSpinZero_7DComplex_withAccep::RooSpinZero_7DComplex_withAccep(const char *name, const char *title,
measurables _measurables,
modelParameters _modelParams,
accepParameters _accepParams) :
RooAbsPdf(name,title),
m1("m1","m1",this,*_measurables.m1),
m2("m2","m2",this,*_measurables.m2),
h1("h1","h1",this,*_measurables.h1),
h2("h2","h2",this,*_measurables.h2),
hs("hs","hs",this,*_measurables.hs),
Phi("Phi","Phi",this,*_measurables.Phi),
Phi1("Phi1","Phi1",this,*_measurables.Phi1),
a1Val("a1Val","a1Val",this,*_modelParams.a1Val),
phi1Val("phi1Val","phi1Val",this,*_modelParams.phi1Val),
a2Val("a2Val","a2Val",this,*_modelParams.a2Val),
phi2Val("phi2Val","phi2Val",this,*_modelParams.phi2Val),
a3Val("a3Val","a3Val",this,*_modelParams.a3Val),
phi3Val("phi3Val","phi3Val",this,*_modelParams.phi3Val),
parameterization(_modelParams.parameterization),
g1Val("g1Val","g1Val",this,*_modelParams.g1Val),
g2Val("g2Val","g2Val",this,*_modelParams.g2Val),
g3Val("g3Val","g3Val",this,*_modelParams.g3Val),
g4Val("g4Val","g4Val",this,*_modelParams.g4Val),
g1ValIm("g1ValIm","g1ValIm",this,*_modelParams.g1ValIm),
g2ValIm("g2ValIm","g2ValIm",this,*_modelParams.g2ValIm),
g3ValIm("g3ValIm","g3ValIm",this,*_modelParams.g3ValIm),
g4ValIm("g4ValIm","g4ValIm",this,*_modelParams.g4ValIm),

fa2("fa2","fa2",this,*_modelParams.fa2),
fa3("fa3","fa3",this,*_modelParams.fa3),
phia2("phia2","phia2",this,*_modelParams.phia2),
phia3("phia3","phia3",this,*_modelParams.phia3),

mZ("mZ","mZ",this,*_modelParams.mZ),
gamZ("gamZ","gamZ",this,*_modelParams.gamZ),
mX("mX","mX",this,*_modelParams.mX),
R1Val("R1Val","R1Val",this,*_modelParams.R1Val),
R2Val("R2Val","R2Val",this,*_modelParams.R2Val),
// acceptance parameters
aPhi("aPhi","aPhi",this,*_accepParams.aPhi),
bPhi("bPhi","bPhi",this,*_accepParams.bPhi),
cPhi("cPhi","cPhi",this,*_accepParams.cPhi),
dPhi("dPhi","dPhi",this,*_accepParams.dPhi),
ePhi("ePhi","ePhi",this,*_accepParams.ePhi),
aPhi1("aPhi1","aPhi1",this,*_accepParams.aPhi1),
bPhi1("bPhi1","bPhi1",this,*_accepParams.bPhi1),
cPhi1("cPhi1","cPhi1",this,*_accepParams.cPhi1),
dPhi1("dPhi1","dPhi1",this,*_accepParams.dPhi1),
ePhi1("ePhi1","ePhi1",this,*_accepParams.ePhi1),
aH1("aH1","aH1",this,*_accepParams.aH1),
bH1("bH1","bH1",this,*_accepParams.bH1),
cH1("cH1","cH1",this,*_accepParams.cH1),
dH1("dH1","dH1",this,*_accepParams.dH1),
eH1("eH1","eH1",this,*_accepParams.eH1),
aH2("aH2","aH2",this,*_accepParams.aH2),
bH2("bH2","bH2",this,*_accepParams.bH2),
cH2("cH2","cH2",this,*_accepParams.cH2),
dH2("dH2","dH2",this,*_accepParams.dH2),
eH2("eH2","eH2",this,*_accepParams.eH2),
aHs("aHs","aHs",this,*_accepParams.aHs),
bHs("bHs","bHs",this,*_accepParams.bHs),
cHs("cHs","cHs",this,*_accepParams.cHs),
dHs("dHs","dHs",this,*_accepParams.dHs),
eHs("eHs","eHs",this,*_accepParams.eHs)
{

  //std::cout << "RooSpinZero_7DComplex_withAccep::RooSpinZero_7DComplex_withAccep()" << std::endl;
}


RooSpinZero_7DComplex_withAccep::RooSpinZero_7DComplex_withAccep(const RooSpinZero_7DComplex_withAccep& other, const char* name) :
RooAbsPdf(other,name),
m1("m1",this,other.m1),
m2("m2",this,other.m2),
h1("h1",this,other.h1),
h2("h2",this,other.h2),
hs("hs",this,other.hs),
Phi("Phi",this,other.Phi),
Phi1("Phi1",this,other.Phi1),
a1Val("a1Val",this,other.a1Val),
phi1Val("phi1Val",this,other.phi1Val),
a2Val("a2Val",this,other.a2Val),
phi2Val("phi2Val",this,other.phi2Val),
a3Val("a3Val",this,other.a3Val),
phi3Val("phi3Val",this,other.phi3Val),
parameterization(other.parameterization),
g1Val("g1Val",this,other.g1Val),
g2Val("a2Val",this,other.g2Val),
g3Val("g3Val",this,other.g3Val),
g4Val("g4Val",this,other.g4Val),
g1ValIm("g1ValIm",this,other.g1ValIm),
g2ValIm("a2ValIm",this,other.g2ValIm),
g3ValIm("g3ValIm",this,other.g3ValIm),
g4ValIm("g4ValIm",this,other.g4ValIm),

fa2("fa2",this,other.fa2),
fa3("fa3",this,other.fa3),
phia2("phia2",this,other.phia2),
phia3("phia3",this,other.phia3),

mZ("mZ",this,other.mZ),
gamZ("gamZ",this,other.gamZ),
mX("mX",this,other.mX),
R1Val("R1Val",this,other.R1Val),
R2Val("R2Val",this,other.R2Val),
// acceptance parameters
aPhi("aPhi",this,other.aPhi),
bPhi("bPhi",this,other.bPhi),
cPhi("cPhi",this,other.cPhi),
dPhi("dPhi",this,other.dPhi),
ePhi("ePhi",this,other.ePhi),
aPhi1("aPhi1",this,other.aPhi1),
bPhi1("bPhi1",this,other.bPhi1),
cPhi1("cPhi1",this,other.cPhi1),
dPhi1("dPhi1",this,other.dPhi1),
ePhi1("ePhi1",this,other.ePhi1),
aH1("aH1",this,other.aH1),
bH1("bH1",this,other.bH1),
cH1("cH1",this,other.cH1),
dH1("dH1",this,other.dH1),
eH1("eH1",this,other.eH1),
aH2("aH2",this,other.aH2),
bH2("bH2",this,other.bH2),
cH2("cH2",this,other.cH2),
dH2("dH2",this,other.dH2),
eH2("eH2",this,other.eH2),
aHs("aHs",this,other.aHs),
bHs("bHs",this,other.bHs),
cHs("cHs",this,other.cHs),
dHs("dHs",this,other.dHs),
eHs("eHs",this,other.eHs)
{
}



Double_t RooSpinZero_7DComplex_withAccep::evaluate() const
{


  //std::cout << "RooSpinZero_7DComplex_withAccep::evaluate()" << std::endl;

// ENTER EXPRESSION IN TERMS OF VARIABLE ARGUMENTS HERE
//   const Double_t VEV = 246.;

  //std::cout << "check 0" << std::endl;

Double_t Pi = 3.14159265359;
//std::cout << "check 1" << std::endl;

Double_t sh1 = sqrt(1-h1*h1);
//std::cout << "check 2" << std::endl;

Double_t sh2 = sqrt(1-h2*h2);
//std::cout << "check 3" << std::endl;


bool isZZ = true;
if ( mZ < 90.) isZZ = false;
if ( isZZ ) {
if( (m1+m2) > mX || m2>m1 ) return 1e-9;
} else {
if( (m1+m2) > mX ) return 1e-9;
}
double nanval = sqrt((1 - TMath::Power(m1 - m2,2)/TMath::Power(mX,2))*(1 - TMath::Power(m1 + m2,2)/TMath::Power(mX,2)));
if (nanval != nanval) return 1e-9;

double s=(mX*mX-m1*m1-m2*m2)/2.;
double kappa=s/(1000*1000);

double a1=0,a2=0,a3=0,a1Im=0,a2Im=0,a3Im=0;
double g1(1.0), g1Im(0.), g2(0.), g2Im(0.), g3(0.), g3Im(0.), g4(0.), g4Im(0.);


//std::cout << "check 1" << std::endl;

if(parameterization==kMagPhase_As){
a1=a1Val;
a1Im=phi1Val;
a2=a2Val;
a2Im=phi2Val;
a3=a3Val;
a3Im=phi3Val;
} else {

//
// Important, the PDF has an emphirical fix
// Forcing the couplings to be its conjugate
// to agree with the generator shapes
//
if(parameterization==kFracPhase_Gs){
nanval = sqrt(1 - fa2 - fa3);
if (nanval != nanval) return 1e-9;

// convert fraction and phase to g1,g2...etc
double sigma_1=2.0418442;   // numbers coming from JHUGen
double sigma_2=0.77498928;
double sigma_4=0.32711197;

double g1Mag = 1.;
double g2Mag = sqrt(fa2/(1.-fa2-fa3))*sqrt(sigma_1/sigma_2);
double g4Mag = sqrt(fa3/(1.-fa2-fa3))*sqrt(sigma_1/sigma_4);


//std::cout << "check 2" << std::endl;

g1   = g1Mag;
g1Im = 0.0;
g2   = g2Mag*cos(phia2);
g2Im = - g2Mag*sin(phia2);
g3   = 0.0;
g3Im = 0.0;
g4   = g4Mag*cos(phia3);
g4Im = - g4Mag*sin(phia3);

}else if(parameterization==kRealImag_Gs){

g1   = g1Val;
g1Im = - g1ValIm;
g2   = g2Val;
g2Im = - g2ValIm;
g3   = g3Val;
g3Im = - g3ValIm;
g4   = g4Val;
g4Im = - g4ValIm;
}

a1 = g1*mZ*mZ/(mX*mX) + g2*2.*s/(mX*mX) + g3*kappa*s/(mX*mX);
a1Im = g1Im*mZ*mZ/(mX*mX) + g2Im*2.*s/(mX*mX) + g3Im*kappa*s/(mX*mX);
a2 = -2.*g2 - g3*kappa;
a2Im = -2.*g2Im - g3Im*kappa;
a3 = -2.*g4;
a3Im = -2.*g4Im;

}

// From the form output in terms of the g couplings
// https://dl.dropbox.com/u/86680464/result_spin0.txt
Double_t x = (mX*mX-m1*m1-m2*m2)/(2.0*m1*m2);
Double_t f00Real =
a2 * (  - (x*x-1)*m1*m2 )
+ a1 * ( 1./4.*TMath::Power(m1, -1)*TMath::Power(m2, 3) - 1./2.*m1*m2 + 1./4.*TMath::Power(m1,3)*TMath::Power(m2,-1) - (x*x-1)*m1*m2 )
+ TMath::Power(mX,4)*a1 * (  - 1./4.*TMath::Power(m1,-1)*TMath::Power(m2,-1) );
//    Double_t f00Imag = 0.;
Double_t f00Imag =
a2Im * (  - (x*x-1)*m1*m2 )
+ a1Im * ( 1./4.*TMath::Power(m1, -1)*TMath::Power(m2, 3) - 1./2.*m1*m2 + 1./4.*TMath::Power(m1,3)*TMath::Power(m2,-1) - (x*x-1)*m1*m2 )
+ TMath::Power(mX,4)*a1Im * (  - 1./4.*TMath::Power(m1,-1)*TMath::Power(m2,-1) );

//    Double_t fppReal = TMath::Power(mX, 2)*a1;
//    Double_t fppImag = a3*sqrt(x*x-1)*m1*m2 ;
Double_t fppReal = TMath::Power(mX, 2)*a1 - a3Im*sqrt(x*x-1)*m1*m2;
Double_t fppImag = a3*sqrt(x*x-1)*m1*m2 + TMath::Power(mX, 2)*a1Im;

Double_t fmmReal = TMath::Power(mX, 2)*a1 + a3Im*sqrt(x*x-1)*m1*m2;
Double_t fmmImag = -a3*sqrt(x*x-1)*m1*m2 + TMath::Power(mX, 2)*a1Im;

Double_t f00 = f00Imag*f00Imag + f00Real*f00Real;
Double_t fpp = fppImag*fppImag + fppReal*fppReal;
Double_t fmm = fmmImag*fmmImag + fmmReal*fmmReal;

Double_t phi00=atan2(f00Imag,f00Real);
Double_t phipp=atan2(fppImag,fppReal)-phi00;
Double_t phimm=atan2(fmmImag,fmmReal)-phi00;


Double_t betaValSquared = (1.-(pow(m1-m2,2)/pow(mX,2)))*(1.-(pow(m1+m2,2)/pow(mX,2)));
Double_t betaVal = sqrt(betaValSquared);

Double_t term1Coeff = (pow(m1,3))/( (pow(m1,2)-pow(mZ,2))*(pow(m1,2)-pow(mZ,2))+pow(mZ,2)*pow(gamZ,2) );
Double_t term2Coeff = (pow(m2,3))/( (pow(m2,2)-pow(mZ,2))*(pow(m2,2)-pow(mZ,2))+pow(mZ,2)*pow(gamZ,2) );

// BELOW GOES THE test_Decay.txt OUTPUT FROM Master_yy.nb

double value = 0.;

value+=(f00*(-1 + pow(h1,2))*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) +dH1*pow(h1,6) + eH1*pow(h1,8))*(-1 + pow(h2,2))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) + dH2*pow(h2,6) +eH2*pow(h2,8))*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) +dHs*pow(hs,6) + eHs*pow(hs,8))*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi))*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) +dPhi1*cos(3*Phi1) + ePhi1*cos(4*Phi1)))/4.;
value+=(fmm*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) +dH2*pow(h2,6) + eH2*pow(h2,8))*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) + dHs*pow(hs,6) +eHs*pow(hs,8))*(1 + pow(h1,2) - 2*h1*R1Val)*(1 + pow(h2,2) - 2*h2*R2Val)*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi))*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) +dPhi1*cos(3*Phi1) + ePhi1*cos(4*Phi1)))/16.;
value+=(fpp*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) +dH2*pow(h2,6) + eH2*pow(h2,8))*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) + dHs*pow(hs,6) +eHs*pow(hs,8))*(1 + pow(h1,2) + 2*h1*R1Val)*(1 + pow(h2,2) + 2*h2*R2Val)*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi))*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) +dPhi1*cos(3*Phi1) + ePhi1*cos(4*Phi1)))/16.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(sqrt(f00)*sqrt(fmm)*sqrt(1 - pow(h1,2))*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*sqrt(1 - pow(h2,2))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) + dH2*pow(h2,6) +eH2*pow(h2,8))*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) +dHs*pow(hs,6) + eHs*pow(hs,8))*(h1 - R1Val)*(h2 - R2Val)*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi))*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) +dPhi1*cos(3*Phi1) + ePhi1*cos(4*Phi1))*cos(Phi - phimm))/4.;
value+=(sqrt(f00)*sqrt(fpp)*sqrt(1 - pow(h1,2))*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*sqrt(1 - pow(h2,2))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) + dH2*pow(h2,6) +eH2*pow(h2,8))*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) +dHs*pow(hs,6) + eHs*pow(hs,8))*(h1 + R1Val)*(h2 + R2Val)*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi))*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) +dPhi1*cos(3*Phi1) + ePhi1*cos(4*Phi1))*cos(Phi + phipp))/4.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(sqrt(fmm)*sqrt(fpp)*(-1 + pow(h1,2))*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*(-1 + pow(h2,2))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) + dH2*pow(h2,6) +eH2*pow(h2,8))*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) +dHs*pow(hs,6) + eHs*pow(hs,8))*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi))*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) +dPhi1*cos(3*Phi1) + ePhi1*cos(4*Phi1))*cos(2*Phi - phimm + phipp))/8.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;


return  betaVal*term1Coeff*term2Coeff*value;


}


Int_t RooSpinZero_7DComplex_withAccep::getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* /*rangeName*/) const
{

  //if (matchArgs(allVars,analVars,RooArgSet(*hs.absArg(),*h1.absArg(),*h2.absArg(),*Phi.absArg(),*Phi1.absArg()))) return 6 ; // No m1,m2
  if (matchArgs(allVars,analVars,hs,h1,h2,Phi)) return 2 ; // No Phi1
  if (matchArgs(allVars,analVars,hs,h1,h2,Phi1)) return 5 ; // No Phi
  if (matchArgs(allVars,analVars,hs,h1,Phi,Phi1)) return 3 ; // No h2
  if (matchArgs(allVars,analVars,hs,h2,Phi,Phi1)) return 4 ; // No h1
  if (matchArgs(allVars,analVars,h1,h2,Phi,Phi1)) return 1 ; // No hs

return 0 ;
}
Double_t RooSpinZero_7DComplex_withAccep::analyticalIntegral(Int_t code, const char* rangeName) const
{

bool isZZ = true;
if ( mZ < 90.) isZZ = false;
if ( isZZ ) {
if( (m1+m2) > mX || m2>m1 ) return 1e-9;
} else {
if( (m1+m2) > mX ) return 1e-9;
}
double nanval = sqrt((1 - TMath::Power(m1 - m2,2)/TMath::Power(mX,2))*(1 - TMath::Power(m1 + m2,2)/TMath::Power(mX,2)));
if (nanval != nanval) return 1e-9;

//
//  common variables to use for all cases
//

Double_t Pi = 3.14159265359;

Double_t sh1 = sqrt(1-h1*h1);
Double_t sh2 = sqrt(1-h2*h2);
double s=(mX*mX-m1*m1-m2*m2)/2.;
double kappa=s/(1000*1000);

double a1=0,a2=0,a3=0,a1Im=0,a2Im=0,a3Im=0;

double g1(1.0), g1Im(0.), g2(0.), g2Im(0.), g3(0.), g3Im(0.), g4(0.), g4Im(0.);

if(parameterization==kMagPhase_As){
a1=a1Val;
a1Im=phi1Val;
a2=a2Val;
a2Im=phi2Val;
a3=a3Val;
a3Im=phi3Val;
} else {

//
// Important, the PDF has an emphirical fix
// Forcing the couplings to be its conjugate
// to agree with the generator shapes
//
if(parameterization==kFracPhase_Gs){
nanval = sqrt(1 - fa2 - fa3);
if (nanval != nanval) return 1e-9;

// convert fraction and phase to g1,g2...etc
double sigma_1=2.0418442;   // numbers coming from JHUGen
double sigma_2=0.77498928;
double sigma_4=0.32711197;

double g1Mag = 1.;
double g2Mag = sqrt(fa2/(1.-fa2-fa3))*sqrt(sigma_1/sigma_2);
double g4Mag = sqrt(fa3/(1.-fa2-fa3))*sqrt(sigma_1/sigma_4);

g1   = g1Mag;
g1Im = 0.0;
g2   = g2Mag*cos(phia2);
g2Im = - g2Mag*sin(phia2);
g3   = 0.0;
g3Im = 0.0;
g4   = g4Mag*cos(phia3);
g4Im = - g4Mag*sin(phia3);

}else if(parameterization==kRealImag_Gs){

g1   = g1Val;
g1Im = - g1ValIm;
g2   = g2Val;
g2Im = - g2ValIm;
g3   = g3Val;
g3Im = - g3ValIm;
g4   = g4Val;
g4Im = - g4ValIm;
}

// std::cout << "g4 = " << g4 << "\t " << "i " << g4Im << "\n";
a1 = g1*mZ*mZ/(mX*mX) + g2*2.*s/(mX*mX) + g3*kappa*s/(mX*mX);
a1Im = g1Im*mZ*mZ/(mX*mX) + g2Im*2.*s/(mX*mX) + g3Im*kappa*s/(mX*mX);
a2 = -2.*g2 - g3*kappa;
a2Im = -2.*g2Im - g3Im*kappa;
a3 = -2.*g4;
a3Im = -2.*g4Im;

}

// From the form output in terms of the g couplings
// https://dl.dropbox.com/u/86680464/result_spin0.txt
Double_t x = (mX*mX-m1*m1-m2*m2)/(2.0*m1*m2);
Double_t f00Real =
a2 * (  - (x*x-1)*m1*m2 )
+ a1 * ( 1./4.*TMath::Power(m1, -1)*TMath::Power(m2, 3) - 1./2.*m1*m2 + 1./4.*TMath::Power(m1,3)*TMath::Power(m2,-1) - (x*x-1)*m1*m2 )
+ TMath::Power(mX,4)*a1 * (  - 1./4.*TMath::Power(m1,-1)*TMath::Power(m2,-1) );
//    Double_t f00Imag = 0.;
Double_t f00Imag =
a2Im * (  - (x*x-1)*m1*m2 )
+ a1Im * ( 1./4.*TMath::Power(m1, -1)*TMath::Power(m2, 3) - 1./2.*m1*m2 + 1./4.*TMath::Power(m1,3)*TMath::Power(m2,-1) - (x*x-1)*m1*m2 )
+ TMath::Power(mX,4)*a1Im * (  - 1./4.*TMath::Power(m1,-1)*TMath::Power(m2,-1) );

//    Double_t fppReal = TMath::Power(mX, 2)*a1;
//    Double_t fppImag = a3*sqrt(x*x-1)*m1*m2 ;
Double_t fppReal = TMath::Power(mX, 2)*a1 - a3Im*sqrt(x*x-1)*m1*m2;
Double_t fppImag = a3*sqrt(x*x-1)*m1*m2 + TMath::Power(mX, 2)*a1Im;

Double_t fmmReal = TMath::Power(mX, 2)*a1 + a3Im*sqrt(x*x-1)*m1*m2;
Double_t fmmImag = -a3*sqrt(x*x-1)*m1*m2 + TMath::Power(mX, 2)*a1Im;

Double_t f00 = f00Imag*f00Imag + f00Real*f00Real;
Double_t fpp = fppImag*fppImag + fppReal*fppReal;
Double_t fmm = fmmImag*fmmImag + fmmReal*fmmReal;

Double_t phi00=atan2(f00Imag,f00Real);
Double_t phipp=atan2(fppImag,fppReal)-phi00;
Double_t phimm=atan2(fmmImag,fmmReal)-phi00;

Double_t betaValSquared = (1.-(pow(m1-m2,2)/pow(mX,2)))*(1.-(pow(m1+m2,2)/pow(mX,2)));
Double_t betaVal = sqrt(betaValSquared);

Double_t term1Coeff = (pow(m1,3))/( (pow(m1,2)-pow(mZ,2))*(pow(m1,2)-pow(mZ,2))+pow(mZ,2)*pow(gamZ,2) );
Double_t term2Coeff = (pow(m2,3))/( (pow(m2,2)-pow(mZ,2))*(pow(m2,2)-pow(mZ,2))+pow(mZ,2)*pow(gamZ,2) );

switch(code)
{
// projections to hs
case 1:
{

// test_InteNoHs.txt

double value = 0.;

value+=(16*aPhi*aPhi1*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*f00*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) + dHs*pow(hs,6) +eHs*pow(hs,8))*pow(Pi,2))/1.2006225e7;
value+=(16*aPhi*aPhi1*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*fmm*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) + dHs*pow(hs,6) +eHs*pow(hs,8))*pow(Pi,2))/1.2006225e7;
value+=(16*aPhi*aPhi1*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*fpp*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) + dHs*pow(hs,6) +eHs*pow(hs,8))*pow(Pi,2))/1.2006225e7;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(aPhi1*bPhi*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*sqrt(f00)*sqrt(fmm)*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) + dHs*pow(hs,6) +eHs*pow(hs,8))*pow(Pi,4)*R1Val*R2Val*cos(phimm))/131072.;
value+=(aPhi1*bPhi*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*sqrt(f00)*sqrt(fpp)*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) + dHs*pow(hs,6) +eHs*pow(hs,8))*pow(Pi,4)*R1Val*R2Val*cos(phipp))/131072.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(4*aPhi1*cPhi*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*sqrt(fmm)*sqrt(fpp)*(aHs + bHs*pow(hs,2) + cHs*pow(hs,4) + dHs*pow(hs,6) +eHs*pow(hs,8))*pow(Pi,2)*cos(phimm - phipp))/1.2006225e7;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;


return betaVal*term1Coeff*term2Coeff*value;

}
// projections to Phi1
case 2:
{

// from test_IntNoPhi1.txt

double value = 0.;

value+=(16*aPhi*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*f00*Pi*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) + dPhi1*cos(3*Phi1) +ePhi1*cos(4*Phi1)))/3.781960875e9;
value+=(16*aPhi*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*fmm*Pi*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) + dPhi1*cos(3*Phi1) +ePhi1*cos(4*Phi1)))/3.781960875e9;
value+=(16*aPhi*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*fpp*Pi*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) + dPhi1*cos(3*Phi1) +ePhi1*cos(4*Phi1)))/3.781960875e9;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(bPhi*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(f00)*sqrt(fmm)*pow(Pi,3)*R1Val*R2Val*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) + dPhi1*cos(3*Phi1) +ePhi1*cos(4*Phi1))*cos(phimm))/262144.;
value+=(bPhi*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(f00)*sqrt(fpp)*pow(Pi,3)*R1Val*R2Val*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) + dPhi1*cos(3*Phi1) +ePhi1*cos(4*Phi1))*cos(phipp))/262144.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(4*cPhi*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*sqrt(fmm)*sqrt(fpp)*Pi*(aPhi1 + bPhi1*cos(Phi1) + cPhi1*cos(2*Phi1) + dPhi1*cos(3*Phi1) +ePhi1*cos(4*Phi1))*cos(phimm - phipp))/3.781960875e9;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;


return betaVal*term1Coeff*term2Coeff*value;

}
// projections to h2
case 3:
{

// from test_IntNoH2.txt

double value = 0.;

value+=(-4*aPhi*aPhi1*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*f00*(-1 + pow(h2,2))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) +dH2*pow(h2,6) + eH2*pow(h2,8))*pow(Pi,2))/3465.;
value+=(2*aPhi*aPhi1*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*fmm*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) + dH2*pow(h2,6) +eH2*pow(h2,8))*pow(Pi,2)*(1 + pow(h2,2) - 2*h2*R2Val))/3465.;
value+=(2*aPhi*aPhi1*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*fpp*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) + dH2*pow(h2,6) +eH2*pow(h2,8))*pow(Pi,2)*(1 + pow(h2,2) + 2*h2*R2Val))/3465.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=-(aPhi1*bPhi*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(f00)*sqrt(fmm)*sqrt(1 - pow(h2,2))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) + dH2*pow(h2,6) +eH2*pow(h2,8))*pow(Pi,3)*R1Val*(h2 - R2Val)*cos(phimm))/512.;
value+=(aPhi1*bPhi*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(f00)*sqrt(fpp)*sqrt(1 - pow(h2,2))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) + dH2*pow(h2,6) +eH2*pow(h2,8))*pow(Pi,3)*R1Val*(h2 + R2Val)*cos(phipp))/512.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=-(aPhi1*cPhi*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(fmm)*sqrt(fpp)*(-1 + pow(h2,2))*(aH2 + bH2*pow(h2,2) + cH2*pow(h2,4) + dH2*pow(h2,6) +eH2*pow(h2,8))*pow(Pi,2)*cos(phimm - phipp))/3465.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;


return betaVal*term1Coeff*term2Coeff*value;

}
// projections to h1
case 4:
{

// from test_IntNoH1.txt

double value = 0.;

value+=(-4*aPhi*aPhi1*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*f00*(-1 + pow(h1,2))*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) +dH1*pow(h1,6) + eH1*pow(h1,8))*pow(Pi,2))/3465.;
value+=(2*aPhi*aPhi1*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*fmm*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*pow(Pi,2)*(1 + pow(h1,2) - 2*h1*R1Val))/3465.;
value+=(2*aPhi*aPhi1*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*fpp*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*pow(Pi,2)*(1 + pow(h1,2) + 2*h1*R1Val))/3465.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=-(aPhi1*bPhi*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(f00)*sqrt(fmm)*sqrt(1 - pow(h1,2))*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*pow(Pi,3)*(h1 - R1Val)*R2Val*cos(phimm))/512.;
value+=(aPhi1*bPhi*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(f00)*sqrt(fpp)*sqrt(1 - pow(h1,2))*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*pow(Pi,3)*(h1 + R1Val)*R2Val*cos(phipp))/512.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=-(aPhi1*cPhi*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(fmm)*sqrt(fpp)*(-1 + pow(h1,2))*(aH1 + bH1*pow(h1,2) + cH1*pow(h1,4) + dH1*pow(h1,6) +eH1*pow(h1,8))*pow(Pi,2)*cos(phimm - phipp))/3465.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;


return betaVal*term1Coeff*term2Coeff*value;

}
// projections to Phi
case 5:
{

// from test_IntNoPhi.txt

double value = 0.;

value+=(16*aPhi1*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*f00*Pi*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi)))/3.781960875e9;
value+=(16*aPhi1*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*fmm*Pi*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi)))/3.781960875e9;
value+=(16*aPhi1*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*fpp*Pi*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi)))/3.781960875e9;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(aPhi1*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(f00)*sqrt(fmm)*pow(Pi,3)*R1Val*R2Val*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi))*cos(Phi - phimm))/131072.;
value+=(aPhi1*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*(2*aHs + (2*bHs)/3. + (2*cHs)/5. + (2*dHs)/7. + (2*eHs)/9.)*sqrt(f00)*sqrt(fpp)*pow(Pi,3)*R1Val*R2Val*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi))*cos(Phi + phipp))/131072.;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(8*aPhi1*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*sqrt(fmm)*sqrt(fpp)*Pi*(aPhi + bPhi*cos(Phi) + cPhi*cos(2*Phi) + dPhi*cos(3*Phi) +ePhi*cos(4*Phi))*cos(2*Phi - phimm + phipp))/3.781960875e9;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;


return betaVal*term1Coeff*term2Coeff*value;

}
// projections to mz1/mz2
case 6:
{

// from test_IntAll.txt

double value = 0.;

value+=(32*aPhi*aPhi1*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*f00*pow(Pi,2))/3.781960875e9;
value+=(32*aPhi*aPhi1*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*fmm*pow(Pi,2))/3.781960875e9;
value+=(32*aPhi*aPhi1*(1155*aH1 + 462*bH1 + 297*cH1 + 220*dH1 + 175*eH1)*(1155*aH2 + 462*bH2 + 297*cH2 + 220*dH2 + 175*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*fpp*pow(Pi,2))/3.781960875e9;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(aPhi1*bPhi*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*sqrt(f00)*sqrt(fmm)*pow(Pi,4)*R1Val*R2Val*cos(phimm))/2.064384e7;
value+=(aPhi1*bPhi*(128*aH1 + 32*bH1 + 16*cH1 + 10*dH1 + 7*eH1)*(128*aH2 + 32*bH2 + 16*cH2 + 10*dH2 + 7*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*sqrt(f00)*sqrt(fpp)*pow(Pi,4)*R1Val*R2Val*cos(phipp))/2.064384e7;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=(8*aPhi1*cPhi*(1155*aH1 + 231*bH1 + 99*cH1 + 55*dH1 + 35*eH1)*(1155*aH2 + 231*bH2 + 99*cH2 + 55*dH2 + 35*eH2)*(315*aHs + 105*bHs + 63*cHs + 45*dHs + 35*eHs)*sqrt(fmm)*sqrt(fpp)*pow(Pi,2)*cos(phimm - phipp))/3.781960875e9;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;
value+=0;


return betaVal*term1Coeff*term2Coeff*value;

}

}
assert(0) ;
return 0 ;
}


