#ifndef SunNtuple_h
#define SunNtuple_h

#include "NtupleBase.hh"
#include "SunBase.hh"
#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

class SunNtuple : public NtupleBase<SunBase> {

public:
  SunNtuple(TTree* tree = 0);
  virtual ~SunNtuple();

private:
  void InitOutputTree();
  void FillOutputTree();

  // common variables for output tree
  double m_weight;

  double m_MET;
  double m_TrkMET;
  double m_dphi_MET_TrkMET;

  bool m_HLT_xe70_tc_lcw;
  
  double m_dphiMin1;
  double m_dphiMin2;
  double m_dphiMin3;
  double m_dphiMinAll;

  // for vetoes, 1 -> pass, 0 -> fail
  bool m_LepVeto;
  bool m_TauVeto;

  // compressed variables
  double m_PTISR;
  double m_PTCM;
  double m_RISR;
  double m_cosS;
  double m_MS;
  double m_MISR;
  double m_MV;
  double m_dphiCMI;
  double m_dphiISRI;
  double m_pTjV1;
  double m_pTjV2;
  double m_pTjV3;
  double m_pTjV4;
  double m_pTjV5;
  double m_pTjV6;
  double m_pTbV1;
  double m_pTbV2;
  int m_NbV;
  int m_NbISR;
  int m_NjV;
  int m_NjISR;
  
  // RestFrames stuff
  LabRecoFrame*       LAB;
  DecayRecoFrame*     CM;
  DecayRecoFrame*     S;
  VisibleRecoFrame*   ISR;
  VisibleRecoFrame*   V;
  InvisibleRecoFrame* I;
  InvisibleGroup*  INV;
  CombinatoricGroup*  VIS;
  SetMassInvJigsaw*   InvMass;
  MinMassesCombJigsaw* SplitVis;

};

#endif
