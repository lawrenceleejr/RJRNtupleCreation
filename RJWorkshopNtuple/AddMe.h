//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan 20 13:44:25 2016 by ROOT version 5.34/26
// from TTree Analysis/Analysis
// found on file: test.root
//////////////////////////////////////////////////////////

#ifndef AddMe_h
#define AddMe_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class AddMe {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        weight;
   Double_t        Rsib;
   Double_t        deltaQCD;
   Double_t        HT1CM;
   Double_t        PIoHT1CM;
   Double_t        cosS;
   Double_t        Idepth;
   Double_t        MS;
   Int_t           NVS;
   Double_t        MISR;
   Double_t        MVS;
   Double_t        MVSoMS;
   Double_t        RPT_HT1CM;
   Int_t           NbV;
   Int_t           NbISR;
   Int_t           NV;
   Int_t           NISR;
   Int_t           dphiCMV;
   Bool_t          LepVeto;
   Double_t        m_MET;

   // List of branches
   TBranch        *b_weight;   //!
   TBranch        *b_Rsib;   //!
   TBranch        *b_deltaQCD;   //!
   TBranch        *b_HT1CM;   //!
   TBranch        *b_PIoHT1CM;   //!
   TBranch        *b_cosS;   //!
   TBranch        *b_Idepth;   //!
   TBranch        *b_MS;   //!
   TBranch        *b_NVS;   //!
   TBranch        *b_MISR;   //!
   TBranch        *b_MVS;   //!
   TBranch        *b_MVSoMS;   //!
   TBranch        *b_RPT_HT1CM;   //!
   TBranch        *b_NbV;   //!
   TBranch        *b_NbISR;   //!
   TBranch        *b_NV;   //!
   TBranch        *b_NISR;   //!
   TBranch        *b_dphiCMV;   //!
   TBranch        *b_LepVeto;   //!
   TBranch        *b_m_MET;   //!

   AddMe(TTree *tree=0);
   virtual ~AddMe();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef AddMe_cxx
AddMe::AddMe(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("test.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("test.root");
      }
      f->GetObject("Analysis",tree);

   }
   Init(tree);
}

AddMe::~AddMe()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AddMe::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AddMe::LoadTree(Long64_t entry)
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

void AddMe::Init(TTree *tree)
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
   fChain->SetBranchAddress("Rsib", &Rsib, &b_Rsib);
   fChain->SetBranchAddress("deltaQCD", &deltaQCD, &b_deltaQCD);
   fChain->SetBranchAddress("HT1CM", &HT1CM, &b_HT1CM);
   fChain->SetBranchAddress("PIoHT1CM", &PIoHT1CM, &b_PIoHT1CM);
   fChain->SetBranchAddress("cosS", &cosS, &b_cosS);
   fChain->SetBranchAddress("Idepth", &Idepth, &b_Idepth);
   fChain->SetBranchAddress("MS", &MS, &b_MS);
   fChain->SetBranchAddress("NVS", &NVS, &b_NVS);
   fChain->SetBranchAddress("MISR", &MISR, &b_MISR);
   fChain->SetBranchAddress("MVS", &MVS, &b_MVS);
   fChain->SetBranchAddress("MVSoMS", &MVSoMS, &b_MVSoMS);
   fChain->SetBranchAddress("RPT_HT1CM", &RPT_HT1CM, &b_RPT_HT1CM);
   fChain->SetBranchAddress("NbV", &NbV, &b_NbV);
   fChain->SetBranchAddress("NbISR", &NbISR, &b_NbISR);
   fChain->SetBranchAddress("NV", &NV, &b_NV);
   fChain->SetBranchAddress("NISR", &NISR, &b_NISR);
   fChain->SetBranchAddress("dphiCMV", &dphiCMV, &b_dphiCMV);
   fChain->SetBranchAddress("LepVeto", &LepVeto, &b_LepVeto);
   fChain->SetBranchAddress("m_MET", &m_MET, &b_m_MET);
   Notify();
}

Bool_t AddMe::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AddMe::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AddMe::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef AddMe_cxx
