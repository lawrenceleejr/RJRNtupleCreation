#include "RJWorkshopNtuple.hh"

using namespace RestFrames;



RJWorkshopNtuple::RJWorkshopNtuple(TTree* tree)
  : NtupleBase<ZeroLeptonBase>(tree)
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

  // bkg tree
  LAB_bkg = new LabRecoFrame("LAB_bkg","lab");
  S_bkg   = new SelfAssemblingRecoFrame("CM_bkg","CM");
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

  // ISR tree
  LAB_ISR = new LabRecoFrame("LAB_ISR","lab");
  CM_ISR = new DecayRecoFrame("CM_ISR","CM");
  S_ISR = new DecayRecoFrame("S_ISR","S");
  ISR_ISR = new VisibleRecoFrame("ISR_ISR","ISR");
  V_ISR = new VisibleRecoFrame("V_ISR","Vis");
  I_ISR = new InvisibleRecoFrame("I_ISR","Inv");

  LAB_ISR->SetChildFrame(*CM_ISR);
  CM_ISR->AddChildFrame(*ISR_ISR);
  CM_ISR->AddChildFrame(*S_ISR);
  S_ISR->AddChildFrame(*V_ISR);
  S_ISR->AddChildFrame(*I_ISR);

  LAB_ISR->InitializeTree();

  INV_ISR = new InvisibleGroup("INV_ISR","Invisible System");
  INV_ISR->AddFrame(*I_ISR);

  VIS_ISR = new CombinatoricGroup("VIS_ISR","Visible Objects");
  VIS_ISR->AddFrame(*ISR_ISR);
  VIS_ISR->SetNElementsForFrame(*ISR_ISR,1,false);
  VIS_ISR->AddFrame(*V_ISR);
  VIS_ISR->SetNElementsForFrame(*V_ISR,0,false);

  InvMass_ISR = new SetMassInvJigsaw("InvMass_ISR", "Invisible system mass Jigsaw");
  INV_ISR->AddJigsaw(*InvMass_ISR);

  SplitVis_ISR = new MinMassesCombJigsaw("SplitVis_ISR","Minimize M_{ISR} and M_{S} Jigsaw");
  VIS_ISR->AddJigsaw(*SplitVis_ISR);
  // "0" group (ISR)
  SplitVis_ISR->AddFrame(*ISR_ISR, 0);
  // "1" group (V + I)
  SplitVis_ISR->AddFrame(*V_ISR,1);
  SplitVis_ISR->AddFrame(*I_ISR,1);

  LAB_ISR->InitializeAnalysis();
  
}

RJWorkshopNtuple::~RJWorkshopNtuple() {
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

  delete LAB_ISR;
  delete CM_ISR;
  delete S_ISR;
  delete ISR_ISR;
  delete V_ISR;
  delete I_ISR;

  delete INV_ISR;
  delete VIS_ISR;

  delete InvMass_ISR;
  delete SplitVis_ISR;
}

void RJWorkshopNtuple::InitOutputTree(){
  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  if(name.find("_CRWT") != string::npos ||
     name.find("_VRWT") != string::npos)
    m_CRWT = true;
  else 
    m_CRWT = false;

  if( name.find("_CRZ") != string::npos)
    m_CRZ = true;
  else 
    m_CRZ = false;

  if( name.find("_CRY") != string::npos)
    m_CRY = true;
  else 
    m_CRY = false;

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
    m_Tree->Branch("leptonWeight", &m_leptonWeight);
  }

  if(m_CRY){
    m_Tree->Branch("phSignal", &m_phSignal);
    m_Tree->Branch("phPt", &m_phPt);
    m_Tree->Branch("phTruthOrigin", &m_phTruthOrigin);
    m_Tree->Branch("phTopoetcone40", &m_phTopoetcone40);
    m_Tree->Branch("phPtcone20", &m_phPtcone20);
    m_Tree->Branch("phTight", &m_phTight);
   }
 
  m_Tree->Branch("weight", &m_weight);
  m_Tree->Branch("veto", &m_veto);
  m_Tree->Branch("cleaning", &m_cleaning);
  m_Tree->Branch("timing", &m_timing);

  m_Tree->Branch("RunNumber", &m_RunNumber);
  m_Tree->Branch("EventNumber", &m_EventNumber);
  m_Tree->Branch("LumiBlockNumber", &m_LumiBlockNumber);
  m_Tree->Branch("nBJet", &m_nBJet);
  m_Tree->Branch("nCJet", &m_nCJet);
  m_Tree->Branch("bTagWeight", &m_bTagWeight);
  m_Tree->Branch("m_jet1_eta", &m_jet1_eta);
  m_Tree->Branch("m_jet1_chf", &m_jet1_chf);
  m_Tree->Branch("m_jet1_FracSamplingMax", &m_jet1_FracSamplingMax);

  // QCD type A
  m_Tree->Branch("Rsib", &m_Rsib);
  m_Tree->Branch("deltaQCD", &m_deltaQCD);

  m_Tree->Branch("pTCM", &m_pTCM);
  m_Tree->Branch("pZCM", &m_pZCM);

  // trigger
  m_Tree->Branch("PP_VisShape", &m_PP_VisShape);
  m_Tree->Branch("MDR", &m_MDR);

  m_Tree->Branch("H2PP", &m_H2PP);

  // compressed 
  m_Tree->Branch("PTISR", &m_PTISR);
  m_Tree->Branch("RISR", &m_RISR);
  m_Tree->Branch("cosS", &m_cosS);
  m_Tree->Branch("dphiCMI", &m_dphiCMI);
  m_Tree->Branch("dphiISRI", &m_dphiISRI);
  m_Tree->Branch("MS", &m_MS);
  m_Tree->Branch("NV", &m_NV);
  m_Tree->Branch("NISR", &m_NISR);
  m_Tree->Branch("MISR", &m_MISR);
  m_Tree->Branch("MV", &m_MV);
  m_Tree->Branch("pTjV1", &m_pTjV1);
  m_Tree->Branch("pTjV2", &m_pTjV2);
  m_Tree->Branch("pTjV3", &m_pTjV3);
  m_Tree->Branch("pTjV4", &m_pTjV4);
  m_Tree->Branch("RPT_PTISR", &m_RPT_PTISR);

  m_Tree->Branch("cosPP", &m_cosPP);
  m_Tree->Branch("dphiVP", &m_dphiVP);
  m_Tree->Branch("dphiPPV", &m_dphiPPV);
  m_Tree->Branch("cosP", &m_cosP);
  m_Tree->Branch("sangle", &m_sangle);
  m_Tree->Branch("dangle", &m_dangle);
  m_Tree->Branch("dphiPa", &m_dphiPa);
  m_Tree->Branch("dphiPb", &m_dphiPb);
  m_Tree->Branch("ddphiP", &m_ddphiP);
  m_Tree->Branch("sdphiP", &m_sdphiP);

  // squark-direct specific
  m_Tree->Branch("H3PP", &m_H3PP);
  m_Tree->Branch("H4PP", &m_H4PP);
  m_Tree->Branch("HT3PP", &m_HT3PP);
  m_Tree->Branch("HT4PP", &m_HT4PP);
  m_Tree->Branch("R_H2PP_H3PP", &m_R_H2PP_H3PP);
  m_Tree->Branch("R_pTj2_HT3PP", &m_R_pTj2_HT3PP);
  m_Tree->Branch("RPZ_HT3PP", &m_RPZ_HT3PP);
  m_Tree->Branch("RPT_HT3PP", &m_RPT_HT3PP);

  // gluino-direct specific
  m_Tree->Branch("H5PP", &m_H5PP);
  m_Tree->Branch("H6PP", &m_H6PP);
  m_Tree->Branch("HT5PP", &m_HT5PP);
  m_Tree->Branch("HT6PP", &m_HT6PP);
  m_Tree->Branch("R_H2PP_H5PP", &m_R_H2PP_H5PP);
  m_Tree->Branch("R_HT5PP_H5PP", &m_R_HT5PP_H5PP);
  m_Tree->Branch("minR_pTj2i_HT3PPi", &m_minR_pTj2i_HT3PPi);
  m_Tree->Branch("maxR_H1PPi_H2PPi", &m_maxR_H1PPi_H2PPi);
  m_Tree->Branch("RPZ_HT5PP", &m_RPZ_HT5PP);
  m_Tree->Branch("RPT_HT5PP", &m_RPT_HT5PP);

  // GG onestep CC specific
  m_Tree->Branch("H9PP", &m_H9PP);
  m_Tree->Branch("H10PP", &m_H10PP);
  m_Tree->Branch("HT9PP", &m_HT9PP);
  m_Tree->Branch("HT10PP", &m_HT10PP);
  m_Tree->Branch("R_H2PP_H9PP", &m_R_H2PP_H9PP);
  m_Tree->Branch("R_HT9PP_H9PP", &m_R_HT9PP_H9PP);
  m_Tree->Branch("RPZ_HT9PP", &m_RPZ_HT9PP);
  m_Tree->Branch("RPT_HT9PP", &m_RPT_HT9PP);

  // P -frames 
  m_Tree->Branch("H2Pa", &m_H2Pa);
  m_Tree->Branch("H2Pb", &m_H2Pb);
  m_Tree->Branch("H3Pa", &m_H3Pa);
  m_Tree->Branch("H3Pb", &m_H3Pb);
  m_Tree->Branch("H4Pa", &m_H4Pa);
  m_Tree->Branch("H4Pb", &m_H4Pb);
  m_Tree->Branch("H5Pa", &m_H5Pa);
  m_Tree->Branch("H5Pb", &m_H5Pb);
  m_Tree->Branch("dH2o3P", &m_dH2o3P);

  // C -frames
  m_Tree->Branch("H2Ca", &m_H2Ca);
  m_Tree->Branch("H2Cb", &m_H2Cb);
  m_Tree->Branch("H3Ca", &m_H3Ca);
  m_Tree->Branch("H3Cb", &m_H3Cb);

  m_Tree->Branch("dphiPV1a", &m_dphiPV1a);
  m_Tree->Branch("dphiPV1b", &m_dphiPV1b);
  m_Tree->Branch("cosV1a", &m_cosV1a);
  m_Tree->Branch("cosV1b", &m_cosV1b);
  m_Tree->Branch("dphiCV2a", &m_dphiCV2a);
  m_Tree->Branch("dphiCV2b", &m_dphiCV2b);
  m_Tree->Branch("cosV2a", &m_cosV2a);
  m_Tree->Branch("cosV2b", &m_cosV2b);

  // other
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

  m_Tree->Branch("pT_jet1", &m_pT_jet1);
  m_Tree->Branch("pT_jet2", &m_pT_jet2);
  m_Tree->Branch("pT_jet3", &m_pT_jet3);
  m_Tree->Branch("pT_jet4", &m_pT_jet4);
  m_Tree->Branch("pT_jet5", &m_pT_jet5);
  m_Tree->Branch("pT_jet6", &m_pT_jet6);

  m_Tree->Branch("pTPP_jet1", &m_pTPP_jet1);
  m_Tree->Branch("pTPP_jet2", &m_pTPP_jet2);

  m_Tree->Branch("pT_jet1a", &m_pT_jet1a);
  m_Tree->Branch("pT_jet2a", &m_pT_jet2a);
  m_Tree->Branch("pT_jet1b", &m_pT_jet1b);
  m_Tree->Branch("pT_jet2b", &m_pT_jet2b);

  m_Tree->Branch("pTPP_jet1a", &m_pTPP_jet1a);
  m_Tree->Branch("pTPP_jet2a", &m_pTPP_jet2a);
  m_Tree->Branch("pTPP_jet3a", &m_pTPP_jet3a);
  m_Tree->Branch("pTPP_jet1b", &m_pTPP_jet1b);
  m_Tree->Branch("pTPP_jet2b", &m_pTPP_jet2b);
  m_Tree->Branch("pTPP_jet3b", &m_pTPP_jet3b);

  m_Tree->Branch("pPP_jet1a", &m_pPP_jet1a);
  m_Tree->Branch("pPP_jet2a", &m_pPP_jet2a);
  m_Tree->Branch("pPP_jet3a", &m_pPP_jet3a);
  m_Tree->Branch("pPP_jet1b", &m_pPP_jet1b);
  m_Tree->Branch("pPP_jet2b", &m_pPP_jet2b);
  m_Tree->Branch("pPP_jet3b", &m_pPP_jet3b);

  m_Tree->Branch("pTPP_Va", &m_pTPP_Va);
  m_Tree->Branch("pTPP_V1a", &m_pTPP_V1a);
  m_Tree->Branch("pTPP_V2a", &m_pTPP_V2a);
  m_Tree->Branch("pTPP_Vb", &m_pTPP_Vb);
  m_Tree->Branch("pTPP_V1b", &m_pTPP_V1b);
  m_Tree->Branch("pTPP_V2b", &m_pTPP_V2b);
  m_Tree->Branch("pTPP_Ia", &m_pTPP_Ia);
  m_Tree->Branch("pTPP_Ib", &m_pTPP_Ib);

  m_Tree->Branch("pPP_Va", &m_pPP_Va);
  m_Tree->Branch("pPP_V1a", &m_pPP_V1a);
  m_Tree->Branch("pPP_V2a", &m_pPP_V2a);
  m_Tree->Branch("pPP_Vb", &m_pPP_Vb);
  m_Tree->Branch("pPP_V1b", &m_pPP_V1b);
  m_Tree->Branch("pPP_V2b", &m_pPP_V2b);
  m_Tree->Branch("pPP_Ia", &m_pPP_Ia);
  m_Tree->Branch("pPP_Ib", &m_pPP_Ib);

}

void RJWorkshopNtuple::FillOutputTree(){

  TVector3 ETMiss = GetMET(); 

  vector<TLorentzVector> Jets; 
  GetJets(Jets, 40., 2.8); 

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

  if(ETMiss.Mag() < 100. || m_NJet < 2)
    return;

  // background tree
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

  TLorentzVector Psib = I_bkg->GetSiblingFrame().GetFourVector(*LAB_bkg);
  TLorentzVector Pmet = I_bkg->GetFourVector(*LAB_bkg);
  
  m_Rsib = max(0.,Psib.Vect().Dot(Pmet.Vect().Unit()));
  m_Rsib = m_Rsib / (Pmet.Pt() + m_Rsib);
  
  TVector3 boostQCD = (Pmet+Psib).BoostVector();
  Psib.Boost(-boostQCD);
  double cosQCD = -1.*Psib.Vect().Unit().Dot(boostQCD.Unit());
  cosQCD = (1.-cosQCD)/2.;
  m_deltaQCD = (cosQCD-m_Rsib)/(cosQCD+m_Rsib);    
 
  // compressed tree
  LAB_ISR->ClearEvent();
  vector<RFKey> jetID_ISR; 
  for(int i = 0; i < int(Jets.size()); i++){
    Jets[i].SetPtEtaPhiM(Jets[i].Pt(),0.0,Jets[i].Phi(),Jets[i].M());
    jetID_ISR.push_back(VIS_ISR->AddLabFrameFourVector(Jets[i]));
  }
  INV_ISR->SetLabFrameThreeVector(ETMiss);
  if(!LAB_ISR->AnalyzeEvent()) cout << "Something went wrong..." << endl;
 
  m_NV = VIS_ISR->GetNElementsInFrame(*V_ISR);
  m_NISR = VIS_ISR->GetNElementsInFrame(*ISR_ISR);

  if(m_NV < 1){
    m_PTISR = 0.;
    m_RISR = 0.;
    m_cosS = 0.;
    m_dphiCMI = 0.;
    m_dphiISRI = 0.;
    m_MS = 0.;
    m_MV = 0.;
    m_MISR = 0.;
    m_pTjV1 = 0.;
    m_pTjV2 = 0.;
    m_pTjV3 = 0.;
    m_pTjV4 = 0.;
    m_RPT_PTISR = 0.;
  } else {

    TVector3 vP_ISR = ISR_ISR->GetFourVector(*CM_ISR).Vect();
    TVector3 vP_I   = I_ISR->GetFourVector(*CM_ISR).Vect();

    m_PTISR = vP_ISR.Mag();
    m_MS    = S_ISR->GetMass();
    m_MV    = V_ISR->GetMass();
    m_MISR  = ISR_ISR->GetMass();

    if(m_PTISR > 0.)
      m_RISR = fabs(vP_I.Dot(vP_ISR.Unit())) / m_PTISR;
    else
      m_RISR = 0.;
   
    m_cosS  = S_ISR->GetCosDecayAngle();
    m_dphiCMI  = CM_ISR->GetDeltaPhiBoostVisible();
    m_dphiISRI = fabs(vP_ISR.DeltaPhi(vP_I));

    TLorentzVector PCM = CM_ISR->GetFourVector();
    m_RPT_PTISR = PCM.Pt() / ( PCM.Pt() + m_PTISR );

    int iN = 0;
    m_pTjV1 = 0.;
    m_pTjV2 = 0.;
    m_pTjV3 = 0.;
    m_pTjV4 = 0.;
    for(int i = 0; i < int(Jets.size()); i++){
      if(VIS_ISR->GetFrame(jetID_ISR[i]) == *V_ISR){
	if(iN == 0)
	  m_pTjV1 = Jets[i].Pt();
	if(iN == 1)
	  m_pTjV2 = Jets[i].Pt();
	if(iN == 2)
	  m_pTjV3 = Jets[i].Pt();
	if(iN == 3)
	  m_pTjV4 = Jets[i].Pt();
	iN++;
      }
    }
  }

  // signal variables
  TLorentzVector vP_Va = Pa->GetVisibleFourVector(*Pa);
  TLorentzVector vP_Vb = Pb->GetVisibleFourVector(*Pb);
  
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
  m_H5PP = vP_V1aPP.P() + vP_V2aPP.P() + vP_V1bPP.P() + vP_V2bPP.P() + (vP_IaPP + vP_IbPP).P();
  m_H6PP = vP_V1aPP.P() + vP_V2aPP.P() + vP_V1bPP.P() + vP_V2bPP.P() + vP_IaPP.P() + vP_IbPP.P();

  m_H9PP  = 0.;
  m_H10PP = 0.;

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
    m_H9PP += SAV1a->GetChildFrame(0).GetMomentum(*PP);
    m_H9PP += SAV1a->GetChildFrame(1).GetMomentum(*PP);
  } else {
    m_H4Pa += vP_V1aPa.P();
    m_H5Pa += vP_V1aPa.P();
    m_H9PP += vP_V1aPP.P();
  }
  if(m_NJ1b > 1){
    m_H4Pb += SAV1b->GetChildFrame(0).GetMomentum(*Pb);
    m_H4Pb += SAV1b->GetChildFrame(1).GetMomentum(*Pb);
    m_H5Pb += m_H4Pb;
    m_H9PP += SAV1b->GetChildFrame(0).GetMomentum(*PP);
    m_H9PP += SAV1b->GetChildFrame(1).GetMomentum(*PP);
  } else {
    m_H4Pb += vP_V1bPb.P();
    m_H5Pb += vP_V1bPb.P();
    m_H9PP += vP_V1bPP.P();
  }
  m_H4Pa += vP_V2aPa.P();
  m_H4Pb += vP_V2bPb.P();
  
  if(m_NJ2a > 1){
    m_H5Pa += SAV2a->GetChildFrame(0).GetMomentum(*Pa);
    m_H5Pa += SAV2a->GetChildFrame(1).GetMomentum(*Pa);
    m_H9PP += SAV2a->GetChildFrame(0).GetMomentum(*PP);
    m_H9PP += SAV2a->GetChildFrame(1).GetMomentum(*PP);
  } else {
    m_H5Pa += vP_V2aPa.P();
    m_H9PP += vP_V2aPP.P();
  }
  if(m_NJ2b > 1){
    m_H5Pb += SAV2b->GetChildFrame(0).GetMomentum(*Pb);
    m_H5Pb += SAV2b->GetChildFrame(1).GetMomentum(*Pb);
    m_H9PP += SAV2b->GetChildFrame(0).GetMomentum(*PP);
    m_H9PP += SAV2b->GetChildFrame(1).GetMomentum(*PP);
  } else {
    m_H5Pb += vP_V2bPb.P();
    m_H9PP += vP_V2bPP.P();
  }
  m_H4Pa += vP_IaPa.P();
  m_H5Pa += vP_IaPa.P();
  m_H4Pb += vP_IbPb.P();
  m_H5Pb += vP_IbPb.P();

  m_H10PP = m_H9PP;

  m_H9PP  += (vP_IaPP + vP_IbPP).P();
  m_H10PP += vP_IaPP.P() + vP_IbPP.P();

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

  TVector3 vP_PP = PP->GetFourVector(*LAB).Vect();
  
  m_PP_VisShape = PP->GetVisibleShape();
  m_MDR = m_PP_VisShape*PP->GetMass();
 
  
  m_cosPP = PP->GetCosDecayAngle();
  m_dphiVP = PP->GetDeltaPhiDecayVisible();
  m_dphiPPV = PP->GetDeltaPhiBoostVisible();
  m_cosP = Pa->GetCosDecayAngle(*Ia);
  m_dphiVP = (m_dphiVP-acos(-1.)/2.)/(acos(-1.)/2.);

  m_sangle = fabs(m_dphiVP + 2.*m_cosP)/3.;
  m_dangle = (2.*m_dphiVP - m_cosP)/3.;

  // gluino hemishpere variables
  m_dphiPa = Pa->GetDeltaPhiDecayPlanes(*Ca);
  m_dphiPb = Pb->GetDeltaPhiDecayPlanes(*Cb);

  double dphiA = m_dphiPa;
  double dphiB = m_dphiPb;
  if(dphiA > acos(-1.))
    dphiA = 2.*acos(-1.) - dphiA;
  if(dphiB > acos(-1.))
    dphiB = 2.*acos(-1.) - dphiB;
  m_ddphiP = (dphiA-dphiB)/acos(-1.);
  m_sdphiP = fabs(dphiA+dphiB)/2./acos(-1.);

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
  m_Meff = NTVars_meffInc;
  m_Aplan = NTExtraVars_Ap;
  m_dphi = NTVars_dPhi;
  m_dphiR = NTVars_dPhiR;

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

  m_pTPP_Va  = PP->GetTransverseMomentum(V1a->GetFourVector()+V2a->GetFourVector());
  m_pTPP_V1a = V1a->GetTransverseMomentum(*PP);
  m_pTPP_V2a = V2a->GetTransverseMomentum(*PP);
  m_pTPP_Vb  = PP->GetTransverseMomentum(V1b->GetFourVector()+V2b->GetFourVector());
  m_pTPP_V1b = V1b->GetTransverseMomentum(*PP);
  m_pTPP_V2b = V2b->GetTransverseMomentum(*PP);
  m_pTPP_Ia = Ia->GetTransverseMomentum(*PP);
  m_pTPP_Ib = Ib->GetTransverseMomentum(*PP);
  
  m_pPP_Va  = (V1a->GetFourVector(*PP)+V2a->GetFourVector(*PP)).P();
  m_pPP_V1a = V1a->GetMomentum(*PP);
  m_pPP_V2a = V2a->GetMomentum(*PP);
  m_pPP_Vb  = (V1b->GetFourVector(*PP)+V2b->GetFourVector(*PP)).P();
  m_pPP_V1b = V1b->GetMomentum(*PP);
  m_pPP_V2b = V2b->GetMomentum(*PP);
  m_pPP_Ia = Ia->GetMomentum(*PP);
  m_pPP_Ib = Ib->GetMomentum(*PP);

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
	if(pT > m_pT_jet2a){
	  m_pT_jet2a = pT;
	} 
      }
    }
    if(V1b->IsSame(frame) || V2b->IsSame(frame)){
      if(pT > m_pT_jet1b){
	m_pT_jet2b = m_pT_jet1b;
	m_pT_jet1b = pT;
      } else {
	if(pT > m_pT_jet2b){
	  m_pT_jet2b = pT;
	} 
      }
    }
  }

  m_pTPP_jet1a = 0.;
  m_pTPP_jet2a = 0.;
  m_pTPP_jet3a = 0.;
  m_pTPP_jet1b = 0.;
  m_pTPP_jet2b = 0.;
  m_pTPP_jet3b = 0.;

  for(int j = 0; j < N; j++){
    RestFrame const& frame = VIS->GetFrame(jetID[j]);
    double pT = PP->GetTransverseMomentum(VIS->GetLabFrameFourVector(jetID[j]));
    double p  = PP->GetFourVector(VIS->GetLabFrameFourVector(jetID[j])).P();

    if(V1a->IsSame(frame) || V2a->IsSame(frame)){
      if(pT > m_pTPP_jet1a){
	m_pTPP_jet3a = m_pTPP_jet2a;
	m_pPP_jet3a  = m_pPP_jet2a;
	m_pTPP_jet2a = m_pTPP_jet1a;
	m_pPP_jet2a  = m_pPP_jet1a;
	m_pTPP_jet1a = pT;
	m_pPP_jet1a  = p;
      } else {
	if(pT > m_pTPP_jet2a){
	  m_pTPP_jet3a = m_pTPP_jet2a;
	  m_pPP_jet3a  = m_pPP_jet2a;
	  m_pTPP_jet2a = pT;
	  m_pPP_jet2a  = p;
	} else{
	  if(pT > m_pTPP_jet3a){
	    m_pTPP_jet3a = pT;
	    m_pPP_jet3a  = p;
	  } 
	}
      }
    }
    if(V1b->IsSame(frame) || V2b->IsSame(frame)){
      if(pT > m_pTPP_jet1b){
	m_pTPP_jet3b = m_pTPP_jet2b;
	m_pPP_jet3b  = m_pPP_jet2b;
	m_pTPP_jet2b = m_pTPP_jet1b;
	m_pPP_jet2b  = m_pPP_jet1b;
	m_pTPP_jet1b = pT;
	m_pPP_jet1b  = p;
      } else {
	if(pT > m_pTPP_jet2b){
	  m_pTPP_jet3b = m_pTPP_jet2b;
	  m_pPP_jet3b  = m_pPP_jet2b;
	  m_pTPP_jet2b = pT;
	  m_pPP_jet2b  = p;
	} else{
	  if(pT > m_pTPP_jet3b){
	    m_pTPP_jet3b = pT;
	    m_pPP_jet3b  = p;
	  } 
	}
      }
    }
  }

  if(m_pTPP_jet1a > m_pTPP_jet1b){
    m_pTPP_jet1 = m_pTPP_jet1a;
    m_pTPP_jet2 = max(m_pTPP_jet1b,m_pTPP_jet2a);
  } else {
    m_pTPP_jet1 = m_pTPP_jet1b;
    m_pTPP_jet2 = max(m_pTPP_jet1a,m_pTPP_jet2b);
  }

  m_HT3PP = m_pTPP_Va + m_pTPP_Vb +
            m_H2PP/2.;
  m_HT4PP = m_pTPP_Va + m_pTPP_Vb +
            m_pTPP_Ia + m_pTPP_Ib;
  m_HT5PP = m_pTPP_V1a + m_pTPP_V1b +
            m_pTPP_V2a + m_pTPP_V2b +
            m_H2PP/2.;
  m_HT6PP = m_pTPP_V1a + m_pTPP_V1b +
            m_pTPP_V2a + m_pTPP_V2b +
            m_pTPP_Ia + m_pTPP_Ib;

  m_HT9PP = 0;
  if(m_NJ1a > 1){
    m_HT9PP += SAV1a->GetChildFrame(0).GetTransverseMomentum(*PP);
    m_HT9PP += SAV1a->GetChildFrame(1).GetTransverseMomentum(*PP);
  } else {
    m_HT9PP += m_pTPP_V1a;
  }
  if(m_NJ1b > 1){
    m_HT9PP += SAV1b->GetChildFrame(0).GetTransverseMomentum(*PP);
    m_HT9PP += SAV1b->GetChildFrame(1).GetTransverseMomentum(*PP);
  } else {
    m_HT9PP += m_pTPP_V1b;
  }
  if(m_NJ2a > 1){
    m_HT9PP += SAV2a->GetChildFrame(0).GetTransverseMomentum(*PP);
    m_HT9PP += SAV2a->GetChildFrame(1).GetTransverseMomentum(*PP);
  } else {
    m_HT9PP += m_pTPP_V2a;
  }
  if(m_NJ2b > 1){
    m_HT9PP += SAV2b->GetChildFrame(0).GetTransverseMomentum(*PP);
    m_HT9PP += SAV2b->GetChildFrame(1).GetTransverseMomentum(*PP);
  } else {
    m_HT9PP += m_pTPP_V2b;
  }

  m_HT10PP = m_HT9PP;
  m_HT9PP  += m_H2PP/2.;
  m_HT10PP += m_pTPP_Ia + m_pTPP_Ib;

  /// squark ratios
  m_R_H2PP_H3PP = m_H2PP/m_H3PP;
  m_R_pTj2_HT3PP = m_pTPP_jet2 / m_HT3PP;

  /// gluino ratios
  m_R_HT5PP_H5PP = m_HT5PP/m_H5PP;
  m_R_H2PP_H5PP = m_H2PP/m_H5PP;
  m_minR_pTj2i_HT3PPi = min(m_pTPP_jet2a/(m_pTPP_V1a+m_pTPP_V2a+m_pTPP_Ia),
			    m_pTPP_jet2b/(m_pTPP_V1b+m_pTPP_V2b+m_pTPP_Ib));
  m_maxR_H1PPi_H2PPi = max(m_pPP_Va/(m_pPP_V1a+m_pPP_V2a),m_pPP_Vb/(m_pPP_V1b+m_pPP_V2b));

   /// GG onestep ratios
  m_R_HT9PP_H9PP = m_HT5PP/m_H9PP;
  m_R_H2PP_H9PP = m_H2PP/m_H9PP;

  m_dH2o3P = m_H2Pa/m_H3Pa - m_H2Pb/m_H3Pb;

  m_pTCM = vP_PP.Pt();
  m_pZCM = fabs(vP_PP.Pz());
  
  m_RPZ_HT3PP = m_pZCM / (m_pZCM + m_HT3PP);
  m_RPZ_HT5PP = m_pZCM / (m_pZCM + m_HT5PP);
  m_RPZ_HT9PP = m_pZCM / (m_pZCM + m_HT9PP);
  m_RPT_HT3PP = m_pTCM / (m_pTCM + m_HT3PP);
  m_RPT_HT5PP = m_pTCM / (m_pTCM + m_HT5PP);
  m_RPT_HT9PP = m_pTCM / (m_pTCM + m_HT9PP);

  m_weight = GetEventWeight();
  m_veto = NTVars_veto;
  m_cleaning = NTVars_cleaning;
  m_timing = NTVars_timing;

  m_RunNumber = NTVars_RunNumber; 
  m_EventNumber = NTVars_EventNumber;
  m_LumiBlockNumber = NTVars_LumiBlockNumber;
  m_nBJet = NTVars_nBJet;
  m_nCJet = NTVars_nCJet;
  //m_bTagWeight = NTVars_bTagWeight;
  m_bTagWeight = 1.;
  m_jet1_eta = jetEta->at(0);
  m_jet1_chf= NTVars_jet1Chf;
  m_jet1_FracSamplingMax= jetFracSamplingMax->at(0);

  if(m_CRWT){
    m_MTW = NTCRWTVars_mt;
    m_lept1Pt = NTCRWTVars_lep1Pt;
    m_lep1sign = NTCRWTVars_lep1sign;
  }

  if(m_CRZ){
    m_Mll = NTCRZVars_mll;
    m_lept1Pt = NTCRZVars_lep1Pt;
    m_lep1sign = NTCRZVars_lep1sign;
    m_lept2Pt = NTCRZVars_lep2Pt;
    m_lep2sign = NTCRZVars_lep2sign;
    m_leptonWeight = NTCRZVars_leptonWeight;
  } else{
    if(systWeights->size() > 0)
      m_leptonWeight = systWeights->at(0);
    else
      m_leptonWeight = 1.;
  }

  if(m_CRY){
    m_phSignal = NTCRYVars_phSignal;
    m_phPt = NTCRYVars_phPt;
    m_phTruthOrigin = NTCRYVars_phTruthOrigin;
    m_phTopoetcone40 = NTCRYVars_phTopoetcone40;
    m_phPtcone20 = NTCRYVars_phPtcone20;
    // m_phTight = NTCRYVars_phTight; gone in v107
    m_phTight = 1.;
  }

  if(m_Tree)
    m_Tree->Fill();
}
