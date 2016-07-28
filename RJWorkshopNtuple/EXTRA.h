//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Sep 27 11:20:02 2015 by ROOT version 5.34/26
// from TTree Top_SRAll/Top_SRAll
// found on file: Top.root
//////////////////////////////////////////////////////////

#ifndef EXTRA_h
#define EXTRA_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class EXTRA {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        weight;
   UInt_t          veto;
   UInt_t          cleaning;
   UInt_t          timing;
   Double_t        Rsib;
   Double_t        deltaQCD;
   Double_t        RPT;
   Double_t        RPZ;
   Double_t        MDR;
   Double_t        MP;
   Double_t        PP_VisShape;
   Double_t        gaminvPP;
   Double_t        cosPP;
   Double_t        dphiVP;
   Double_t        dphiPPV;
   Double_t        cosP;
   Double_t        H2PP;
   Double_t        H3PP;
   Double_t        H4PP;
   Double_t        H6PP;
   Double_t        H2Pa;
   Double_t        H2Pb;
   Double_t        H3Pa;
   Double_t        H3Pb;
   Double_t        H4Pa;
   Double_t        H4Pb;
   Double_t        H5Pa;
   Double_t        H5Pb;
   Double_t        H2Ca;
   Double_t        H2Cb;
   Double_t        H3Ca;
   Double_t        H3Cb;
   Double_t        dphiPCa;
   Double_t        dphiPCb;
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
   Double_t        pT_jet1a;
   Double_t        pT_jet2a;
   Double_t        pT_jet1b;
   Double_t        pT_jet2b;
   Double_t        m_pTPP_jet1a;
   Double_t        m_pTPP_jet2a;
   Double_t        m_pTPP_jet1b;
   Double_t        m_pTPP_jet2b;
   Double_t        m_pTPP_V1a;
   Double_t        m_pTPP_V2a;
   Double_t        m_pTPP_V1b;
   Double_t        m_pTPP_V2b;
   Double_t        m_pPP_V1a;
   Double_t        m_pPP_V2a;
   Double_t        m_pPP_V1b;
   Double_t        m_pPP_V2b;

   // List of branches
   TBranch        *b_weight;   //!
   TBranch        *b_veto;   //!
   TBranch        *b_cleaning;   //!
   TBranch        *b_timing;   //!
   TBranch        *b_Rsib;   //!
   TBranch        *b_deltaQCD;   //!
   TBranch        *b_RPT;   //!
   TBranch        *b_RPZ;   //!
   TBranch        *b_MDR;   //!
   TBranch        *b_MP;   //!
   TBranch        *b_PP_VisShape;   //!
   TBranch        *b_gaminvPP;   //!
   TBranch        *b_cosPP;   //!
   TBranch        *b_dphiVP;   //!
   TBranch        *b_dphiPPV;   //!
   TBranch        *b_cosP;   //!
   TBranch        *b_H2PP;   //!
   TBranch        *b_H3PP;   //!
   TBranch        *b_H4PP;   //!
   TBranch        *b_H6PP;   //!
   TBranch        *b_H2Pa;   //!
   TBranch        *b_H2Pb;   //!
   TBranch        *b_H3Pa;   //!
   TBranch        *b_H3Pb;   //!
   TBranch        *b_H4Pa;   //!
   TBranch        *b_H4Pb;   //!
   TBranch        *b_H5Pa;   //!
   TBranch        *b_H5Pb;   //!
   TBranch        *b_H2Ca;   //!
   TBranch        *b_H2Cb;   //!
   TBranch        *b_H3Ca;   //!
   TBranch        *b_H3Cb;   //!
   TBranch        *b_dphiPCa;   //!
   TBranch        *b_dphiPCb;   //!
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
   TBranch        *b_pT_jet1a;   //!
   TBranch        *b_pT_jet2a;   //!
   TBranch        *b_pT_jet1b;   //!
   TBranch        *b_pT_jet2b;   //!
   TBranch        *b_m_pTPP_jet1a;   //!
   TBranch        *b_m_pTPP_jet2a;   //!
   TBranch        *b_m_pTPP_jet1b;   //!
   TBranch        *b_m_pTPP_jet2b;   //!
   TBranch        *b_m_pTPP_V1a;   //!
   TBranch        *b_m_pTPP_V2a;   //!
   TBranch        *b_m_pTPP_V1b;   //!
   TBranch        *b_m_pTPP_V2b;   //!
   TBranch        *b_m_pPP_V1a;   //!
   TBranch        *b_m_pPP_V2a;   //!
   TBranch        *b_m_pPP_V1b;   //!
   TBranch        *b_m_pPP_V2b;   //!

   EXTRA(TTree *tree=0);
   virtual ~EXTRA();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef EXTRA_cxx
EXTRA::EXTRA(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Top.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Top.root");
      }
      f->GetObject("Top_SRAll",tree);

   }
   Init(tree);
}

EXTRA::~EXTRA()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t EXTRA::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t EXTRA::LoadTree(Long64_t entry)
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

void EXTRA::Init(TTree *tree)
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
   fChain->SetBranchAddress("Rsib", &Rsib, &b_Rsib);
   fChain->SetBranchAddress("deltaQCD", &deltaQCD, &b_deltaQCD);
   fChain->SetBranchAddress("RPT", &RPT, &b_RPT);
   fChain->SetBranchAddress("RPZ", &RPZ, &b_RPZ);
   fChain->SetBranchAddress("MDR", &MDR, &b_MDR);
   fChain->SetBranchAddress("MP", &MP, &b_MP);
   fChain->SetBranchAddress("PP_VisShape", &PP_VisShape, &b_PP_VisShape);
   fChain->SetBranchAddress("gaminvPP", &gaminvPP, &b_gaminvPP);
   fChain->SetBranchAddress("cosPP", &cosPP, &b_cosPP);
   fChain->SetBranchAddress("dphiVP", &dphiVP, &b_dphiVP);
   fChain->SetBranchAddress("dphiPPV", &dphiPPV, &b_dphiPPV);
   fChain->SetBranchAddress("cosP", &cosP, &b_cosP);
   fChain->SetBranchAddress("H2PP", &H2PP, &b_H2PP);
   fChain->SetBranchAddress("H3PP", &H3PP, &b_H3PP);
   fChain->SetBranchAddress("H4PP", &H4PP, &b_H4PP);
   fChain->SetBranchAddress("H6PP", &H6PP, &b_H6PP);
   fChain->SetBranchAddress("H2Pa", &H2Pa, &b_H2Pa);
   fChain->SetBranchAddress("H2Pb", &H2Pb, &b_H2Pb);
   fChain->SetBranchAddress("H3Pa", &H3Pa, &b_H3Pa);
   fChain->SetBranchAddress("H3Pb", &H3Pb, &b_H3Pb);
   fChain->SetBranchAddress("H4Pa", &H4Pa, &b_H4Pa);
   fChain->SetBranchAddress("H4Pb", &H4Pb, &b_H4Pb);
   fChain->SetBranchAddress("H5Pa", &H5Pa, &b_H5Pa);
   fChain->SetBranchAddress("H5Pb", &H5Pb, &b_H5Pb);
   fChain->SetBranchAddress("H2Ca", &H2Ca, &b_H2Ca);
   fChain->SetBranchAddress("H2Cb", &H2Cb, &b_H2Cb);
   fChain->SetBranchAddress("H3Ca", &H3Ca, &b_H3Ca);
   fChain->SetBranchAddress("H3Cb", &H3Cb, &b_H3Cb);
   fChain->SetBranchAddress("dphiPCa", &dphiPCa, &b_dphiPCa);
   fChain->SetBranchAddress("dphiPCb", &dphiPCb, &b_dphiPCb);
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
   fChain->SetBranchAddress("pT_jet1a", &pT_jet1a, &b_pT_jet1a);
   fChain->SetBranchAddress("pT_jet2a", &pT_jet2a, &b_pT_jet2a);
   fChain->SetBranchAddress("pT_jet1b", &pT_jet1b, &b_pT_jet1b);
   fChain->SetBranchAddress("pT_jet2b", &pT_jet2b, &b_pT_jet2b);
   fChain->SetBranchAddress("m_pTPP_jet1a", &m_pTPP_jet1a, &b_m_pTPP_jet1a);
   fChain->SetBranchAddress("m_pTPP_jet2a", &m_pTPP_jet2a, &b_m_pTPP_jet2a);
   fChain->SetBranchAddress("m_pTPP_jet1b", &m_pTPP_jet1b, &b_m_pTPP_jet1b);
   fChain->SetBranchAddress("m_pTPP_jet2b", &m_pTPP_jet2b, &b_m_pTPP_jet2b);
   fChain->SetBranchAddress("m_pTPP_V1a", &m_pTPP_V1a, &b_m_pTPP_V1a);
   fChain->SetBranchAddress("m_pTPP_V2a", &m_pTPP_V2a, &b_m_pTPP_V2a);
   fChain->SetBranchAddress("m_pTPP_V1b", &m_pTPP_V1b, &b_m_pTPP_V1b);
   fChain->SetBranchAddress("m_pTPP_V2b", &m_pTPP_V2b, &b_m_pTPP_V2b);
   fChain->SetBranchAddress("m_pPP_V1a", &m_pPP_V1a, &b_m_pPP_V1a);
   fChain->SetBranchAddress("m_pPP_V2a", &m_pPP_V2a, &b_m_pPP_V2a);
   fChain->SetBranchAddress("m_pPP_V1b", &m_pPP_V1b, &b_m_pPP_V1b);
   fChain->SetBranchAddress("m_pPP_V2b", &m_pPP_V2b, &b_m_pPP_V2b);
   Notify();
}

Bool_t EXTRA::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void EXTRA::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t EXTRA::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef EXTRA_cxx
