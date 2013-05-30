/*****************************************************************************
 * Project: RooFit                                                           *
 *                                                                           *
  * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/

#ifndef ROOSPINZERO_5D_ZH
#define ROOSPINZERO_5D_ZH

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class RooSpinZero_5D_ZH : public RooAbsPdf {
public:
  RooSpinZero_5D_ZH() {} ; 
  RooSpinZero_5D_ZH(const char *name, const char *title,
	      RooAbsReal& _h1,
	      RooAbsReal& _h2,
	      RooAbsReal& _hs,
	      RooAbsReal& _Phi,
   	      RooAbsReal& _Phi1,
	      RooAbsReal& _sqrts,
	      RooAbsReal& _mH,
	      RooAbsReal& _mZ,
	      RooAbsReal& _a1,
	      RooAbsReal& _a2,
	      RooAbsReal& _a3,
	      RooAbsReal& _phi1,
	      RooAbsReal& _phi2,
	      RooAbsReal& _phi3,
	      RooAbsReal& _R1val,
	      RooAbsReal& _R2Val);

  RooSpinZero_5D_ZH(const RooSpinZero_5D_ZH& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooSpinZero_5D_ZH(*this,newname); }
  inline virtual ~RooSpinZero_5D_ZH() { }

	Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const ;
	Double_t analyticalIntegral(Int_t code, const char* rangeName=0) const ;

	
protected:

  RooRealProxy h1 ;
  RooRealProxy h2 ;
  RooRealProxy hs ;
  RooRealProxy Phi ;
  RooRealProxy Phi1 ;
  RooRealProxy sqrts ;
  RooRealProxy mH ;
  RooRealProxy mZ ;
  RooRealProxy a1 ;
  RooRealProxy a2 ;
  RooRealProxy a3 ;
  RooRealProxy phia1 ;
  RooRealProxy phia2 ;
  RooRealProxy phia3 ;
  RooRealProxy R1Val ;
  RooRealProxy R2Val ;

    
  Double_t evaluate() const ;

private:

  ClassDef(RooSpinZero_5D_ZH,1) // Your description goes here...
};
 
#endif
