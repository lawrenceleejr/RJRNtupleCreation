#include "ChicagoNtuple.hh"

using namespace RestFrames;

ChicagoNtuple::ChicagoNtuple(TTree* tree)
  : NtupleBase<ChicagoBase>(tree)
{
  // RestFrames stuff

  LAB = new LabRecoFrame("LAB","lab");
  PP = new DecayRecoFrame("PP","PP");
  Pa = new DecayRecoFrame("Pa","P_{a}");
  Pb = new DecayRecoFrame("Pb","P_{b}");
  Ca = new DecayRecoFrame("Ca","C_{a}");
  Cb = new DecayRecoFrame("Cb","C_{b}");
  SAV1a = new SelfAssemblingRecoFrame("SAV1a","SA_{V1a}");
  SAV1b = new SelfAssemblingRecoFrame("SAV1b","SA_{V1b}");
  SAV2a = new SelfAssemblingRecoFrame("SAV2a","SA_{V2a}");
  SAV2b = new SelfAssemblingRecoFrame("SAV2b","SA_{V2b}");
  V1a = new VisibleRecoFrame("V1a","V_{1a}");
  V1b = new VisibleRecoFrame("V1b","V_{1b}");
  V2a = new VisibleRecoFrame("V2a","V_{2a}");
  V2b = new VisibleRecoFrame("V2b","V_{2b}");
  Ia = new InvisibleRecoFrame("Ia","I_{a}");
  Ib = new InvisibleRecoFrame("Ib","I_{b}");

  LAB->SetChildFrame(*PP);
  PP->AddChildFrame(*Pa);
  PP->AddChildFrame(*Pb);
  Pa->AddChildFrame(*SAV1a);
  Pb->AddChildFrame(*SAV1b);
  Pa->AddChildFrame(*Ca);
  Pb->AddChildFrame(*Cb);

  SAV1a->AddChildFrame(*V1a);
  SAV1b->AddChildFrame(*V1b);

  Ca->AddChildFrame(*SAV2a);
  Cb->AddChildFrame(*SAV2b);
  Ca->AddChildFrame(*Ia);
  Cb->AddChildFrame(*Ib);

  SAV2a->AddChildFrame(*V2a);
  SAV2b->AddChildFrame(*V2b);

  LAB->InitializeTree();

  INV = new InvisibleGroup("INV","Invisible State Jigsaws");
  INV->AddFrame(*Ia);
  INV->AddFrame(*Ib);

  VIS = new CombinatoricGroup("VIS","Visible Object Jigsaws");
  VIS->AddFrame(*V1a);
  VIS->SetNElementsForFrame(*V1a,0,false);
  VIS->AddFrame(*V1b);
  VIS->SetNElementsForFrame(*V1b,0,false);
  VIS->AddFrame(*V2a);
  VIS->SetNElementsForFrame(*V2a,1,false);
  VIS->AddFrame(*V2b);
  VIS->SetNElementsForFrame(*V2b,1,false);

  InvMassJigsaw = new SetMassInvJigsaw("InvMassJigsaw", "Invisible system mass Jigsaw");
  INV->AddJigsaw(*InvMassJigsaw);

  InvRapidityJigsaw = new SetRapidityInvJigsaw("InvRapidityJigsaw", "Invisible system rapidity Jigsaw");
  INV->AddJigsaw(*InvRapidityJigsaw);
  InvRapidityJigsaw->AddVisibleFrames(LAB->GetListVisibleFrames());

  InvCBJigsaw = new ContraBoostInvJigsaw("InvCBJigsaw","Contraboost invariant Jigsaw");
  INV->AddJigsaw(*InvCBJigsaw);
  InvCBJigsaw->AddVisibleFrames(Pa->GetListVisibleFrames(), 0);
  InvCBJigsaw->AddVisibleFrames(Pb->GetListVisibleFrames(), 1);
  InvCBJigsaw->AddInvisibleFrame(*Ia, 0);
  InvCBJigsaw->AddInvisibleFrame(*Ib, 1);

  CombPPJigsaw = new MinMassesCombJigsaw("CombPPJigsaw","Minimize m _{V_{a,b}} Jigsaw");
  VIS->AddJigsaw(*CombPPJigsaw);
  CombPPJigsaw->AddFrame(*V1a,0);
  CombPPJigsaw->AddFrame(*V1b,1);
  CombPPJigsaw->AddFrame(*V2a,0);
  CombPPJigsaw->AddFrame(*V2b,1);

  CombPaJigsaw = new MinMassesCombJigsaw("C1HEM_JIGSAW","Minimize m _{C_{a}} Jigsaw");
  VIS->AddJigsaw(*CombPaJigsaw);
  CombPaJigsaw->AddFrame(*V1a,0);
  CombPaJigsaw->AddFrame(*V2a,1);

  CombPbJigsaw = new MinMassesCombJigsaw("C2HEM_JIGSAW","Minimize m _{C_{b}} Jigsaw");
  VIS->AddJigsaw(*CombPbJigsaw);
  CombPbJigsaw->AddFrame(*V1b,0);
  CombPbJigsaw->AddFrame(*V2b,1);

  LAB->InitializeAnalysis();

  LAB_bkg = new LabRecoFrame("LAB","lab");
  S_bkg   = new SelfAssemblingRecoFrame("CM","CM");
  V_bkg   = new VisibleRecoFrame("V_bkg","Vis");
  I_bkg   = new InvisibleRecoFrame("I_bkg","Inv");

  LAB_bkg->SetChildFrame(*S_bkg);
  S_bkg->AddChildFrame(*V_bkg);
  S_bkg->AddChildFrame(*I_bkg);

  LAB_bkg->InitializeTree();

  INV_bkg = new InvisibleGroup("INV_bkg","Invisible State Jigsaws");
  INV_bkg->AddFrame(*I_bkg);

  VIS_bkg = new CombinatoricGroup("VIS_bkg","Visible Object Jigsaws");
  VIS_bkg->AddFrame(*V_bkg);
  VIS_bkg->SetNElementsForFrame(*V_bkg,1,false);

  InvMass_bkg = new SetMassInvJigsaw("InvMass_bkg", "Invisible system mass Jigsaw");
  INV_bkg->AddJigsaw(*InvMass_bkg);

  InvRapidity_bkg = new SetRapidityInvJigsaw("InvRapidity_bkg", "Invisible system rapidity Jigsaw");
  INV_bkg->AddJigsaw(*InvRapidity_bkg);
  InvRapidity_bkg->AddVisibleFrames(LAB_bkg->GetListVisibleFrames());

  LAB_bkg->InitializeAnalysis();
}

ChicagoNtuple::~ChicagoNtuple() {
  delete LAB;
  delete PP;
  delete Pa;
  delete Pb;
  delete Ca;
  delete Cb;
  delete SAV1a;
  delete SAV1b;
  delete SAV2a;
  delete SAV2b;
  delete V1a;
  delete V1b;
  delete V2a;
  delete V2b;
  delete Ia;
  delete Ib;

  delete INV;
  delete VIS;

  delete InvMassJigsaw;
  delete InvRapidityJigsaw;
  delete InvCBJigsaw;
  delete CombPPJigsaw;
  delete CombPaJigsaw;
  delete CombPbJigsaw;

  delete LAB_bkg;
  delete S_bkg;
  delete V_bkg;
  delete I_bkg;

  delete INV_bkg;
  delete VIS_bkg;

  delete InvMass_bkg;
  delete InvRapidity_bkg;
}

void ChicagoNtuple::InitOutputTree(){
  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  if( name.find("_CRWT") != string::npos)
    m_CRWT = true;
  else
    m_CRWT = false;

  if( name.find("_CRZ") != string::npos)
    m_CRZ = true;
  else
    m_CRZ = false;

  m_Tree = (TTree*) new TTree(name.c_str(), name.c_str());

  // special variables for control regions
  if(m_CRWT){
    m_Tree->Branch("MTW", &m_MTW);
    m_Tree->Branch("lept1Pt", &m_lept1Pt);
    m_Tree->Branch("lep1sign", &m_lep1sign);
  }

  if(m_CRZ){
    m_Tree->Branch("Mll", &m_Mll);
    m_Tree->Branch("lept1Pt", &m_lept1Pt);
    m_Tree->Branch("lep1sign", &m_lep1sign);
    m_Tree->Branch("lept2Pt", &m_lept2Pt);
    m_Tree->Branch("lep2sign", &m_lep2sign);
  }

  m_Tree->Branch("weight", &m_weight);
  m_Tree->Branch("veto", &m_veto);
  m_Tree->Branch("cleaning", &m_cleaning);
  m_Tree->Branch("timing", &m_timing);

  m_Tree->Branch("Rsib", &m_Rsib);
  m_Tree->Branch("deltaQCD", &m_deltaQCD);

  m_Tree->Branch("RPT", &m_RPT);
  m_Tree->Branch("RPZ", &m_RPZ);
  m_Tree->Branch("MDR", &m_MDR);

  m_Tree->Branch("MP", &m_MP);
  m_Tree->Branch("PP_VisShape", &m_PP_VisShape);
  m_Tree->Branch("gaminvPP", &m_gaminvPP);
  m_Tree->Branch("cosPP", &m_cosPP);
  m_Tree->Branch("dphiVP", &m_dphiVP);
  m_Tree->Branch("dphiPPV", &m_dphiPPV);
  m_Tree->Branch("cosP", &m_cosP);

  m_Tree->Branch("H2PP", &m_H2PP);
  m_Tree->Branch("H3PP", &m_H3PP);
  m_Tree->Branch("H4PP", &m_H4PP);
  m_Tree->Branch("H6PP", &m_H6PP);

  m_Tree->Branch("H2Pa", &m_H2Pa);
  m_Tree->Branch("H2Pb", &m_H2Pb);
  m_Tree->Branch("H3Pa", &m_H3Pa);
  m_Tree->Branch("H3Pb", &m_H3Pb);

  m_Tree->Branch("H4Pa", &m_H4Pa);
  m_Tree->Branch("H4Pb", &m_H4Pb);
  m_Tree->Branch("H5Pa", &m_H5Pa);
  m_Tree->Branch("H5Pb", &m_H5Pb);

  m_Tree->Branch("H2Ca", &m_H2Ca);
  m_Tree->Branch("H2Cb", &m_H2Cb);
  m_Tree->Branch("H3Ca", &m_H3Ca);
  m_Tree->Branch("H3Cb", &m_H3Cb);

  m_Tree->Branch("dphiPCa", &m_dphiPCa);
  m_Tree->Branch("dphiPCb", &m_dphiPCb);

  m_Tree->Branch("dphiPV1a", &m_dphiPV1a);
  m_Tree->Branch("dphiPV1b", &m_dphiPV1b);
  m_Tree->Branch("cosV1a", &m_cosV1a);
  m_Tree->Branch("cosV1b", &m_cosV1b);
  m_Tree->Branch("dphiCV2a", &m_dphiCV2a);
  m_Tree->Branch("dphiCV2b", &m_dphiCV2b);
  m_Tree->Branch("cosV2a", &m_cosV2a);
  m_Tree->Branch("cosV2b", &m_cosV2b);

  m_Tree->Branch("MET", &m_MET);
  m_Tree->Branch("Meff", &m_Meff);
  m_Tree->Branch("Aplan", &m_Aplan);
  m_Tree->Branch("dphi", &m_dphi);
  m_Tree->Branch("dphiR", &m_dphiR);

  m_Tree->Branch("NJet", &m_NJet);
  m_Tree->Branch("NJa", &m_NJa);
  m_Tree->Branch("NJb", &m_NJb);
  m_Tree->Branch("NJ1a", &m_NJ1a);
  m_Tree->Branch("NJ1b", &m_NJ1b);
  m_Tree->Branch("NJ2a", &m_NJ2a);
  m_Tree->Branch("NJ2b", &m_NJ2b);

  m_Tree->Branch("Nbjet", &m_Nbjet);
  m_Tree->Branch("Ntop", &m_Ntop);

  m_Tree->Branch("pT_jet1", &m_pT_jet1);
  m_Tree->Branch("pT_jet2", &m_pT_jet2);
  m_Tree->Branch("pT_jet3", &m_pT_jet3);
  m_Tree->Branch("pT_jet4", &m_pT_jet4);
  m_Tree->Branch("pT_jet5", &m_pT_jet5);
  m_Tree->Branch("pT_jet6", &m_pT_jet6);
  m_Tree->Branch("pT_jet1a", &m_pT_jet1a);
  m_Tree->Branch("pT_jet2a", &m_pT_jet2a);
  m_Tree->Branch("pT_jet1b", &m_pT_jet1b);
  m_Tree->Branch("pT_jet2b", &m_pT_jet2b);
}

void ChicagoNtuple::FillOutputTree(){

  TVector3 ETMiss = GetMET();

  vector<TLorentzVector> Jets;
  m_Nbjet = GetJets(Jets,40.,2.8);

  vector<TLorentzVector> LargeRJets;
  m_Ntop = GetLargeRJets(LargeRJets, 300., 2.0);

  // need two jets to play
  if(Jets.size() < 2)
    return;

  LAB->ClearEvent();

  vector<RFKey> jetID;
  for(int i = 0; i < int(Jets.size()); i++){
    jetID.push_back(VIS->AddLabFrameFourVector(Jets[i]));
  }
  INV->SetLabFrameThreeVector(ETMiss);
  if(!LAB->AnalyzeEvent()) cout << "Something went wrong..." << endl;

  m_NJet = Jets.size();
  m_NJ1a = VIS->GetNElementsInFrame(*V1a);
  m_NJ1b = VIS->GetNElementsInFrame(*V1b);
  m_NJ2a = VIS->GetNElementsInFrame(*V2a);
  m_NJ2b = VIS->GetNElementsInFrame(*V2b);
  m_NJa = m_NJ1a+m_NJ2a;
  m_NJb = m_NJ1b+m_NJ2b;

  if(ETMiss.Mag() < 100.)
    return;

  LAB_bkg->ClearEvent();
  double HT = 0.;
  vector<RFKey> jetID_bkg;
  for(int i = 0; i < int(Jets.size()); i++){
    Jets[i].SetPtEtaPhiM(Jets[i].Pt(),0.0,Jets[i].Phi(),Jets[i].M());
    jetID_bkg.push_back(VIS_bkg->AddLabFrameFourVector(Jets[i]));
    HT += Jets[i].Pt();
  }
  INV_bkg->SetLabFrameThreeVector(ETMiss);
  if(!LAB_bkg->AnalyzeEvent()) cout << "Something went wrong..." << endl;

  // QCD clean-up
  TLorentzVector Psib = I_bkg->GetSiblingFrame().GetFourVector(*LAB_bkg);
  TLorentzVector Pmet = I_bkg->GetFourVector(*LAB_bkg);

  m_Rsib = max(0.,Psib.Vect().Dot(Pmet.Vect().Unit()));
  m_Rsib = m_Rsib / (Pmet.Pt() + m_Rsib);

  TVector3 boostQCD = (Pmet+Psib).BoostVector();
  Psib.Boost(-boostQCD);
  double cosQCD = -1.*Psib.Vect().Unit().Dot(boostQCD.Unit());
  cosQCD = (1.-cosQCD)/2.;
  m_deltaQCD = (cosQCD-m_Rsib)/(cosQCD+m_Rsib);

  // signal variables
  TLorentzVector vP_Va = Pa->GetVisibleFourVector(*Pa);
  TLorentzVector vP_Vb = Pb->GetVisibleFourVector(*Pb);
  m_MP = (vP_Va.M2()-vP_Vb.M2())/(2.*(vP_Va.E()-vP_Vb.E()));

  TLorentzVector vP_V1aPP = V1a->GetFourVector(*PP);
  TLorentzVector vP_V2aPP = V2a->GetFourVector(*PP);
  TLorentzVector vP_V1bPP = V1b->GetFourVector(*PP);
  TLorentzVector vP_V2bPP = V2b->GetFourVector(*PP);
  TLorentzVector vP_IaPP  = Ia->GetFourVector(*PP);
  TLorentzVector vP_IbPP  = Ib->GetFourVector(*PP);

  TLorentzVector vP_V1aPa = V1a->GetFourVector(*Pa);
  TLorentzVector vP_V2aPa = V2a->GetFourVector(*Pa);
  TLorentzVector vP_IaPa  = Ia->GetFourVector(*Pa);
  TLorentzVector vP_V1bPb = V1b->GetFourVector(*Pb);
  TLorentzVector vP_V2bPb = V2b->GetFourVector(*Pb);
  TLorentzVector vP_IbPb  = Ib->GetFourVector(*Pb);

  m_H2PP = (vP_V1aPP + vP_V2aPP + vP_V1bPP + vP_V2bPP).P() + (vP_IaPP+vP_IbPP).P();
  m_H3PP = (vP_V1aPP + vP_V2aPP).P() + (vP_V1bPP + vP_V2bPP).P() + (vP_IaPP + vP_IbPP).P();
  m_H4PP = (vP_V1aPP + vP_V2aPP).P() + (vP_V1bPP + vP_V2bPP).P() + vP_IaPP.P() + vP_IbPP.P();
  m_H6PP = vP_V1aPP.P() + vP_V2aPP.P() + vP_V1bPP.P() + vP_V2bPP.P() + vP_IaPP.P() + vP_IbPP.P();

  m_H2Pa = (vP_V1aPa + vP_V2aPa).P() + vP_IaPa.P();
  m_H2Pb = (vP_V1bPb + vP_V2bPb).P() + vP_IbPb.P();
  m_H3Pa = vP_V1aPa.P() + vP_V2aPa.P() + vP_IaPa.P();
  m_H3Pb = vP_V1bPb.P() + vP_V2bPb.P() + vP_IbPb.P();

  m_H4Pa = 0.;
  m_H4Pb = 0.;
  m_H5Pa = 0.;
  m_H5Pb = 0.;

  if(m_NJ1a > 1){
    m_H4Pa += SAV1a->GetChildFrame(0).GetMomentum(*Pa);
    m_H4Pa += SAV1a->GetChildFrame(1).GetMomentum(*Pa);
    m_H5Pa += m_H4Pa;
  } else {
    m_H4Pa += vP_V1aPa.P();
    m_H5Pa += vP_V1aPa.P();
  }
  if(m_NJ1b > 1){
    m_H4Pb += SAV1b->GetChildFrame(0).GetMomentum(*Pb);
    m_H4Pb += SAV1b->GetChildFrame(1).GetMomentum(*Pb);
    m_H5Pb += m_H4Pb;
  } else {
    m_H4Pb += vP_V1bPb.P();
    m_H5Pb += vP_V1bPb.P();
  }
  m_H4Pa += vP_V2aPa.P();
  m_H4Pb += vP_V2bPb.P();

  if(m_NJ2a > 1){
    m_H5Pa += SAV2a->GetChildFrame(0).GetMomentum(*Pa);
    m_H5Pa += SAV2a->GetChildFrame(1).GetMomentum(*Pa);
  } else {
    m_H5Pa += vP_V2aPa.P();
  }
  if(m_NJ2b > 1){
    m_H5Pb += SAV2b->GetChildFrame(0).GetMomentum(*Pb);
    m_H5Pb += SAV2b->GetChildFrame(1).GetMomentum(*Pb);
  } else {
    m_H5Pb += vP_V2bPb.P();
  }
  m_H4Pa += vP_IaPa.P();
  m_H5Pa += vP_IaPa.P();
  m_H4Pb += vP_IbPb.P();
  m_H5Pb += vP_IbPb.P();

  TLorentzVector vP_IaCa  = Ia->GetFourVector(*Ca);
  TLorentzVector vP_IbCb  = Ib->GetFourVector(*Cb);

  m_H2Ca = 2.*vP_IaCa.P();
  m_H2Cb = 2.*vP_IbCb.P();
  if(m_NJ2a > 1)
    m_H3Ca = vP_IaCa.P()+
      SAV2a->GetChildFrame(0).GetMomentum(*Ca)+
      SAV2a->GetChildFrame(1).GetMomentum(*Ca);
  else
    m_H3Ca = m_H2Ca;

  if(m_NJ2b > 1)
    m_H3Cb = vP_IbCb.P()+
      SAV2b->GetChildFrame(0).GetMomentum(*Cb)+
      SAV2b->GetChildFrame(1).GetMomentum(*Cb);
  else
    m_H3Cb = m_H2Cb;

  double P_P = Pa->GetMomentum(*PP);

  double MPP = 2.*sqrt(P_P*P_P + m_MP*m_MP);
  TVector3 vP_PP = PP->GetFourVector(*LAB).Vect();
  double Pt_PP = vP_PP.Pt();
  double Pz_PP = fabs(vP_PP.Pz());
  m_RPT = Pt_PP / (Pt_PP + MPP/4.);
  m_RPZ = Pz_PP;

  m_PP_VisShape = PP->GetVisibleShape();

  m_gaminvPP = 2.*m_MP/MPP;
  m_MDR = m_PP_VisShape*PP->GetMass();

  m_cosPP = PP->GetCosDecayAngle();
  m_dphiVP = PP->GetDeltaPhiDecayVisible();
  m_dphiPPV = PP->GetDeltaPhiBoostVisible();
  m_cosP = Pa->GetCosDecayAngle(*Ia);

  // gluino hemishpere variables
  m_dphiPCa = Pa->GetDeltaPhiDecayPlanes(*Ca);
  m_dphiPCb = Pb->GetDeltaPhiDecayPlanes(*Cb);

  // inside gluino hemisphere variables
  m_dphiPV1a = Pa->GetDeltaPhiDecayPlanes(*SAV1a);
  m_dphiPV1b = Pb->GetDeltaPhiDecayPlanes(*SAV1b);
  m_cosV1a = SAV1a->GetCosDecayAngle();
  m_cosV1b = SAV1b->GetCosDecayAngle();
  m_dphiCV2a = Ca->GetDeltaPhiDecayPlanes(*SAV2a);
  m_dphiCV2b = Cb->GetDeltaPhiDecayPlanes(*SAV2b);
  m_cosV2a = SAV2a->GetCosDecayAngle();
  m_cosV2b = SAV2b->GetCosDecayAngle();

  m_MET = ETMiss.Pt();
  m_Meff = HT+m_MET;
  m_Aplan = 0.;
  m_dphi =  DeltaPhiMin(Jets, ETMiss, 3);
  m_dphiR = DeltaPhiMin(Jets, ETMiss);

  m_pT_jet1 = Jets[0].Pt();
  m_pT_jet2 = Jets[1].Pt();
  if(m_NJet >= 3)
    m_pT_jet3 = Jets[2].Pt();
  else
    m_pT_jet3 = 0.;
  if(m_NJet >= 3)
    m_pT_jet4 = Jets[3].Pt();
  else
    m_pT_jet4 = 0.;
  if(m_NJet >= 3)
    m_pT_jet5 = Jets[4].Pt();
  else
    m_pT_jet5 = 0.;
  if(m_NJet >= 3)
    m_pT_jet6 = Jets[5].Pt();
  else
    m_pT_jet6 = 0.;

  m_pT_jet1a = 0.;
  m_pT_jet2a = 0.;
  m_pT_jet1b = 0.;
  m_pT_jet2b = 0.;

  int N = jetID.size();
  for(int j = 0; j < N; j++){
    RestFrame const& frame = VIS->GetFrame(jetID[j]);
    double pT = VIS->GetLabFrameFourVector(jetID[j]).Pt();

    if(V1a->IsSame(frame) || V2a->IsSame(frame)){
      if(pT > m_pT_jet1a){
	m_pT_jet2a = m_pT_jet1a;
	m_pT_jet1a = pT;
      } else {
	if(pT > m_pT_jet2a) m_pT_jet2a = pT;
      }
    }
    if(V1b->IsSame(frame) || V2b->IsSame(frame)){
      if(pT > m_pT_jet1b){
	m_pT_jet2b = m_pT_jet1b;
	m_pT_jet1b = pT;
      } else {
	if(pT > m_pT_jet2b) m_pT_jet2b = pT;
      }
    }
  }

  m_weight = GetEventWeight();
  // m_veto = NTVars_veto;
  // m_cleaning = NTVars_cleaning;
  // m_timing = NTVars_timing;

  // if(m_CRWT){
  //   m_MTW = NTCRWTVars_mt;
  //   m_lept1Pt = NTCRWTVars_lep1Pt;
  //   m_lep1sign = NTCRWTVars_lep1sign;
  // }

  // if(m_CRZ){
  //   m_Mll = NTCRZVars_mll;
  //   m_lept1Pt = NTCRZVars_lep1Pt;
  //   m_lep1sign = NTCRZVars_lep1sign;
  //   m_lept2Pt = NTCRZVars_lep2Pt;
  //   m_lep2sign = NTCRZVars_lep2sign;
  // }

  if(m_Tree)
    m_Tree->Fill();
}
