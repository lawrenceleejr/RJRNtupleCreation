//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Dec 10 11:11:53 2015 by ROOT version 5.34/25
// from TTree FiducialEventsTree/Fiducial Events
// found on file: Data.root
//////////////////////////////////////////////////////////

#ifndef SunBase_h
#define SunBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

using namespace std;

class SunBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           m_jet_n;
   vector<float>   *m_jet_pt;
   vector<float>   *m_jet_eta;
   vector<float>   *m_jet_phi;
   vector<float>   *m_jet_E;
   vector<bool>    *m_jet_btag;
   Int_t           m_muon_n;
   vector<float>   *m_muon_pt;
   vector<float>   *m_muon_eta;
   vector<float>   *m_muon_phi;
   Int_t           m_el_n;
   vector<float>   *m_el_pt;
   vector<float>   *m_el_eta;
   vector<float>   *m_el_phi;
   Int_t           m_tau_n;
   vector<float>   *m_tau_pt;
   vector<float>   *m_tau_eta;
   vector<float>   *m_tau_phi;
   Float_t         m_met_Et;
   Float_t         m_met_phi;
   Float_t         m_weight;

   // List of branches
   TBranch        *b_m_jet_n;   //!
   TBranch        *b_m_jet_pt;   //!
   TBranch        *b_m_jet_eta;   //!
   TBranch        *b_m_jet_phi;   //!
   TBranch        *b_m_jet_E;   //!
   TBranch        *b_m_jet_btag;   //!
   TBranch        *b_m_muon_n;   //!
   TBranch        *b_m_muon_pt;   //!
   TBranch        *b_m_muon_eta;   //!
   TBranch        *b_m_muon_phi;   //!
   TBranch        *b_m_el_n;   //!
   TBranch        *b_m_el_pt;   //!
   TBranch        *b_m_el_eta;   //!
   TBranch        *b_m_el_phi;   //!
   TBranch        *b_m_tau_n;   //!
   TBranch        *b_m_tau_pt;   //!
   TBranch        *b_m_tau_eta;   //!
   TBranch        *b_m_tau_phi;   //!
   TBranch        *b_m_met_Et;   //!
   TBranch        *b_m_met_phi;   //!
   TBranch        *b_m_weight;   //!

   SunBase(TTree *tree=0);
   virtual ~SunBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
  virtual void     Loop(){}
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

//#ifdef SunBase_cxx
inline SunBase::SunBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Data.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("Data.root");
      }
      f->GetObject("FiducialEventsTree",tree);

   }
   Init(tree);
}

inline SunBase::~SunBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t SunBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t SunBase::LoadTree(Long64_t entry)
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

inline void SunBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   m_jet_pt = 0;
   m_jet_eta = 0;
   m_jet_phi = 0;
   m_jet_E = 0;
   m_jet_btag = 0;
   m_muon_pt = 0;
   m_muon_eta = 0;
   m_muon_phi = 0;
   m_el_pt = 0;
   m_el_eta = 0;
   m_el_phi = 0;
   m_tau_pt = 0;
   m_tau_eta = 0;
   m_tau_phi = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("m_jet_n", &m_jet_n, &b_m_jet_n);
   fChain->SetBranchAddress("m_jet_pt", &m_jet_pt, &b_m_jet_pt);
   fChain->SetBranchAddress("m_jet_eta", &m_jet_eta, &b_m_jet_eta);
   fChain->SetBranchAddress("m_jet_phi", &m_jet_phi, &b_m_jet_phi);
   fChain->SetBranchAddress("m_jet_E", &m_jet_E, &b_m_jet_E);
   fChain->SetBranchAddress("m_jet_btag", &m_jet_btag, &b_m_jet_btag);
   fChain->SetBranchAddress("m_muon_n", &m_muon_n, &b_m_muon_n);
   fChain->SetBranchAddress("m_muon_pt", &m_muon_pt, &b_m_muon_pt);
   fChain->SetBranchAddress("m_muon_eta", &m_muon_eta, &b_m_muon_eta);
   fChain->SetBranchAddress("m_muon_phi", &m_muon_phi, &b_m_muon_phi);
   fChain->SetBranchAddress("m_el_n", &m_el_n, &b_m_el_n);
   fChain->SetBranchAddress("m_el_pt", &m_el_pt, &b_m_el_pt);
   fChain->SetBranchAddress("m_el_eta", &m_el_eta, &b_m_el_eta);
   fChain->SetBranchAddress("m_el_phi", &m_el_phi, &b_m_el_phi);
   fChain->SetBranchAddress("m_tau_n", &m_tau_n, &b_m_tau_n);
   fChain->SetBranchAddress("m_tau_pt", &m_tau_pt, &b_m_tau_pt);
   fChain->SetBranchAddress("m_tau_eta", &m_tau_eta, &b_m_tau_eta);
   fChain->SetBranchAddress("m_tau_phi", &m_tau_phi, &b_m_tau_phi);
   fChain->SetBranchAddress("m_met_Et", &m_met_Et, &b_m_met_Et);
   fChain->SetBranchAddress("m_met_phi", &m_met_phi, &b_m_met_phi);
   fChain->SetBranchAddress("m_weight", &m_weight, &b_m_weight);
   Notify();
}

inline Bool_t SunBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void SunBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t SunBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
//#endif // #ifdef SunBase_cxx
