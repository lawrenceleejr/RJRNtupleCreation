#include "SunNtuple.hh"

using namespace RestFrames;



SunNtuple::SunNtuple(TTree* tree)
  : NtupleBase<SunBase>(tree)
{
  // RestFrames stuff

  LAB = new LabRecoFrame("LAB","lab");
  CM = new DecayRecoFrame("CM","CM");
  S = new DecayRecoFrame("S","S");
  ISR = new VisibleRecoFrame("ISR","ISR");
  V = new VisibleRecoFrame("V","Vis");
  I = new InvisibleRecoFrame("I","Inv");

  LAB->SetChildFrame(*CM);
  CM->AddChildFrame(*ISR);
  CM->AddChildFrame(*S);
  S->AddChildFrame(*V);
  S->AddChildFrame(*I);

  LAB->InitializeTree(); 

  INV = new InvisibleGroup("INV","Invisible System");
  INV->AddFrame(*I);

  VIS = new CombinatoricGroup("VIS","Visible Objects");
  VIS->AddFrame(*ISR);
  VIS->SetNElementsForFrame(*ISR,1,false);
  VIS->AddFrame(*V);
  VIS->SetNElementsForFrame(*V,0,false);

  // set the invisible system mass to zero
  InvMass = new SetMassInvJigsaw("InvMass", "Invisible system mass Jigsaw");
  INV->AddJigsaw(*InvMass);

  // define the rule for partitioning objects between "ISR" and "V"
  SplitVis = new MinMassesCombJigsaw("SplitVis","Minimize M_{ISR} and M_{S} Jigsaw");
  VIS->AddJigsaw(*SplitVis);
  // "0" group (ISR)
  SplitVis->AddFrame(*ISR, 0);
  // "1" group (V + I)
  SplitVis->AddFrame(*V,1);
  SplitVis->AddFrame(*I,1);

  LAB->InitializeAnalysis(); 
}

SunNtuple::~SunNtuple() {
  delete LAB;
  delete CM;
  delete S;
  delete ISR;
  delete V;
  delete I;

  delete INV;
  delete VIS;

  delete InvMass;
  delete SplitVis;
  
}

void SunNtuple::InitOutputTree(){
  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  name = "CompressedAnalysis";

  m_Tree = (TTree*) new TTree(name.c_str(), name.c_str());
 
  m_Tree->Branch("weight", &m_weight);
  m_Tree->Branch("MET", &m_MET);
  m_Tree->Branch("TrkMET", &m_TrkMET);
  m_Tree->Branch("dphi_MET_TrkMET", &m_dphi_MET_TrkMET);
  m_Tree->Branch("HLT_xe70_tc_lcw", &m_HLT_xe70_tc_lcw);
  m_Tree->Branch("dphiMin1", &m_dphiMin1);
  m_Tree->Branch("dphiMin2", &m_dphiMin2);
  m_Tree->Branch("dphiMin3", &m_dphiMin3);
  m_Tree->Branch("dphiMinAll", &m_dphiMinAll);

  m_Tree->Branch("LepVeto", &m_LepVeto);
  m_Tree->Branch("TauVeto", &m_TauVeto);

  // compressed tree variables
  m_Tree->Branch("PTISR", &m_PTISR);
  m_Tree->Branch("PTCM", &m_PTCM);
  m_Tree->Branch("RISR", &m_RISR);
  m_Tree->Branch("cosS", &m_cosS);
  m_Tree->Branch("MS", &m_MS);
  m_Tree->Branch("MISR", &m_MISR);
  m_Tree->Branch("MV", &m_MV);
  m_Tree->Branch("dphiCMI", &m_dphiCMI);
  m_Tree->Branch("dphiISRI", &m_dphiISRI);
  m_Tree->Branch("pTjV1", &m_pTjV1);
  m_Tree->Branch("pTjV2", &m_pTjV2);
  m_Tree->Branch("pTjV3", &m_pTjV3);
  m_Tree->Branch("pTjV4", &m_pTjV4);
  m_Tree->Branch("pTjV5", &m_pTjV5);
  m_Tree->Branch("pTjV6", &m_pTjV6);
  m_Tree->Branch("pTbV1", &m_pTbV1);
  m_Tree->Branch("pTbV2", &m_pTbV2);
  m_Tree->Branch("NbV", &m_NbV);
  m_Tree->Branch("NbISR", &m_NbISR);
  m_Tree->Branch("NjV", &m_NjV);
  m_Tree->Branch("NjISR", &m_NjISR);

}

void SunNtuple::FillOutputTree(){

  TVector3 ETMiss = GetMET(); 
      
  vector<pair<TLorentzVector,bool> > Jets; 
  GetJetsBtag(Jets, 20., 2.8); 

  // need two jets to play
  if(Jets.size() < 2) 
    return; 

  // other observables
  m_MET = ETMiss.Pt();
  m_TrkMET = 100.;
  m_dphi_MET_TrkMET = 0.;
  m_HLT_xe70_tc_lcw = 1;

  m_dphiMin1   = DeltaPhiMin(Jets, ETMiss, 1);
  m_dphiMin2   = DeltaPhiMin(Jets, ETMiss, 2);
  m_dphiMin3   = DeltaPhiMin(Jets, ETMiss, 3);
  m_dphiMinAll = DeltaPhiMin(Jets, ETMiss);

  m_LepVeto = (m_muon_n+m_el_n < 1);
  m_TauVeto = 1.;
  m_weight = GetEventWeight();

  // analyze event in RestFrames tree
  LAB->ClearEvent();
  vector<RFKey> jetID; 
  for(int i = 0; i < int(Jets.size()); i++){
    TLorentzVector jet = Jets[i].first;
    // transverse view of jet 4-vectors
    jet.SetPtEtaPhiM(jet.Pt(),0.0,jet.Phi(),jet.M());
    jetID.push_back(VIS->AddLabFrameFourVector(jet));
  }
  INV->SetLabFrameThreeVector(ETMiss);
  if(!LAB->AnalyzeEvent()) cout << "Something went wrong..." << endl;
 
  // Compressed variables from tree
  m_NjV = 0;
  m_NbV = 0;
  m_NjISR = 0;
  m_NbISR = 0;
  m_pTjV1 = 0.;
  m_pTjV2 = 0.;
  m_pTjV3 = 0.;
  m_pTjV4 = 0.;
  m_pTjV5 = 0.;
  m_pTjV6 = 0.;
  m_pTbV1 = 0.;
  m_pTbV2 = 0.;
  for(int i = 0; i < int(Jets.size()); i++){
    if(VIS->GetFrame(jetID[i]) == *V){ // sparticle group
      m_NjV++;
      if(m_NjV == 1)
	m_pTjV1 = Jets[i].first.Pt();
      if(m_NjV == 2)
	m_pTjV2 = Jets[i].first.Pt();
      if(m_NjV == 3)
	m_pTjV3 = Jets[i].first.Pt();
      if(m_NjV == 4)
	m_pTjV4 = Jets[i].first.Pt();
      if(m_NjV == 5)
	m_pTjV5 = Jets[i].first.Pt();
      if(m_NjV == 6)
	m_pTjV6 = Jets[i].first.Pt();
      if(Jets[i].second){
	m_NbV++;
	if(m_NbV == 1)
	  m_pTbV1 = Jets[i].first.Pt();
	if(m_NbV == 2)
	  m_pTbV2 = Jets[i].first.Pt();
      }
    } else {
      m_NjISR++;
      if(Jets[i].second)
	m_NbISR++;
    }
  }

  // need at least one jet associated with sparticle-side of event
  if(m_NjV < 1){
    m_PTISR = 0.;
    m_PTCM = 0.;
    m_RISR = 0.;
    m_cosS = 0.;
    m_MS = 0.;
    m_MV = 0.;
    m_MISR = 0.;
    m_dphiCMI = 0.;
    m_dphiISRI = 0.;
  } else {

    TVector3 vP_ISR = ISR->GetFourVector(*CM).Vect();
    TVector3 vP_I   = I->GetFourVector(*CM).Vect();
    TVector3 vP_CM   = CM->GetFourVector(*LAB).Vect();
  
    m_PTISR = vP_ISR.Mag();
    m_PTCM  = vP_CM.Pt();
    m_RISR = fabs(vP_I.Dot(vP_ISR.Unit())) / m_PTISR;
    m_cosS = S->GetCosDecayAngle();
    m_MS = S->GetMass();
    m_MV = V->GetMass();
    m_MISR = ISR->GetMass();
    m_dphiCMI = acos(-1.)-fabs(CM->GetDeltaPhiBoostVisible());
    m_dphiISRI = fabs(vP_ISR.DeltaPhi(vP_I));
  }   

  m_MET = ETMiss.Pt();

  m_weight = GetEventWeight();

  if(m_Tree)
    m_Tree->Fill();
}
