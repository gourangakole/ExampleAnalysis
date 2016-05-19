#include "MiniTree/Selection/interface/UncertaintyComputer.hh"
#include <iostream>
#include <iomanip>

ClassImp(UncertaintyComputer)

using namespace std;

double UncertaintyComputer::metWithJER(const vector<MyJet> & vJ, vector<int> *j, MyMET MET, int jer)
{
  double metX = MET.p4.px();
  double metY = MET.p4.py();

  for(size_t i = 0; i < j->size(); i++){
    int j_ind = j->at(i);
    
    double gen_pt = vJ[j_ind].Genp4.pt();
    if(gen_pt <= 0) continue;
    MyLorentzVector rawJet = vJ[j_ind].p4; //vJ[j_ind].JECs["Uncorrected"]*vJ[j_ind].p4;
    metX += rawJet.px();
    metY += rawJet.py();
    double jet_pt = vJ[j_ind].p4.pt();
    double SF = getJERSF(vJ[j_ind].p4.eta(), jer);
    double ptscale = max(0.0, 1.0 + (SF - 1)*(jet_pt - gen_pt)/ jet_pt);
    rawJet *= ptscale;
    metX -= rawJet.px();
    metY -= rawJet.py();
  } 

  return sqrt(metX*metX + metY*metY);
}

double UncertaintyComputer::getJERSF(double eta, int jer)
{

  double SF = 1.0;
  for(size_t i = 0; i < 7; i++){
    if(TMath::Abs(eta) >= JEREtaMap[i] && TMath::Abs(eta) < JEREtaMap[i+1]){
      if(jer == 0)SF = JERSF[i];
      else if (jer == 1){
	SF = JERSFUp[i]; //JERSF[i] + sqrt(JERSFStatUn[i]*JERSFStatUn[i] + JERSFUp[i]*JERSFUp[i]);
      }
      else if(jer == -1){
	SF = JERSFDown[i]; //JERSF[i] - sqrt(JERSFStatUn[i]*JERSFStatUn[i] + JERSFDown[i]*JERSFDown[i]);
      }
    }
  }

  return SF;
}

double UncertaintyComputer::metWithJES(const vector<MyJet> & vJ, vector<int> *j, MyMET MET, int jes)
{
  double metX = MET.p4.px(); 
  double metY = MET.p4.py(); 
  
  for(size_t i = 0; i < j->size(); i++){ 
    int j_ind = j->at(i); 

    metX -= (vJ[j_ind].p4.px()*(vJ[j_ind].JECUncertainty*double(jes)));
    metY -= (vJ[j_ind].p4.py()*(vJ[j_ind].JECUncertainty*double(jes)));
  }

  return sqrt(metX*metX + metY*metY);
}

double UncertaintyComputer::metWithJESJER(const vector<MyJet> & vJ, vector<int> *j, MyMET MET, int jes, int jer) 
{ 
  double metX = MET.p4.px(); 
  double metY = MET.p4.py(); 

  //get JER uncert.
  for(size_t i = 0; i < j->size(); i++){ 
    int j_ind = j->at(i); 
     
    double gen_pt = vJ[j_ind].Genp4.pt(); 
    if(gen_pt <= 0) continue; 
    MyLorentzVector rawJet = vJ[j_ind].p4; //vJ[j_ind].JECs["Uncorrected"]*vJ[j_ind].p4; 
    metX += rawJet.px(); 
    metY += rawJet.py(); 
    double jet_pt = vJ[j_ind].p4.pt(); 
    double SF = getJERSF(vJ[j_ind].p4.eta(), jer); 
    double ptscale = max(0.0, 1.0 + (SF - 1)*(jet_pt - gen_pt)/ jet_pt); 
    rawJet *= ptscale; 
    metX -= rawJet.px(); 
    metY -= rawJet.py(); 
  }  

  //get JES unc.
  for(size_t i = 0; i < j->size(); i++){  
    int j_ind = j->at(i);  
 
    metX -= (vJ[j_ind].p4.px()*(vJ[j_ind].JECUncertainty*double(jes))); 
    metY -= (vJ[j_ind].p4.py()*(vJ[j_ind].JECUncertainty*double(jes))); 
  } 
 
  return sqrt(metX*metX + metY*metY); 
}

double UncertaintyComputer::metWithUncl(const vector<MyJet> & vJ, vector<int> *j, const vector<MyMuon> &vMu, vector<int> *m, const vector<MyElectron> &vEle, vector<int> *el, MyMET MET, int unc)
{
  double metX = MET.p4.px(); 
  double metY = MET.p4.py(); 

  //remove jets
  for(size_t i = 0; i < j->size(); i++){  
    int j_ind = j->at(i);
    
    metX += vJ[j_ind].p4.px();
    metY += vJ[j_ind].p4.py();

  }
  //remove leptons
  for(size_t i = 0; i < m->size(); i++){   
    int m_ind = m->at(i); 

    metX += vMu[m_ind].p4.px();
    metY += vMu[m_ind].p4.py();
  }
  for(size_t i = 0; i < el->size(); i++){
    int e_ind = el->at(i);
    metX += vEle[e_ind].p4.px();
    metY += vEle[e_ind].p4.py();
  }

  metX *= (1 + double(unc)*0.1); //vary by 10%
  metY *= (1 + double(unc)*0.1);

  //Re add objects
  for(size_t i = 0; i < m->size(); i++){    
    int m_ind = m->at(i);  
 
    metX -= vMu[m_ind].p4.px(); 
    metY -= vMu[m_ind].p4.py(); 
  } 
  for(size_t i = 0; i < el->size(); i++){ 
    int e_ind = el->at(i); 
    metX -= vEle[e_ind].p4.px(); 
    metY -= vEle[e_ind].p4.py(); 
  } 

  for(size_t i = 0; i < j->size(); i++){   
    int j_ind = j->at(i); 
     
    metX -= vJ[j_ind].p4.px(); 
    metY -= vJ[j_ind].p4.py(); 
 
  } 

  return sqrt(metX*metX + metY*metY);
}

double UncertaintyComputer::jetPtWithJESJER(MyJet jet, int jes, int jer){

  double gen_pt = jet.Genp4.pt();  
  double jet_pt = jet.p4.pt();
  //apply JES uncert scaling 
  jet_pt *= (1+(jet.JECUncertainty*double(jes)));

  //apply JER uncert, scaling
  if(gen_pt > 0){
    double SF = getJERSF(jet.p4.eta(), jer); 
    double ptscale = max(0.0, 1.0 + (SF - 1)*(jet_pt - gen_pt)/ jet_pt);
    jet_pt *= ptscale;
  }
  
  return jet_pt;
}

bool UncertaintyComputer::getBtagWithSF(MyJet jet, bool isData, int scale, bool is2012){
  bool isBtagged = false;

  if(scale == 0){
    isBtagged = btsf->isbtagged(jet.p4.pt(), jet.p4.eta(), jet.bDiscriminator["combinedSecondaryVertexBJetTags"], jet.partonFlavour, isData ,kNo, kNo, is2012);
  }
  else if(scale == 1){
    isBtagged = btsf->isbtagged(jet.p4.pt(), jet.p4.eta(), jet.bDiscriminator["combinedSecondaryVertexBJetTags"], jet.partonFlavour, isData ,kUp, kUp, is2012);
  }
  else if(scale == -1){
    isBtagged = btsf->isbtagged(jet.p4.pt(), jet.p4.eta(), jet.bDiscriminator["combinedSecondaryVertexBJetTags"], jet.partonFlavour, isData ,kDown, kDown, is2012);
  }
  
  return isBtagged;
}

double UncertaintyComputer::EffUncOnSV(MyJet jet)
{
  
  double Uncert = 0.0;
  if(abs(jet.partonFlavour) >= 3 && abs(jet.partonFlavour) <= 5)
    {
      Uncert = sveffunc->getUncC(jet.p4.pt());
    }
  else
    {
      Uncert = sveffunc->getUncL(jet.p4.pt(), jet.p4.eta());
    }

  return Uncert;
}
