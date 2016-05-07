#include "MiniTree/Selection/interface/SampleInfo.h"

ClassImp(SampleInfo)

SampleInfo::SampleInfo()
{
  sampleName="";
  mcEvtType = 0;
  pileup.clear();
  truepileup.clear();
  puWeights.clear();
  topPtWeights.clear();
  hepNUP = -99;
}

SampleInfo::~SampleInfo()
{
}
