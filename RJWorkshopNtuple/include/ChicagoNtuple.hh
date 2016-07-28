#ifndef ChicagoNtuple_h
#define ChicagoNtuple_h

#include "NtupleBase.hh"
#include "ChicagoBase.hh"
#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

class ChicagoNtuple : public NtupleBase<ChicagoBase> {

public:
  ChicagoNtuple(TTree* tree = 0);
  virtual ~ChicagoNtuple();

private:
  void InitOutputTree();
  void FillOutputTree();

  bool m_CRZ;
  bool m_CRWT;

  // CRWT
  double m_MTW;
  double m_lept1Pt;
  int m_lep1sign;

  // CRZ
  double m_Mll;
  double m_lept2Pt;
  int m_lep2sign;

  // variables for gluino tree
  double m_weight;
  UInt_t m_veto;
  UInt_t m_cleaning;
  UInt_t m_timing;

  double m_Rsib;
  double m_deltaQCD;

  double m_RPT;
  double m_RPZ;
  double m_MP;

  double m_PP_VisShape;
  double m_gaminvPP;
  double m_MDR;

  double m_cosPP;
  double m_dphiVP;
  double m_dphiPPV;
  double m_cosP;

  double m_dphiPCa;
  double m_dphiPCb;

  double m_H2PP;
  double m_H3PP;
  double m_H4PP;
  double m_H6PP;

  double m_H2Pa;
  double m_H2Pb;
  double m_H3Pa;
  double m_H3Pb;

  double m_H4Pa;
  double m_H4Pb;
  double m_H5Pa;
  double m_H5Pb;

  double m_H2Ca;
  double m_H2Cb;
  double m_H3Ca;
  double m_H3Cb;

  double m_dphiPV1a;
  double m_dphiPV1b;
  double m_cosV1a;
  double m_cosV1b;
  double m_dphiCV2a;
  double m_dphiCV2b;
  double m_cosV2a;
  double m_cosV2b;

  double m_MET;
  double m_Meff;
  double m_Aplan;
  double m_dphi;
  double m_dphiR;

  double m_NJet;
  double m_NJa;
  double m_NJb;
  double m_NJ1a;
  double m_NJ1b;
  double m_NJ2a;
  double m_NJ2b;

  double m_Nbjet;
  double m_Ntop;

  double m_pT_jet1;
  double m_pT_jet2;
  double m_pT_jet3;
  double m_pT_jet4;
  double m_pT_jet5;
  double m_pT_jet6;

  double m_pT_jet1a;
  double m_pT_jet2a;
  double m_pT_jet1b;
  double m_pT_jet2b;

  // RestFrames stuff
  LabRecoFrame*       LAB;
  DecayRecoFrame*     PP;
  DecayRecoFrame*     Pa;
  DecayRecoFrame*     Pb;
  DecayRecoFrame*     Ca;
  DecayRecoFrame*     Cb;
  SelfAssemblingRecoFrame* SAV1a;
  SelfAssemblingRecoFrame* SAV1b;
  SelfAssemblingRecoFrame* SAV2a;
  SelfAssemblingRecoFrame* SAV2b;
  VisibleRecoFrame*   V1a;
  VisibleRecoFrame*   V1b;
  VisibleRecoFrame*   V2a;
  VisibleRecoFrame*   V2b;
  InvisibleRecoFrame* Ia;
  InvisibleRecoFrame* Ib;

  InvisibleGroup*    INV;
  CombinatoricGroup* VIS;

  SetMassInvJigsaw*     InvMassJigsaw;
  SetRapidityInvJigsaw* InvRapidityJigsaw;
  ContraBoostInvJigsaw* InvCBJigsaw;
  MinMassesCombJigsaw*  CombPPJigsaw;
  MinMassesCombJigsaw*  CombPaJigsaw;
  MinMassesCombJigsaw*  CombPbJigsaw;

  LabRecoFrame*            LAB_bkg;
  SelfAssemblingRecoFrame* S_bkg;
  VisibleRecoFrame*        V_bkg;
  InvisibleRecoFrame*      I_bkg;

  InvisibleGroup*    INV_bkg;
  CombinatoricGroup* VIS_bkg;

  SetMassInvJigsaw*     InvMass_bkg;
  SetRapidityInvJigsaw* InvRapidity_bkg;

};

#endif
