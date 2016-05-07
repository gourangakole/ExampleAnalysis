#ifndef _uncertaintycomputer_h_
#define _uncertaintycomputer_h_

#if !defined(__CINT__) || defined(__MAKECINT__)

#include <iomanip>
#include <iostream>
#include <fstream>

#include "TRandom2.h"
#include "TMatrixD.h"
#include "TF1.h"
#include "TProfile.h"
#include "TObjArray.h"
#include "TMatrixD.h"
#include "TH1.h"
#include "TTimeStamp.h"
#include <exception>

#ifdef _STANDALONE
#include "Reader.h"
#else
#include "MiniTree/Selection/interface/Reader.h"
#endif
#include "MiniTree/Selection/interface/BtagSF.hh"
#include "MiniTree/Selection/interface/SVEffUnc.hh"

#endif

const double JEREtaMap[6] = {0., 0.5, 1.1, 1.7, 2.3, 5.0}; 
const double JERSF[5] = {1.052, 1.057, 1.096, 1.134, 1.288}; 
//const double JERSFStatUn[5] = {0.012, 0.012, 0.017, 0.035, 0.127}; 
const double JERSFUp[5] = {1.115, 1.114, 1.161, 1.228, 1.488}; 
const double JERSFDown[5] = {0.990, 1.001, 1.032, 1.042, 1.089}; 

class UncertaintyComputer{

public :
  UncertaintyComputer()
  {
    btsf = new BtagSF(12345);
    sveffunc = new SVEffUnc();
  }

  ~UncertaintyComputer(){
    delete btsf;
    delete sveffunc;
  }
  
  double metWithJES(const vector<MyJet> & vJ, vector<int> *j, MyMET MET, int jes=0);
  double metWithJER(const vector<MyJet> & vJ, vector<int> *j, MyMET MET, int jer=0);
  double metWithJESJER(const vector<MyJet> & vJ, vector<int> *j, MyMET MET, int jes=0, int jer=0);
  double metWithUncl(const vector<MyJet> & vJ, vector<int> *j, const vector<MyMuon> &vMu, vector<int> *m, const vector<MyElectron> &vEle, vector<int> *el, MyMET MET, int unc=0);
  double getJERSF(double eta, int jer=0);
  double jetPtWithJESJER(MyJet jet, int jes=0, int jer=0); 
  bool getBtagWithSF(MyJet jet, bool isData, int scale, bool is2012);
  double EffUncOnSV(MyJet jet);
  
private :
  BtagSF* btsf;
  enum BVariation{kNo = 0, kDown = 1, kUp = 2};
  SVEffUnc* sveffunc;

  ClassDef(UncertaintyComputer, 1)
};
#endif
