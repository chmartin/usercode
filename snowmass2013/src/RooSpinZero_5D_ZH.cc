 /***************************************************************************** 
  * Project: RooFit                                                           * 
  *                                                                           * 
  * This code was autogenerated by RooClassFactory                            * 
  *****************************************************************************/ 

 // Your description goes here... 

 #include "Riostream.h" 

 #include "RooSpinZero_5D_ZH.h" 
 #include "RooAbsReal.h" 
 #include "RooAbsCategory.h" 

#include <math.h>
#include "TMath.h"

using namespace TMath;


 ClassImp(RooSpinZero_5D_ZH) 

 RooSpinZero_5D_ZH::RooSpinZero_5D_ZH(const char *name, const char *title, 
                        RooAbsReal& _h1,
                        RooAbsReal& _h2,
                        RooAbsReal& _hs,
                        RooAbsReal& _Phi,
			RooAbsReal& _Phi1,
			RooAbsReal& _sqrts,
			RooAbsReal& _mH,
    	                RooAbsReal& _mZ,
			RooAbsReal& _R1Val,
                        RooAbsReal& _R2Val) :
   RooAbsPdf(name,title), 
   h1("h1","h1",this,_h1),
   h2("h2","h2",this,_h2),
   hs("hs","hs",this,_hs),
   Phi("Phi","Phi",this,_Phi),
   Phi1("Phi1","Phi1",this,_Phi1),
   sqrts("sqrts","sqrts",this,_sqrts),
   mH("mH","mH",this,_mH),
   mZ("mZ","mZ",this,_mZ),
   R1Val("R1Val","R1Val",this,_R1Val),
   R2Val("R2Val","R2Val",this,_R2Val)
 { 
 } 


 RooSpinZero_5D_ZH::RooSpinZero_5D_ZH(const RooSpinZero_5D_ZH& other, const char* name) :  
   RooAbsPdf(other,name), 
   h1("h1",this,other.h1),
   h2("h2",this,other.h2),
   hs("hs",this,other.hs),
   Phi("Phi",this,other.Phi),
   Phi1("Phi1",this,other.Phi1),
   sqrts("sqrts",this,other.sqrts),
   mH("mH",this,other.mH),
   mZ("mZ",this,other.mZ),
   R1Val("R1Val",this,other.R1Val),
   R2Val("R2Val",this,other.R2Val)
 { 
 } 



 Double_t RooSpinZero_5D_ZH::evaluate() const 
 { 
   Double_t shs = sqrt(1-hs*hs);
   Double_t sh1 = sqrt(1-h1*h1);
   Double_t sh2 = sqrt(1-h2*h2);
   
   Double_t betaValSquared =(1.-(pow(mH+mZ,2)/pow(sqrts,2)))*(1.-(pow(mH-mZ,2)/pow(sqrts,2)));
   Double_t gamma = 1./sqrt(1-betaValSquared);

   
   // these amplitudes are calculated based on comparing equations to the PRD paper
   Double_t f00 = gamma*gamma/(2+gamma*gamma);
   Double_t fp0 = (1.-f00)/2.;
   Double_t fm0 = fp0;
   
   Double_t phi00 = TMath::Pi();
   Double_t phip0 = 0.-phi00;
   Double_t phim0 = 0.-phi00;

   Double_t value = 0;
   

   value += (f00*(-1 + Power(h1,2))*(-1 + Power(hs,2)))/4.;

   value += (fp0*(1 + Power(h1,2) + 2*h1*R1Val)*(1 + Power(hs,2) - 2*hs*R2Val))/16.;

   value += (fm0*(1 + Power(h1,2) - 2*h1*R1Val)*(1 + Power(hs,2) + 2*hs*R2Val))/16.;

   value += (Sqrt(f00)*Sqrt(fp0)*Sqrt(1 - Power(h1,2))*Sqrt(1 - Power(hs,2))*(h1 + R1Val)*(hs - R2Val)*Cos(Phi1 - phip0))/4.;

   value += (Sqrt(f00)*Sqrt(fm0)*Sqrt(1 - Power(h1,2))*Sqrt(1 - Power(hs,2))*(h1 - R1Val)*(hs + R2Val)*Cos(Phi1 + phim0))/4.;

   value += (Sqrt(fm0)*Sqrt(fp0)*(-1 + Power(h1,2))*(-1 + Power(hs,2))*Cos(2*Phi1 + phim0 - phip0))/8.;


   return value ; 
 } 

Int_t RooSpinZero_5D_ZH::getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* /*rangeName*/) const
{
  
  if (matchArgs(allVars,analVars,RooArgSet(*h1.absArg(),*h2.absArg(),*hs.absArg(),*Phi.absArg(),*Phi1.absArg()))) return 6 ;
  if (matchArgs(allVars,analVars,h1,h2,Phi,Phi1)) return 1 ;
  if (matchArgs(allVars,analVars,h1,h2,hs,Phi)) return 2 ;
  if (matchArgs(allVars,analVars,h1,hs,Phi,Phi1)) return 3 ;
  if (matchArgs(allVars,analVars,h2,hs,Phi,Phi1)) return 4 ;
  if (matchArgs(allVars,analVars,h1,h2,hs,Phi1)) return 5 ;
  
  return 0 ;
}

Double_t RooSpinZero_5D_ZH::analyticalIntegral(Int_t code, const char* rangeName) const
{
   
   Double_t R1Val = 0.15;

   Double_t betaValSquared =(1.-(pow(mH+mZ,2)/pow(sqrts,2)))*(1.-(pow(mH-mZ,2)/pow(sqrts,2)));
   Double_t gamma = 1./sqrt(1-betaValSquared);

   // these amplitudes are calculated based on comparing equations to the PRD paper
   Double_t f00 = gamma*gamma/(2+gamma*gamma);
   Double_t fp0 = (1.-f00)/2.;
   Double_t fm0 = fp0;
   
   Double_t phi00 = TMath::Pi();
   Double_t phip0 = 0.-phi00;
   Double_t phim0 = 0.-phi00;

   switch(code)
     {
       // projections to hs
     case 1:
       {

	 double value = 0.;
	 value += (-8*f00*(-1 + Power(hs,2))*Power(Pi(),2))/3.;

	 value += (4*fp0*Power(Pi(),2)*(1 + Power(hs,2) + 2*hs*R2Val))/3.;

	 value += (4*fm0*Power(Pi(),2)*(1 + Power(hs,2) - 2*hs*R2Val))/3.;

	 return value;

       }
       // projections to Phi1
     case 2:
       {

	 double value = 0.;
	 value += (16*f00*Pi())/9.;

	 value += (16*fp0*Pi())/9.;
	 
	 value += (16*fm0*Pi())/9.;
	 
	 value += (Sqrt(f00)*Sqrt(fp0)*Power(Pi(),3)*R1Val*R2Val*Cos(Phi1 - phip0))/4.;

	 value += (Sqrt(f00)*Sqrt(fm0)*Power(Pi(),3)*R1Val*R2Val*Cos(Phi1 + phim0))/4.;

	 value += (8*sqrt(fm0)*sqrt(fp0)*Pi()*Cos(2*Phi1 - phim0 + phip0))/9.;
	 
	 return value;

       }
       // projections to h2
     case 3:
       {


	 double value = 0.;
	 
	 value += (16*f00*Power(Pi(),2))/9.;
	 
	 value += (16*fp0*Power(Pi(),2))/9.;
	 
	 value += (16*fm0*Power(Pi(),2))/9.;
	 
	 return value;

       }
       // projections to h1
     case 4:
       {

	 double value = 0;
	 
	 value += (-8*f00*(-1 + Power(h1,2))*Power(Pi(),2))/3.;

	 value += (4*fp0*Power(Pi(),2)*(1 + Power(h1,2) + 2*h1*R1Val))/3.;

	 value += (4*fm0*Power(Pi(),2)*(1 + Power(h1,2) - 2*h1*R1Val))/3.;

	 return value;

       }
       // projections to Phi
     case 5:
       {


	 double value = 0.;
	 
	 value += (16*f00*Pi())/9.;
	 
	 value += (16*fp0*Pi())/9.;
	 
	 value += (16*fm0*Pi())/9.;

	 return value;

       }
       // projected everything
     case 6:
       {
	 double value = 0.;
	 
	 value += (32*f00*Power(Pi(),2))/9.;
	 
	 value += (32*fp0*Power(Pi(),2))/9.;
	 
	 value += (32*fm0*Power(Pi(),2))/9.;
	 
	 return value;
       }
     }
   assert(0) ;
   return 0 ;
}



