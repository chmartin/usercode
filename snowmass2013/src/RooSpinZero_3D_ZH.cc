/***************************************************************************** 
  * Project: RooFit                                                           * 
  *                                                                           * 
  * This code was autogenerated by RooClassFactory                            * 
  *****************************************************************************/ 

 // Your description goes here... 

#include "Riostream.h" 

#include "RooSpinZero_3D_ZH.h" 
#include "RooAbsReal.h" 
#include "RooAbsCategory.h" 

#include "TLorentzRotation.h"
#include "TLorentzVector.h"

#include <math.h>
#include "TMath.h"

using namespace TMath;

enum parameterizationList {kMagPhase_As=0,kRealImag_Gs=1,kFracPhase_Gs=2,kNUMparameterizations=3};


 ClassImp(RooSpinZero_3D_ZH) 

 RooSpinZero_3D_ZH::RooSpinZero_3D_ZH(const char *name, const char *title, 
				      RooAbsReal& _h1,
				      RooAbsReal& _h2,
				      RooAbsReal& _Phi,
				      RooAbsReal& _sqrts,
				      RooAbsReal& _mX,
				      RooAbsReal& _mZ,
				      RooAbsReal& _R1Val,
				      RooAbsReal& _R2Val,
				      int _parameterization,
				      RooAbsReal& _a1Val,
				      RooAbsReal& _phi1Val,
				      RooAbsReal& _a2Val,
				      RooAbsReal& _phi2Val,
				      RooAbsReal& _a3Val,
				      RooAbsReal& _phi3Val,
				      RooAbsReal& _g1Val,
				      RooAbsReal& _g2Val,
				      RooAbsReal& _g3Val,
				      RooAbsReal& _g4Val,
				      RooAbsReal& _g1ValIm,
				      RooAbsReal& _g2ValIm,
				      RooAbsReal& _g3ValIm,
				      RooAbsReal& _g4ValIm,
				      RooAbsReal& _fa2,
				      RooAbsReal& _fa3,
				      RooAbsReal& _phia2,
				      RooAbsReal& _phia3,
				      bool      _withAcc):
   RooAbsPdf(name,title), 
   h1("h1","h1",this,_h1),
   h2("h2","h2",this,_h2),
   Phi("Phi","Phi",this,_Phi),
   sqrts("sqrts","sqrts",this,_sqrts),
   mX("mX","mX",this,_mX),
   mZ("mZ","mZ",this,_mZ),
   R1Val("R1Val","R1Val",this,_R1Val),
   R2Val("R2Val","R2Val",this,_R2Val),
   parameterization(_parameterization),
   a1Val("a1Val","a1Val",this,_a1Val),
   phi1Val("phi1Val","phi1Val",this,_phi1Val),
   a2Val("a2Val","a2Val",this,_a2Val),
   phi2Val("phi2Val","phi2Val",this,_phi2Val),
   a3Val("a3Val","a3Val",this,_a3Val),
   phi3Val("phi3Val","phi3Val",this,_phi3Val),
   g1Val("g1Val","g1Val",this,_g1Val),
   g2Val("g2Val","g2Val",this,_g2Val),
   g3Val("g3Val","g3Val",this,_g3Val),
   g4Val("g4Val","g4Val",this,_g4Val),
   g1ValIm("g1ValIm","g1ValIm",this,_g1ValIm),
   g2ValIm("g2ValIm","g2ValIm",this,_g2ValIm),
   g3ValIm("g3ValIm","g3ValIm",this,_g3ValIm),
   g4ValIm("g4ValIm","g4ValIm",this,_g4ValIm),
   fa2("fa2","fa2",this,_fa2),
   fa3("fa3","fa3",this,_fa3),
   phia2("phia2","phia2",this,_phia2),
   phia3("phia3","phia3",this,_phia3),
   withAcc(_withAcc)
 { 
 } 


 RooSpinZero_3D_ZH::RooSpinZero_3D_ZH(const RooSpinZero_3D_ZH& other, const char* name) :  
   RooAbsPdf(other,name), 
   h1("h1",this,other.h1),
   h2("h2",this,other.h2),
   Phi("Phi",this,other.Phi),
   sqrts("sqrts",this,other.sqrts),
   mX("mX",this,other.mX),
   mZ("mZ",this,other.mZ),
   R1Val("R1Val",this,other.R1Val),
   R2Val("R2Val",this,other.R2Val),
   parameterization(other.parameterization),
   a1Val("a1Val",this,other.a1Val),
   phi1Val("phi1Val",this,other.phi1Val),
   a2Val("a2Val",this,other.a2Val),
   phi2Val("phi2Val",this,other.phi2Val),
   a3Val("a3Val",this,other.a3Val),
   phi3Val("phi3Val",this,other.phi3Val),
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
   withAcc(other.withAcc)
 { 
 } 



 Double_t RooSpinZero_3D_ZH::evaluate() const 
 { 

   // these amplitudes are calculated based on comparing equations to the PRD paper
   // the beta and gamma are velocities of the Z in the C.O.M
   // Double_t betaValSquared =(pow(sqrts,2)-(pow(mX+mZ,2)))*(pow(sqrts,2)-(pow(mX-mZ,2)))/pow(pow(sqrts,2)-mX*mX+mZ*mZ,2);
   // Double_t gamma = 1./sqrt(1-betaValSquared);
      // http://prd.aps.org/pdf/PRD/v49/i1/p79_1
   // Double_t f00 = gamma*gamma/(2+gamma*gamma);


   // check whether event is in acceptance or not

   
   if ( withAcc ) {

     vector<TLorentzVector> lep_4vecs = Calculate4Momentum(sqrts,mZ,mX,acos(h1),acos(h2),acos(0),Phi,0);
     
     
     double pt_plus_sq = pow(lep_4vecs[1].Px(),2) + pow(lep_4vecs[1].Py(),2);
     double pt_minus_sq = pow(lep_4vecs[0].Px(),2) + pow(lep_4vecs[0].Py(),2);
     
     double sinh2_eta_plus = pow(lep_4vecs[1].Pz(),2)/pt_plus_sq;
     double sinh2_eta_minus = pow(lep_4vecs[0].Pz(),2)/pt_minus_sq;
     
     if( pt_minus_sq<25.0 
	 || pt_plus_sq<25.0 
	 || sinh2_eta_minus>pow(sinh(2.4),2) 
	 || sinh2_eta_plus>pow(sinh(2.4),2) 
	 ) return 1e-30;
   }
   //-------------------------------------------------

   // below calcualtions are based on the H->ZZ amplitudes 
   double s=-(mX*mX-sqrts*sqrts-mZ*mZ)/2.;
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
     
    if(parameterization==kFracPhase_Gs){

      double nanval = sqrt(1 - fa2 - fa3);
      if (nanval != nanval) return 0.0;

      // convert fraction and phase to g1,g2...etc
      // ILC numbers at 250 GeV at mH= 125 GeV (narrow Z width approximation)
      Double_t sigma1_e = 0.981396; // was 0.94696 at 126 GeV
      Double_t sigma2_e = 33.4674;  // was 32.1981 at 126 GeV
      Double_t sigma4_e = 7.9229;   // was 7.45502 at 126 GeV
      
      // ILC numbers at 500 GeV with mH = 125 GeV ( narrow Z width approximation) 
      if ( sqrts == 500. ) {
	sigma1_e = 2.57246; 
	sigma2_e = 516.556;  
	sigma4_e = 414.378;
      }

      double g1Mag = 1.;
      double g2Mag = sqrt(fa2/(1.-fa2-fa3))*sqrt(sigma1_e/sigma2_e); 
      double g4Mag = sqrt(fa3/(1.-fa2-fa3))*sqrt(sigma1_e/sigma4_e); 
      
      g1   = g1Mag;
      g1Im = 0.0;
      g2   = - g2Mag*cos(phia2);
      g2Im = - g2Mag*sin(phia2);
      g3   = 0.0;
      g3Im = 0.0;
      g4   = - g4Mag*cos(phia3);
      g4Im = - g4Mag*sin(phia3);

      
    }else if(parameterization==kRealImag_Gs){

      g1   =  g1Val;
      g1Im =  g1ValIm;
      g2   =  - g2Val;
      g2Im =  - g2ValIm;
      g3   = g3Val;
      g3Im =  g3ValIm;
      g4   = - g4Val;
      g4Im = - g4ValIm;
    }
    
    a1 = g1*mZ*mZ/(mX*mX) + g2*2.*s/(mX*mX) + g3*kappa*s/(mX*mX);
    a1Im = g1Im*mZ*mZ/(mX*mX) + g2Im*2.*s/(mX*mX) + g3Im*kappa*s/(mX*mX);
    a2 = -2.*g2 - g3*kappa;
    a2Im = -2.*g2Im - g3Im*kappa;
    a3 = -2.*g4;
    a3Im = -2.*g4Im;

  }
  

   Double_t x = pow((mX*mX-sqrts*sqrts-mZ*mZ)/(2.*sqrts*mZ),2)-1;
   
   Double_t A00Real = - (a1*sqrt(1+x) + a2*(mZ*sqrts)/(mX*mX)*x);
   Double_t A00Imag = - (a1Im*sqrt(1+x) + a2Im*(mZ*sqrts)/(mX*mX)*x);

   Double_t Ap0Real = a1 - a3Im*(mZ*sqrts)/(mX*mX)*sqrt(x);
   Double_t Ap0Imag = a1Im + a3*(mZ*sqrts)/(mX*mX)*sqrt(x);

   Double_t Am0Real = a1 + a3Im*(mZ*sqrts)/(mX*mX)*sqrt(x);
   Double_t Am0Imag = a1Im - a3*(mZ*sqrts)/(mX*mX)*sqrt(x);

   Double_t f00 = A00Real*A00Real + A00Imag*A00Imag;
   Double_t fp0 = Ap0Real*Ap0Real + Ap0Imag*Ap0Imag;
   Double_t fm0 = Am0Real*Am0Real + Am0Imag*Am0Imag;
   
   Double_t ftotal = f00 + fp0 + fm0;
   
   // normalize to the total
   f00 = f00 / ftotal;
   fp0 = fp0 / ftotal;
   fm0 = fm0 / ftotal;
   
   Double_t phi00=atan2(A00Imag,A00Real);
   Double_t phip0=atan2(Ap0Imag,Ap0Real)-phi00;
   Double_t phim0=atan2(Am0Imag,Am0Real)-phi00;
   
   Double_t value = 0;
   

   value += (f00*(-1 + Power(h1,2))*(-1 + Power(h2,2)))/4.;

   value += (fp0*(1 + Power(h1,2) - 2*h1*R1Val)*(1 + Power(h2,2) + 2*h2*R2Val))/16.;

   value += (fm0*(1 + Power(h1,2) + 2*h1*R1Val)*(1 + Power(h2,2) - 2*h2*R2Val))/16.;

   value += -(Sqrt(f00)*Sqrt(fp0)*Sqrt(1 - Power(h1,2))*Sqrt(1 - Power(h2,2))*(h1 - R1Val)*(h2 + R2Val)*Cos(Phi + phip0))/4.;

   value += -(Sqrt(f00)*Sqrt(fm0)*Sqrt(1 - Power(h1,2))*Sqrt(1 - Power(h2,2))*(h1 + R1Val)*(h2 - R2Val)*Cos(Phi - phim0))/4.;

   value += (Sqrt(fm0)*Sqrt(fp0)*(-1 + Power(h1,2))*(-1 + Power(h2,2))*Cos(2*Phi - phim0 + phip0))/8.;


   return value ; 
 } 

Int_t RooSpinZero_3D_ZH::getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* /*rangeName*/) const
{

  if ( !withAcc ) {
    if (matchArgs(allVars,analVars,RooArgSet(*h1.absArg(),*h2.absArg(),*Phi.absArg()))) return 4 ;
    if (matchArgs(allVars,analVars,h1,h2)) return 1 ;
    if (matchArgs(allVars,analVars,h1,Phi)) return 2 ;
    if (matchArgs(allVars,analVars,h2,Phi)) return 3 ;
  }
  return 0 ;
}

Double_t RooSpinZero_3D_ZH::analyticalIntegral(Int_t code, const char* rangeName) const
{
   
   // check whether event is in acceptance or not

   if ( withAcc ) {

     vector<TLorentzVector> lep_4vecs = Calculate4Momentum(sqrts,mZ,mX,acos(h1),acos(h2),acos(0),Phi,0);
   
     double pt_plus_sq = pow(lep_4vecs[1].Px(),2) + pow(lep_4vecs[1].Py(),2);
     double pt_minus_sq = pow(lep_4vecs[0].Px(),2) + pow(lep_4vecs[0].Py(),2);
     
     double sinh2_eta_plus = pow(lep_4vecs[1].Pz(),2)/pt_plus_sq;
     double sinh2_eta_minus = pow(lep_4vecs[0].Pz(),2)/pt_minus_sq;
     
     if( pt_minus_sq<25.0 
	 || pt_plus_sq<25.0 
	 || sinh2_eta_minus>pow(sinh(2.4),2) 
	 || sinh2_eta_plus>pow(sinh(2.4),2) 
	 ) return 1e-30;
   }

    // the beta and gamma are velocities of the Z in the C.O.M
   Double_t betaValSquared =(pow(sqrts,2)-(pow(mX+mZ,2)))*(pow(sqrts,2)-(pow(mX-mZ,2)))/pow(pow(sqrts,2)-mX*mX+mZ*mZ,2);
   Double_t gamma = 1./sqrt(1-betaValSquared);

   // these amplitudes are calculated based on comparing equations to the PRD paper
   // http://prd.aps.org/pdf/PRD/v49/i1/p79_1
   // Double_t f00 = gamma*gamma/(2+gamma*gamma);
  
    // below calcualtions are based on the H->ZZ amplitudes 
   double s=-(mX*mX-sqrts*sqrts-mZ*mZ)/2.;
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
     
     if(parameterization==kFracPhase_Gs){
       // 
       // place holder, not correct
       // 
       double nanval = sqrt(1 - fa2 - fa3);
       if (nanval != nanval) return 0.0;
       
       // convert fraction and phase to g1,g2...etc
       // ILC numbers at 250 GeV at mH= 125 GeV (narrow Z width approximation)
       Double_t sigma1_e = 0.981396; // was 0.94696 at 126 GeV
       Double_t sigma2_e = 33.4674;  // was 32.1981 at 126 GeV
       Double_t sigma4_e = 7.9229;   // was 7.45502 at 126 GeV
       
      // ILC numbers at 500 GeV with mH = 125 GeV ( narrow Z width approximation) 
      if ( sqrts == 500. ) {
	sigma1_e = 2.57246; 
	sigma2_e = 516.556;  
	sigma4_e = 414.378;
      }
       
       double g1Mag = 1.;
       double g2Mag = sqrt(fa2/(1.-fa2-fa3))*sqrt(sigma1_e/sigma2_e); 
       double g4Mag = sqrt(fa3/(1.-fa2-fa3))*sqrt(sigma1_e/sigma4_e); 
       
       g1   = g1Mag;
       g1Im = 0.0;
       g2   = - g2Mag*cos(phia2);
       g2Im = - g2Mag*sin(phia2);
       g3   = 0.0;
       g3Im = 0.0;
       g4   = - g4Mag*cos(phia3);
       g4Im = - g4Mag*sin(phia3);
              
       
     }else if(parameterization==kRealImag_Gs){
       
       g1   =  g1Val;
       g1Im =  g1ValIm;
       g2   =  -g2Val;
       g2Im =  -g2ValIm;
       g3   = g3Val;
       g3Im = g3ValIm;
       g4   = - g4Val;
       g4Im = - g4ValIm;
     }
     
     a1 = g1*mZ*mZ/(mX*mX) + g2*2.*s/(mX*mX) + g3*kappa*s/(mX*mX);
     a1Im = g1Im*mZ*mZ/(mX*mX) + g2Im*2.*s/(mX*mX) + g3Im*kappa*s/(mX*mX);
     a2 = -2.*g2 - g3*kappa;
     a2Im = -2.*g2Im - g3Im*kappa;
     a3 =  - 2.*g4;
     a3Im = -2.*g4Im;
     
   }
   
   Double_t x = pow((mX*mX-sqrts*sqrts-mZ*mZ)/(2.*sqrts*mZ),2)-1;
   
   Double_t A00Real = - (a1*sqrt(1+x) + a2*(mZ*sqrts)/(mX*mX)*x);
   Double_t A00Imag = - (a1Im*sqrt(1+x) + a2Im*(mZ*sqrts)/(mX*mX)*x);

   Double_t Ap0Real = a1 - a3Im*(mZ*sqrts)/(mX*mX)*sqrt(x);
   Double_t Ap0Imag = a1Im + a3*(mZ*sqrts)/(mX*mX)*sqrt(x);

   Double_t Am0Real = a1 + a3Im*(mZ*sqrts)/(mX*mX)*sqrt(x);
   Double_t Am0Imag = a1Im - a3*(mZ*sqrts)/(mX*mX)*sqrt(x);

   Double_t f00 = A00Real*A00Real + A00Imag*A00Imag;
   Double_t fp0 = Ap0Real*Ap0Real + Ap0Imag*Ap0Imag;
   Double_t fm0 = Am0Real*Am0Real + Am0Imag*Am0Imag;

   Double_t ftotal = f00 + fp0 + fm0;
   
   // normalize to the total
   f00 = f00 / ftotal;
   fp0 = fp0 / ftotal;
   fm0 = fm0 / ftotal;
   
   Double_t phi00=atan2(A00Imag,A00Real);
   Double_t phip0=atan2(Ap0Imag,Ap0Real)-phi00;
   Double_t phim0=atan2(Am0Imag,Am0Real)-phi00;

   switch(code)
     {
       // projections to h2
     case 2:
       {


	 double value = 0.;
	 
	 value += (-8*f00*(-1 + Power(h2,2))*Power(Pi(),2))/3.;

	 value += (4*fp0*Power(Pi(),2)*(1 + Power(h2,2) + 2*h2*R2Val))/3.;

	 value += (4*fm0*Power(Pi(),2)*(1 + Power(h2,2) - 2*h2*R2Val))/3.;
	 
	 return value/(4*Pi());

       }
       // projections to h1
     case 3:
       {

	 double value = 0;
	 
	 value += (-8*f00*(-1 + Power(h1,2))*Power(Pi(),2))/3.;

	 value += (4*fp0*Power(Pi(),2)*(1 + Power(h1,2) - 2*h1*R1Val))/3.;

	 value += (4*fm0*Power(Pi(),2)*(1 + Power(h1,2) + 2*h1*R1Val))/3.;

	 return value/(4*Pi());

       }
       // projections to Phi
     case 1:
       {


	 double value = 0.;
	 
	 value += (16*f00*Pi())/9.;

	 value += (16*fp0*Pi())/9.;
	 
	 value += (16*fm0*Pi())/9.;
	 
	 value += (Sqrt(f00)*Sqrt(fp0)*Power(Pi(),3)*R1Val*R2Val*Cos(Phi + phip0))/4.;

	 value += (Sqrt(f00)*Sqrt(fm0)*Power(Pi(),3)*R1Val*R2Val*Cos(Phi - phim0))/4.;

	 value += (8*sqrt(fm0)*sqrt(fp0)*Pi()*Cos(2*Phi - phim0 + phip0))/9.;
	 
	 return value/(4*Pi());

       }
       // projected everything
     case 4:
       {
	 double value = 0.;
	 
	 value += (32*f00*Power(Pi(),2))/9.;
	 
	 value += (32*fp0*Power(Pi(),2))/9.;
	 
	 value += (32*fm0*Power(Pi(),2))/9.;
	 
	 return value/(4*Pi());
       }
     }
   assert(0) ;
   return 0 ;
}

vector<TLorentzVector> RooSpinZero_3D_ZH::Calculate4Momentum(float Mx,float M1,float M2,float theta,float theta1,float theta2,float _Phi1_,float _Phi_) const 
{

  float phi1,phi2;
  phi1=TMath::Pi()-_Phi1_;
  phi2=_Phi1_+_Phi_;
    
    
  float gamma1,gamma2,beta1,beta2;
    
  gamma1=(Mx*Mx+M1*M1-M2*M2)/(2*Mx*M1);
  gamma2=(Mx*Mx-M1*M1+M2*M2)/(2*Mx*M2);
  beta1=sqrt(1-1/(gamma1*gamma1));
  beta2=sqrt(1-1/(gamma2*gamma2));
    
  //gluon 4 vectors
  TLorentzVector p1CM(0,0,Mx/2,Mx/2);
  TLorentzVector p2CM(0,0,-Mx/2,Mx/2);
    
  //vector boson 4 vectors
  TLorentzVector kZ1(gamma1*M1*sin(theta)*beta1,0, gamma1*M1*cos(theta)*beta1,gamma1*M1*1);   
  TLorentzVector kZ2(-gamma2*M2*sin(theta)*beta2,0, -gamma2*M2*cos(theta)*beta2,gamma2*M2*1);
    
  //Rotation and Boost matrices. Note gamma1*beta1*M1=gamma2*beta2*M2.
    
  TLorentzRotation Z1ToZ,Z2ToZ;
    
  Z1ToZ.Boost(0,0,beta1);
  Z2ToZ.Boost(0,0,beta2);
  Z1ToZ.RotateY(theta);
  Z2ToZ.RotateY(TMath::Pi()+theta);

  //fermons 4 vectors in vector boson rest frame
    
  TLorentzVector p3Z1((M1/2)*sin(theta1)*cos(phi1),(M1/2)*sin(theta1)*sin(phi1),(M1/2)*cos(theta1),(M1/2)*1);
       
  TLorentzVector p4Z1(-(M1/2)*sin(theta1)*cos(phi1),-(M1/2)*sin(theta1)*sin(phi1),-(M1/2)*cos(theta1),(M1/2)*1);
      
  TLorentzVector p5Z2((M2/2)*sin(theta2)*cos(phi2),(M2/2)*sin(theta2)*sin(phi2),(M2/2)*cos(theta2),(M2/2)*1);
    
  TLorentzVector p6Z2(-(M2/2)*sin(theta2)*cos(phi2),-(M2/2)*sin(theta2)*sin(phi2),-(M2/2)*cos(theta2),(M2/2)*1);
      

  // fermions 4 vectors in CM frame
    
  TLorentzVector p3CM,p4CM,p5CM,p6CM;
    
  p3CM=Z1ToZ*p3Z1;
  p4CM=Z1ToZ*p4Z1;
  p5CM=Z2ToZ*p5Z2;
  p6CM=Z2ToZ*p6Z2;

  vector<TLorentzVector> p;
    
  p.push_back(p3CM);
  p.push_back(p4CM);
  p.push_back(p5CM);
  p.push_back(p6CM);

  return p;
}



