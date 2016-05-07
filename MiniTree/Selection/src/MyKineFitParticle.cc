#include "MiniTree/Selection/interface/MyKineFitParticle.h"

ClassImp(MyKineFitParticle)

MyKineFitParticle::MyKineFitParticle():
  partName(""),
  labelName(""),
  part_id(0),
  part_mother_id(0),
  charge(0),
  chi2OfFit(999.),
  statusOfFit(0),
  probOfFit(0),
  njetsOfFit(0)
{
}

MyKineFitParticle::~MyKineFitParticle() 
{
}

void MyKineFitParticle::Reset()
{
  p4.SetCoordinates(0.0, 0.0, 0.0, 0.0);
  vertex.SetCoordinates(-999.0,-999.0,-999.0);

  partName = "";
  labelName = "";
  part_id = 0;
  part_mother_id = 0;
  charge = 0;
  chi2OfFit = 999.;
  statusOfFit = 0;
  probOfFit = 0;
  njetsOfFit = 0;
}
