//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 15 16:25:43 2015 by ROOT version 5.34/25
// from TTree Top_SRAll/Top_SRAll
// found on file: BKG_v44/Top.root
//////////////////////////////////////////////////////////

#ifndef RJWorkshopBase_h
#define RJWorkshopBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class RJWorkshopBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
  Double_t        weight;
   UInt_t          veto;
   UInt_t          cleaning;
   UInt_t          timing;
   UInt_t          RunNumber;
   Int_t           nBJet;
   Int_t           nCJet;
   Double_t        bTagWeight;
   Double_t        m_jet1_eta;
   Double_t        m_jet1_chf;
   Double_t        m_jet1_FracSamplingMax;
   Double_t        Rsib;
   Double_t        deltaQCD;
   Double_t        pTCM;
   Double_t        pZCM;
   Double_t        PP_VisShape;
   Double_t        MDR;
   Double_t        H2PP;
   Double_t        PTISR;
   Double_t        RISR;
   Double_t        cosS;
   Double_t        dphiCMI;
   Double_t        dphiISRI;
   Double_t        MS;
   Int_t           NV;
   Int_t           NISR;
   Double_t        MISR;
   Double_t        MV;
   Double_t        pTjV1;
   Double_t        pTjV2;
   Double_t        pTjV3;
   Double_t        pTjV4;
   Double_t        RPT_PTISR;
   Bool_t          LepVeto;
   Double_t        cosPP;
   Double_t        dphiVP;
   Double_t        dphiPPV;
   Double_t        cosP;
   Double_t        sangle;
   Double_t        dangle;
   Double_t        dphiPa;
   Double_t        dphiPb;
   Double_t        ddphiP;
   Double_t        sdphiP;
   Double_t        H3PP;
   Double_t        H4PP;
   Double_t        HT3PP;
   Double_t        HT4PP;
   Double_t        R_H2PP_H3PP;
   Double_t        R_pTj2_HT3PP;
   Double_t        RPZ_HT3PP;
   Double_t        RPT_HT3PP;
   Double_t        H5PP;
   Double_t        H6PP;
   Double_t        HT5PP;
   Double_t        HT6PP;
   Double_t        R_H2PP_H5PP;
   Double_t        R_HT5PP_H5PP;
   Double_t        minR_pTj2i_HT3PPi;
   Double_t        maxR_H1PPi_H2PPi;
   Double_t        RPZ_HT5PP;
   Double_t        RPT_HT5PP;
   Double_t        H9PP;
   Double_t        H10PP;
   Double_t        HT9PP;
   Double_t        HT10PP;
   Double_t        R_H2PP_H9PP;
   Double_t        R_HT9PP_H9PP;
   Double_t        RPZ_HT9PP;
   Double_t        RPT_HT9PP;
   Double_t        H2Pa;
   Double_t        H2Pb;
   Double_t        H3Pa;
   Double_t        H3Pb;
   Double_t        H4Pa;
   Double_t        H4Pb;
   Double_t        H5Pa;
   Double_t        H5Pb;
   Double_t        dH2o3P;
   Double_t        H2Ca;
   Double_t        H2Cb;
   Double_t        H3Ca;
   Double_t        H3Cb;
   Double_t        dphiPV1a;
   Double_t        dphiPV1b;
   Double_t        cosV1a;
   Double_t        cosV1b;
   Double_t        dphiCV2a;
   Double_t        dphiCV2b;
   Double_t        cosV2a;
   Double_t        cosV2b;
   Double_t        MET;
   Double_t        Meff;
   Double_t        Aplan;
   Double_t        dphi;
   Double_t        dphiR;
   Double_t        NJet;
   Double_t        NJa;
   Double_t        NJb;
   Double_t        NJ1a;
   Double_t        NJ1b;
   Double_t        NJ2a;
   Double_t        NJ2b;
   Double_t        pT_jet1;
   Double_t        pT_jet2;
   Double_t        pT_jet3;
   Double_t        pT_jet4;
   Double_t        pT_jet5;
   Double_t        pT_jet6;
   Double_t        pTPP_jet1;
   Double_t        pTPP_jet2;
   Double_t        pT_jet1a;
   Double_t        pT_jet2a;
   Double_t        pT_jet1b;
   Double_t        pT_jet2b;
   Double_t        pTPP_jet1a;
   Double_t        pTPP_jet2a;
   Double_t        pTPP_jet3a;
   Double_t        pTPP_jet1b;
   Double_t        pTPP_jet2b;
   Double_t        pTPP_jet3b;
   Double_t        pPP_jet1a;
   Double_t        pPP_jet2a;
   Double_t        pPP_jet3a;
   Double_t        pPP_jet1b;
   Double_t        pPP_jet2b;
   Double_t        pPP_jet3b;
   Double_t        pTPP_Va;
   Double_t        pTPP_V1a;
   Double_t        pTPP_V2a;
   Double_t        pTPP_Vb;
   Double_t        pTPP_V1b;
   Double_t        pTPP_V2b;
   Double_t        pTPP_Ia;
   Double_t        pTPP_Ib;
   Double_t        pPP_Va;
   Double_t        pPP_V1a;
   Double_t        pPP_V2a;
   Double_t        pPP_Vb;
   Double_t        pPP_V1b;
   Double_t        pPP_V2b;
   Double_t        pPP_Ia;
   Double_t        pPP_Ib;

   // List of branches
    TBranch        *b_weight;   //!
   TBranch        *b_veto;   //!
   TBranch        *b_cleaning;   //!
   TBranch        *b_timing;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_nBJet;   //!
   TBranch        *b_nCJet;   //!
   TBranch        *b_bTagWeight;   //!
   TBranch        *b_m_jet1_eta;   //!
   TBranch        *b_m_jet1_chf;   //!
   TBranch        *b_m_jet1_FracSamplingMax;   //!
   TBranch        *b_Rsib;   //!
   TBranch        *b_deltaQCD;   //!
   TBranch        *b_pTCM;   //!
   TBranch        *b_pZCM;   //!
   TBranch        *b_PP_VisShape;   //!
   TBranch        *b_MDR;   //!
   TBranch        *b_H2PP;   //!
   TBranch        *b_PTISR;   //!
   TBranch        *b_RISR;   //!
   TBranch        *b_cosS;   //!
   TBranch        *b_dphiCMI;   //!
   TBranch        *b_dphiISRI;   //!
   TBranch        *b_MS;   //!
   TBranch        *b_NV;   //!
   TBranch        *b_NISR;   //!
   TBranch        *b_MISR;   //!
   TBranch        *b_MV;   //!
   TBranch        *b_pTjV1;   //!
   TBranch        *b_pTjV2;   //!
   TBranch        *b_pTjV3;   //!
   TBranch        *b_pTjV4;   //!
   TBranch        *b_RPT_PTISR;   //!
   TBranch        *b_LepVeto;   //!
   TBranch        *b_m_MET;   //!
   TBranch        *b_cosPP;   //!
   TBranch        *b_dphiVP;   //!
   TBranch        *b_dphiPPV;   //!
   TBranch        *b_cosP;   //!
   TBranch        *b_sangle;   //!
   TBranch        *b_dangle;   //!
   TBranch        *b_dphiPa;   //!
   TBranch        *b_dphiPb;   //!
   TBranch        *b_ddphiP;   //!
   TBranch        *b_sdphiP;   //!
   TBranch        *b_H3PP;   //!
   TBranch        *b_H4PP;   //!
   TBranch        *b_HT3PP;   //!
   TBranch        *b_HT4PP;   //!
   TBranch        *b_R_H2PP_H3PP;   //!
   TBranch        *b_R_pTj2_HT3PP;   //!
   TBranch        *b_RPZ_HT3PP;   //!
   TBranch        *b_RPT_HT3PP;   //!
   TBranch        *b_H5PP;   //!
   TBranch        *b_H6PP;   //!
   TBranch        *b_HT5PP;   //!
   TBranch        *b_HT6PP;   //!
   TBranch        *b_R_H2PP_H5PP;   //!
   TBranch        *b_R_HT5PP_H5PP;   //!
   TBranch        *b_minR_pTj2i_HT3PPi;   //!
   TBranch        *b_maxR_H1PPi_H2PPi;   //!
   TBranch        *b_RPZ_HT5PP;   //!
   TBranch        *b_RPT_HT5PP;   //!
   TBranch        *b_H9PP;   //!
   TBranch        *b_H10PP;   //!
   TBranch        *b_HT9PP;   //!
   TBranch        *b_HT10PP;   //!
   TBranch        *b_R_H2PP_H9PP;   //!
   TBranch        *b_R_HT9PP_H9PP;   //!
   TBranch        *b_RPZ_HT9PP;   //!
   TBranch        *b_RPT_HT9PP;   //!
   TBranch        *b_H2Pa;   //!
   TBranch        *b_H2Pb;   //!
   TBranch        *b_H3Pa;   //!
   TBranch        *b_H3Pb;   //!
   TBranch        *b_H4Pa;   //!
   TBranch        *b_H4Pb;   //!
   TBranch        *b_H5Pa;   //!
   TBranch        *b_H5Pb;   //!
   TBranch        *b_dH2o3P;   //!
   TBranch        *b_H2Ca;   //!
   TBranch        *b_H2Cb;   //!
   TBranch        *b_H3Ca;   //!
   TBranch        *b_H3Cb;   //!
   TBranch        *b_dphiPV1a;   //!
   TBranch        *b_dphiPV1b;   //!
   TBranch        *b_cosV1a;   //!
   TBranch        *b_cosV1b;   //!
   TBranch        *b_dphiCV2a;   //!
   TBranch        *b_dphiCV2b;   //!
   TBranch        *b_cosV2a;   //!
   TBranch        *b_cosV2b;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_Meff;   //!
   TBranch        *b_Aplan;   //!
   TBranch        *b_dphi;   //!
   TBranch        *b_dphiR;   //!
   TBranch        *b_NJet;   //!
   TBranch        *b_NJa;   //!
   TBranch        *b_NJb;   //!
   TBranch        *b_NJ1a;   //!
   TBranch        *b_NJ1b;   //!
   TBranch        *b_NJ2a;   //!
   TBranch        *b_NJ2b;   //!
   TBranch        *b_pT_jet1;   //!
   TBranch        *b_pT_jet2;   //!
   TBranch        *b_pT_jet3;   //!
   TBranch        *b_pT_jet4;   //!
   TBranch        *b_pT_jet5;   //!
   TBranch        *b_pT_jet6;   //!
   TBranch        *b_pTPP_jet1;   //!
   TBranch        *b_pTPP_jet2;   //!
   TBranch        *b_pT_jet1a;   //!
   TBranch        *b_pT_jet2a;   //!
   TBranch        *b_pT_jet1b;   //!
   TBranch        *b_pT_jet2b;   //!
   TBranch        *b_pTPP_jet1a;   //!
   TBranch        *b_pTPP_jet2a;   //!
   TBranch        *b_pTPP_jet3a;   //!
   TBranch        *b_pTPP_jet1b;   //!
   TBranch        *b_pTPP_jet2b;   //!
   TBranch        *b_pTPP_jet3b;   //!
   TBranch        *b_pPP_jet1a;   //!
   TBranch        *b_pPP_jet2a;   //!
   TBranch        *b_pPP_jet3a;   //!
   TBranch        *b_pPP_jet1b;   //!
   TBranch        *b_pPP_jet2b;   //!
   TBranch        *b_pPP_jet3b;   //!
   TBranch        *b_pTPP_Va;   //!
   TBranch        *b_pTPP_V1a;   //!
   TBranch        *b_pTPP_V2a;   //!
   TBranch        *b_pTPP_Vb;   //!
   TBranch        *b_pTPP_V1b;   //!
   TBranch        *b_pTPP_V2b;   //!
   TBranch        *b_pTPP_Ia;   //!
   TBranch        *b_pTPP_Ib;   //!
   TBranch        *b_pPP_Va;   //!
   TBranch        *b_pPP_V1a;   //!
   TBranch        *b_pPP_V2a;   //!
   TBranch        *b_pPP_Vb;   //!
   TBranch        *b_pPP_V1b;   //!
   TBranch        *b_pPP_V2b;   //!
   TBranch        *b_pPP_Ia;   //!
   TBranch        *b_pPP_Ib;   //!

   RJWorkshopBase(TTree *tree=0);
   virtual ~RJWorkshopBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
  virtual void     Loop(){}
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

inline RJWorkshopBase::RJWorkshopBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("BKG_v44/Top.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("BKG_v44/Top.root");
      }
      f->GetObject("Top_SRAll",tree);

   }
   Init(tree);
}

inline RJWorkshopBase::~RJWorkshopBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t RJWorkshopBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t RJWorkshopBase::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

inline void RJWorkshopBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

    fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("veto", &veto, &b_veto);
   fChain->SetBranchAddress("cleaning", &cleaning, &b_cleaning);
   fChain->SetBranchAddress("timing", &timing, &b_timing);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("nBJet", &nBJet, &b_nBJet);
   fChain->SetBranchAddress("nCJet", &nCJet, &b_nCJet);
   fChain->SetBranchAddress("bTagWeight", &bTagWeight, &b_bTagWeight);
   fChain->SetBranchAddress("m_jet1_eta", &m_jet1_eta, &b_m_jet1_eta);
   fChain->SetBranchAddress("m_jet1_chf", &m_jet1_chf, &b_m_jet1_chf);
   fChain->SetBranchAddress("m_jet1_FracSamplingMax", &m_jet1_FracSamplingMax, &b_m_jet1_FracSamplingMax);
   fChain->SetBranchAddress("Rsib", &Rsib, &b_Rsib);
   fChain->SetBranchAddress("deltaQCD", &deltaQCD, &b_deltaQCD);
   fChain->SetBranchAddress("pTCM", &pTCM, &b_pTCM);
   fChain->SetBranchAddress("pZCM", &pZCM, &b_pZCM);
   fChain->SetBranchAddress("PP_VisShape", &PP_VisShape, &b_PP_VisShape);
   fChain->SetBranchAddress("MDR", &MDR, &b_MDR);
   fChain->SetBranchAddress("H2PP", &H2PP, &b_H2PP);
   fChain->SetBranchAddress("PTISR", &PTISR, &b_PTISR);
   fChain->SetBranchAddress("RISR", &RISR, &b_RISR);
   fChain->SetBranchAddress("cosS", &cosS, &b_cosS);
   fChain->SetBranchAddress("dphiCMI", &dphiCMI, &b_dphiCMI);
   fChain->SetBranchAddress("dphiISRI", &dphiISRI, &b_dphiISRI);
   fChain->SetBranchAddress("MS", &MS, &b_MS);
   fChain->SetBranchAddress("NV", &NV, &b_NV);
   fChain->SetBranchAddress("NISR", &NISR, &b_NISR);
   fChain->SetBranchAddress("MISR", &MISR, &b_MISR);
   fChain->SetBranchAddress("MV", &MV, &b_MV);
   fChain->SetBranchAddress("pTjV1", &pTjV1, &b_pTjV1);
   fChain->SetBranchAddress("pTjV2", &pTjV2, &b_pTjV2);
   fChain->SetBranchAddress("pTjV3", &pTjV3, &b_pTjV3);
   fChain->SetBranchAddress("pTjV4", &pTjV4, &b_pTjV4);
   fChain->SetBranchAddress("RPT_PTISR", &RPT_PTISR, &b_RPT_PTISR);
   fChain->SetBranchAddress("cosPP", &cosPP, &b_cosPP);
   fChain->SetBranchAddress("dphiVP", &dphiVP, &b_dphiVP);
   fChain->SetBranchAddress("dphiPPV", &dphiPPV, &b_dphiPPV);
   fChain->SetBranchAddress("cosP", &cosP, &b_cosP);
   fChain->SetBranchAddress("sangle", &sangle, &b_sangle);
   fChain->SetBranchAddress("dangle", &dangle, &b_dangle);
   fChain->SetBranchAddress("dphiPa", &dphiPa, &b_dphiPa);
   fChain->SetBranchAddress("dphiPb", &dphiPb, &b_dphiPb);
   fChain->SetBranchAddress("ddphiP", &ddphiP, &b_ddphiP);
   fChain->SetBranchAddress("sdphiP", &sdphiP, &b_sdphiP);
   fChain->SetBranchAddress("H3PP", &H3PP, &b_H3PP);
   fChain->SetBranchAddress("H4PP", &H4PP, &b_H4PP);
   fChain->SetBranchAddress("HT3PP", &HT3PP, &b_HT3PP);
   fChain->SetBranchAddress("HT4PP", &HT4PP, &b_HT4PP);
   fChain->SetBranchAddress("R_H2PP_H3PP", &R_H2PP_H3PP, &b_R_H2PP_H3PP);
   fChain->SetBranchAddress("R_pTj2_HT3PP", &R_pTj2_HT3PP, &b_R_pTj2_HT3PP);
   fChain->SetBranchAddress("RPZ_HT3PP", &RPZ_HT3PP, &b_RPZ_HT3PP);
   fChain->SetBranchAddress("RPT_HT3PP", &RPT_HT3PP, &b_RPT_HT3PP);
   fChain->SetBranchAddress("H5PP", &H5PP, &b_H5PP);
   fChain->SetBranchAddress("H6PP", &H6PP, &b_H6PP);
   fChain->SetBranchAddress("HT5PP", &HT5PP, &b_HT5PP);
   fChain->SetBranchAddress("HT6PP", &HT6PP, &b_HT6PP);
   fChain->SetBranchAddress("R_H2PP_H5PP", &R_H2PP_H5PP, &b_R_H2PP_H5PP);
   fChain->SetBranchAddress("R_HT5PP_H5PP", &R_HT5PP_H5PP, &b_R_HT5PP_H5PP);
   fChain->SetBranchAddress("minR_pTj2i_HT3PPi", &minR_pTj2i_HT3PPi, &b_minR_pTj2i_HT3PPi);
   fChain->SetBranchAddress("maxR_H1PPi_H2PPi", &maxR_H1PPi_H2PPi, &b_maxR_H1PPi_H2PPi);
   fChain->SetBranchAddress("RPZ_HT5PP", &RPZ_HT5PP, &b_RPZ_HT5PP);
   fChain->SetBranchAddress("RPT_HT5PP", &RPT_HT5PP, &b_RPT_HT5PP);
   fChain->SetBranchAddress("H9PP", &H9PP, &b_H9PP);
   fChain->SetBranchAddress("H10PP", &H10PP, &b_H10PP);
   fChain->SetBranchAddress("HT9PP", &HT9PP, &b_HT9PP);
   fChain->SetBranchAddress("HT10PP", &HT10PP, &b_HT10PP);
   fChain->SetBranchAddress("R_H2PP_H9PP", &R_H2PP_H9PP, &b_R_H2PP_H9PP);
   fChain->SetBranchAddress("R_HT9PP_H9PP", &R_HT9PP_H9PP, &b_R_HT9PP_H9PP);
   fChain->SetBranchAddress("RPZ_HT9PP", &RPZ_HT9PP, &b_RPZ_HT9PP);
   fChain->SetBranchAddress("RPT_HT9PP", &RPT_HT9PP, &b_RPT_HT9PP);
   fChain->SetBranchAddress("H2Pa", &H2Pa, &b_H2Pa);
   fChain->SetBranchAddress("H2Pb", &H2Pb, &b_H2Pb);
   fChain->SetBranchAddress("H3Pa", &H3Pa, &b_H3Pa);
   fChain->SetBranchAddress("H3Pb", &H3Pb, &b_H3Pb);
   fChain->SetBranchAddress("H4Pa", &H4Pa, &b_H4Pa);
   fChain->SetBranchAddress("H4Pb", &H4Pb, &b_H4Pb);
   fChain->SetBranchAddress("H5Pa", &H5Pa, &b_H5Pa);
   fChain->SetBranchAddress("H5Pb", &H5Pb, &b_H5Pb);
   fChain->SetBranchAddress("dH2o3P", &dH2o3P, &b_dH2o3P);
   fChain->SetBranchAddress("H2Ca", &H2Ca, &b_H2Ca);
   fChain->SetBranchAddress("H2Cb", &H2Cb, &b_H2Cb);
   fChain->SetBranchAddress("H3Ca", &H3Ca, &b_H3Ca);
   fChain->SetBranchAddress("H3Cb", &H3Cb, &b_H3Cb);
   fChain->SetBranchAddress("dphiPV1a", &dphiPV1a, &b_dphiPV1a);
   fChain->SetBranchAddress("dphiPV1b", &dphiPV1b, &b_dphiPV1b);
   fChain->SetBranchAddress("cosV1a", &cosV1a, &b_cosV1a);
   fChain->SetBranchAddress("cosV1b", &cosV1b, &b_cosV1b);
   fChain->SetBranchAddress("dphiCV2a", &dphiCV2a, &b_dphiCV2a);
   fChain->SetBranchAddress("dphiCV2b", &dphiCV2b, &b_dphiCV2b);
   fChain->SetBranchAddress("cosV2a", &cosV2a, &b_cosV2a);
   fChain->SetBranchAddress("cosV2b", &cosV2b, &b_cosV2b);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("Meff", &Meff, &b_Meff);
   fChain->SetBranchAddress("Aplan", &Aplan, &b_Aplan);
   fChain->SetBranchAddress("dphi", &dphi, &b_dphi);
   fChain->SetBranchAddress("dphiR", &dphiR, &b_dphiR);
   fChain->SetBranchAddress("NJet", &NJet, &b_NJet);
   fChain->SetBranchAddress("NJa", &NJa, &b_NJa);
   fChain->SetBranchAddress("NJb", &NJb, &b_NJb);
   fChain->SetBranchAddress("NJ1a", &NJ1a, &b_NJ1a);
   fChain->SetBranchAddress("NJ1b", &NJ1b, &b_NJ1b);
   fChain->SetBranchAddress("NJ2a", &NJ2a, &b_NJ2a);
   fChain->SetBranchAddress("NJ2b", &NJ2b, &b_NJ2b);
   fChain->SetBranchAddress("pT_jet1", &pT_jet1, &b_pT_jet1);
   fChain->SetBranchAddress("pT_jet2", &pT_jet2, &b_pT_jet2);
   fChain->SetBranchAddress("pT_jet3", &pT_jet3, &b_pT_jet3);
   fChain->SetBranchAddress("pT_jet4", &pT_jet4, &b_pT_jet4);
   fChain->SetBranchAddress("pT_jet5", &pT_jet5, &b_pT_jet5);
   fChain->SetBranchAddress("pT_jet6", &pT_jet6, &b_pT_jet6);
   fChain->SetBranchAddress("pTPP_jet1", &pTPP_jet1, &b_pTPP_jet1);
   fChain->SetBranchAddress("pTPP_jet2", &pTPP_jet2, &b_pTPP_jet2);
   fChain->SetBranchAddress("pT_jet1a", &pT_jet1a, &b_pT_jet1a);
   fChain->SetBranchAddress("pT_jet2a", &pT_jet2a, &b_pT_jet2a);
   fChain->SetBranchAddress("pT_jet1b", &pT_jet1b, &b_pT_jet1b);
   fChain->SetBranchAddress("pT_jet2b", &pT_jet2b, &b_pT_jet2b);
   fChain->SetBranchAddress("pTPP_jet1a", &pTPP_jet1a, &b_pTPP_jet1a);
   fChain->SetBranchAddress("pTPP_jet2a", &pTPP_jet2a, &b_pTPP_jet2a);
   fChain->SetBranchAddress("pTPP_jet3a", &pTPP_jet3a, &b_pTPP_jet3a);
   fChain->SetBranchAddress("pTPP_jet1b", &pTPP_jet1b, &b_pTPP_jet1b);
   fChain->SetBranchAddress("pTPP_jet2b", &pTPP_jet2b, &b_pTPP_jet2b);
   fChain->SetBranchAddress("pTPP_jet3b", &pTPP_jet3b, &b_pTPP_jet3b);
   fChain->SetBranchAddress("pPP_jet1a", &pPP_jet1a, &b_pPP_jet1a);
   fChain->SetBranchAddress("pPP_jet2a", &pPP_jet2a, &b_pPP_jet2a);
   fChain->SetBranchAddress("pPP_jet3a", &pPP_jet3a, &b_pPP_jet3a);
   fChain->SetBranchAddress("pPP_jet1b", &pPP_jet1b, &b_pPP_jet1b);
   fChain->SetBranchAddress("pPP_jet2b", &pPP_jet2b, &b_pPP_jet2b);
   fChain->SetBranchAddress("pPP_jet3b", &pPP_jet3b, &b_pPP_jet3b);
   fChain->SetBranchAddress("pTPP_Va", &pTPP_Va, &b_pTPP_Va);
   fChain->SetBranchAddress("pTPP_V1a", &pTPP_V1a, &b_pTPP_V1a);
   fChain->SetBranchAddress("pTPP_V2a", &pTPP_V2a, &b_pTPP_V2a);
   fChain->SetBranchAddress("pTPP_Vb", &pTPP_Vb, &b_pTPP_Vb);
   fChain->SetBranchAddress("pTPP_V1b", &pTPP_V1b, &b_pTPP_V1b);
   fChain->SetBranchAddress("pTPP_V2b", &pTPP_V2b, &b_pTPP_V2b);
   fChain->SetBranchAddress("pTPP_Ia", &pTPP_Ia, &b_pTPP_Ia);
   fChain->SetBranchAddress("pTPP_Ib", &pTPP_Ib, &b_pTPP_Ib);
   fChain->SetBranchAddress("pPP_Va", &pPP_Va, &b_pPP_Va);
   fChain->SetBranchAddress("pPP_V1a", &pPP_V1a, &b_pPP_V1a);
   fChain->SetBranchAddress("pPP_V2a", &pPP_V2a, &b_pPP_V2a);
   fChain->SetBranchAddress("pPP_Vb", &pPP_Vb, &b_pPP_Vb);
   fChain->SetBranchAddress("pPP_V1b", &pPP_V1b, &b_pPP_V1b);
   fChain->SetBranchAddress("pPP_V2b", &pPP_V2b, &b_pPP_V2b);
   fChain->SetBranchAddress("pPP_Ia", &pPP_Ia, &b_pPP_Ia);
   fChain->SetBranchAddress("pPP_Ib", &pPP_Ib, &b_pPP_Ib);
   Notify();
}

inline Bool_t RJWorkshopBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void RJWorkshopBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t RJWorkshopBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
