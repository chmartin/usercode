scram p CMSSW_6_1_1
cd CMSSW_6_1_1/src
cmsenv

cvs co HiggsAnalysis/CombinedLimit
cvs co -d HiggsAnalysis/HZZ4lCombination UserCode/Whitbeck/HZZ4Lcombination/testCombination
cvs co -r V00-03-00 -d HiggsAnalysis/Higgs_CS_and_Width UserCode/Snowball/Higgs/Higgs_CS_and_Width

sed -i 's|#include "HiggsCSandWidth.h"|#include "HiggsAnalysis/Higgs_CS_and_Width/include/HiggsCSandWidth.h"|' HiggsAnalysis/Higgs_CS_and_Width/src/HiggsCSandWidth.cc

scram b -j4

cd HiggsAnalysis/HZZ4lCombination/test

cvs co -d SM_inputs_7TeV UserCode/HZZ4L_Combination/CombinationPy/CreateDatacards/SM_inputs_7TeV

cvs co -d SM_inputs_8TeV UserCode/HZZ4L_Combination/CombinationPy/CreateDatacards/SM_inputs_8TeV

root -l -n -q loadClasses.C  testA.C
root -l -n -q loadClasses.C  testB.C