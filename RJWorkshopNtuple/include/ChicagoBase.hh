//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Sep 22 11:38:32 2015 by ROOT version 5.34/26
// from TTree oTree/optimization tree
// found on file: test_RJworkshop.root
//////////////////////////////////////////////////////////

#ifndef ChicagoBase_h
#define ChicagoBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

using namespace std;

class ChicagoBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         event_weight;
   Int_t           event_number;
   Float_t         m_transverse;
   Float_t         met;
   Float_t         met_px;
   Float_t         met_py;
   Float_t         m_effective;
   Float_t         dPhiMETMin;
   Float_t         mTb;
   Float_t         pt_total;
   Int_t           multiplicity_jet;
   Int_t           multiplicity_jet_b;
   vector<float>   *jet_pt;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;
   vector<float>   *jet_m;
   vector<int>     *jet_isB;
   Float_t         pt_jet_rc8_0;
   Float_t         m_jet_rc8_0;
   Float_t         split12_jet_rc8_0;
   Float_t         split23_jet_rc8_0;
   Int_t           nsj_jet_rc8_0;
   Float_t         pt_jet_rc10_0;
   Float_t         m_jet_rc10_0;
   Float_t         split12_jet_rc10_0;
   Float_t         split23_jet_rc10_0;
   Int_t           nsj_jet_rc10_0;
   Float_t         pt_jet_rc12_0;
   Float_t         m_jet_rc12_0;
   Float_t         split12_jet_rc12_0;
   Float_t         split23_jet_rc12_0;
   Int_t           nsj_jet_rc12_0;
   Float_t         pt_jet_rc8_1;
   Float_t         m_jet_rc8_1;
   Float_t         split12_jet_rc8_1;
   Float_t         split23_jet_rc8_1;
   Int_t           nsj_jet_rc8_1;
   Float_t         pt_jet_rc10_1;
   Float_t         m_jet_rc10_1;
   Float_t         split12_jet_rc10_1;
   Float_t         split23_jet_rc10_1;
   Int_t           nsj_jet_rc10_1;
   Float_t         pt_jet_rc12_1;
   Float_t         m_jet_rc12_1;
   Float_t         split12_jet_rc12_1;
   Float_t         split23_jet_rc12_1;
   Int_t           nsj_jet_rc12_1;
   Float_t         pt_jet_rc8_2;
   Float_t         m_jet_rc8_2;
   Float_t         split12_jet_rc8_2;
   Float_t         split23_jet_rc8_2;
   Int_t           nsj_jet_rc8_2;
   Float_t         pt_jet_rc10_2;
   Float_t         m_jet_rc10_2;
   Float_t         split12_jet_rc10_2;
   Float_t         split23_jet_rc10_2;
   Int_t           nsj_jet_rc10_2;
   Float_t         pt_jet_rc12_2;
   Float_t         m_jet_rc12_2;
   Float_t         split12_jet_rc12_2;
   Float_t         split23_jet_rc12_2;
   Int_t           nsj_jet_rc12_2;
   Float_t         pt_jet_rc8_3;
   Float_t         m_jet_rc8_3;
   Float_t         split12_jet_rc8_3;
   Float_t         split23_jet_rc8_3;
   Int_t           nsj_jet_rc8_3;
   Float_t         pt_jet_rc10_3;
   Float_t         m_jet_rc10_3;
   Float_t         split12_jet_rc10_3;
   Float_t         split23_jet_rc10_3;
   Int_t           nsj_jet_rc10_3;
   Float_t         pt_jet_rc12_3;
   Float_t         m_jet_rc12_3;
   Float_t         split12_jet_rc12_3;
   Float_t         split23_jet_rc12_3;
   Int_t           nsj_jet_rc12_3;
   Int_t           multiplicity_jet_varR_top;
   Int_t           multiplicity_jet_varR_W;
   Float_t         m_variableR_top_jet_0;
   Float_t         m_variableR_W_jet_0;
   Float_t         pt_variableR_top_jet_0;
   Float_t         pt_variableR_W_jet_0;
   Int_t           nsj_variableR_top_jet_0;
   Int_t           nsj_variableR_W_jet_0;
   Float_t         m_variableR_top_jet_1;
   Float_t         m_variableR_W_jet_1;
   Float_t         pt_variableR_top_jet_1;
   Float_t         pt_variableR_W_jet_1;
   Int_t           nsj_variableR_top_jet_1;
   Int_t           nsj_variableR_W_jet_1;
   Float_t         m_variableR_top_jet_2;
   Float_t         m_variableR_W_jet_2;
   Float_t         pt_variableR_top_jet_2;
   Float_t         pt_variableR_W_jet_2;
   Int_t           nsj_variableR_top_jet_2;
   Int_t           nsj_variableR_W_jet_2;
   Float_t         m_variableR_top_jet_3;
   Float_t         m_variableR_W_jet_3;
   Float_t         pt_variableR_top_jet_3;
   Float_t         pt_variableR_W_jet_3;
   Int_t           nsj_variableR_top_jet_3;
   Int_t           nsj_variableR_W_jet_3;
   Int_t           multiplicity_jet_largeR;
   Int_t           multiplicity_topTag_smoothloose;
   Int_t           multiplicity_topTag_smoothtight;
   Int_t           multiplicity_topTag_loose;
   Int_t           multiplicity_topTag_tight;
   vector<float>   *jet_largeR_pt;
   vector<float>   *jet_largeR_eta;
   vector<float>   *jet_largeR_phi;
   vector<float>   *jet_largeR_m;
   vector<int>     *jet_largeR_isTopLoose;
   vector<int>     *jet_largeR_isTopTight;
   vector<int>     *jet_largeR_isTopSmooLoose;
   vector<int>     *jet_largeR_isTopSmooTight;
   Float_t         pt_jet_largeR_0;
   Float_t         m_jet_largeR_0;
   Float_t         split12_jet_largeR_0;
   Float_t         split23_jet_largeR_0;
   Int_t           nsj_jet_largeR_0;
   Int_t           topTag_Loose_jet_largeR_0;
   Int_t           topTag_Tight_jet_largeR_0;
   Int_t           topTag_SmoothLoose_jet_largeR_0;
   Int_t           topTag_SmoothTight_jet_largeR_0;
   Float_t         pt_jet_largeR_1;
   Float_t         m_jet_largeR_1;
   Float_t         split12_jet_largeR_1;
   Float_t         split23_jet_largeR_1;
   Int_t           nsj_jet_largeR_1;
   Int_t           topTag_Loose_jet_largeR_1;
   Int_t           topTag_Tight_jet_largeR_1;
   Int_t           topTag_SmoothLoose_jet_largeR_1;
   Int_t           topTag_SmoothTight_jet_largeR_1;
   Float_t         pt_jet_largeR_2;
   Float_t         m_jet_largeR_2;
   Float_t         split12_jet_largeR_2;
   Float_t         split23_jet_largeR_2;
   Int_t           nsj_jet_largeR_2;
   Int_t           topTag_Loose_jet_largeR_2;
   Int_t           topTag_Tight_jet_largeR_2;
   Int_t           topTag_SmoothLoose_jet_largeR_2;
   Int_t           topTag_SmoothTight_jet_largeR_2;
   Float_t         pt_jet_largeR_3;
   Float_t         m_jet_largeR_3;
   Float_t         split12_jet_largeR_3;
   Float_t         split23_jet_largeR_3;
   Int_t           nsj_jet_largeR_3;
   Int_t           topTag_Loose_jet_largeR_3;
   Int_t           topTag_Tight_jet_largeR_3;
   Int_t           topTag_SmoothLoose_jet_largeR_3;
   Int_t           topTag_SmoothTight_jet_largeR_3;
   Float_t         razor_ss_mass;
   Float_t         razor_ss_invgamma;
   Float_t         razor_ss_dphivis;
   Float_t         razor_ss_costheta;
   Float_t         razor_ss_dphidecayangle;
   Float_t         razor_ss_mdeltaR;
   Float_t         razor_s1_mass;
   Float_t         razor_s1_costheta;
   Float_t         razor_s2_mass;
   Float_t         razor_s2_costheta;
   Int_t           razor_i1_depth;
   Int_t           razor_i2_depth;
   Int_t           razor_v1_nelements;
   Int_t           razor_v2_nelements;
   Float_t         razor_ss_abs_costheta;
   Float_t         razor_s1_abs_costheta;
   Float_t         razor_s2_abs_costheta;

   // List of branches
   TBranch        *b_event_weight;   //!
   TBranch        *b_event_number;   //!
   TBranch        *b_m_transverse;   //!
   TBranch        *b_met;   //!
   TBranch        *b_met_mpx;   //!
   TBranch        *b_met_mpy;   //!
   TBranch        *b_m_effective;   //!
   TBranch        *b_dPhiMETMin;   //!
   TBranch        *b_mTb;   //!
   TBranch        *b_pt_total;   //!
   TBranch        *b_multiplicity_jet;   //!
   TBranch        *b_multiplicity_jet_b;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_m;   //!
   TBranch        *b_jet_isB;   //!
   TBranch        *b_pt_jet_rc8_0;   //!
   TBranch        *b_m_jet_rc8_0;   //!
   TBranch        *b_split12_jet_rc8_0;   //!
   TBranch        *b_split23_jet_rc8_0;   //!
   TBranch        *b_nsj_jet_rc8_0;   //!
   TBranch        *b_pt_jet_rc10_0;   //!
   TBranch        *b_m_jet_rc10_0;   //!
   TBranch        *b_split12_jet_rc10_0;   //!
   TBranch        *b_split23_jet_rc10_0;   //!
   TBranch        *b_nsj_jet_rc10_0;   //!
   TBranch        *b_pt_jet_rc12_0;   //!
   TBranch        *b_m_jet_rc12_0;   //!
   TBranch        *b_split12_jet_rc12_0;   //!
   TBranch        *b_split23_jet_rc12_0;   //!
   TBranch        *b_nsj_jet_rc12_0;   //!
   TBranch        *b_pt_jet_rc8_1;   //!
   TBranch        *b_m_jet_rc8_1;   //!
   TBranch        *b_split12_jet_rc8_1;   //!
   TBranch        *b_split23_jet_rc8_1;   //!
   TBranch        *b_nsj_jet_rc8_1;   //!
   TBranch        *b_pt_jet_rc10_1;   //!
   TBranch        *b_m_jet_rc10_1;   //!
   TBranch        *b_split12_jet_rc10_1;   //!
   TBranch        *b_split23_jet_rc10_1;   //!
   TBranch        *b_nsj_jet_rc10_1;   //!
   TBranch        *b_pt_jet_rc12_1;   //!
   TBranch        *b_m_jet_rc12_1;   //!
   TBranch        *b_split12_jet_rc12_1;   //!
   TBranch        *b_split23_jet_rc12_1;   //!
   TBranch        *b_nsj_jet_rc12_1;   //!
   TBranch        *b_pt_jet_rc8_2;   //!
   TBranch        *b_m_jet_rc8_2;   //!
   TBranch        *b_split12_jet_rc8_2;   //!
   TBranch        *b_split23_jet_rc8_2;   //!
   TBranch        *b_nsj_jet_rc8_2;   //!
   TBranch        *b_pt_jet_rc10_2;   //!
   TBranch        *b_m_jet_rc10_2;   //!
   TBranch        *b_split12_jet_rc10_2;   //!
   TBranch        *b_split23_jet_rc10_2;   //!
   TBranch        *b_nsj_jet_rc10_2;   //!
   TBranch        *b_pt_jet_rc12_2;   //!
   TBranch        *b_m_jet_rc12_2;   //!
   TBranch        *b_split12_jet_rc12_2;   //!
   TBranch        *b_split23_jet_rc12_2;   //!
   TBranch        *b_nsj_jet_rc12_2;   //!
   TBranch        *b_pt_jet_rc8_3;   //!
   TBranch        *b_m_jet_rc8_3;   //!
   TBranch        *b_split12_jet_rc8_3;   //!
   TBranch        *b_split23_jet_rc8_3;   //!
   TBranch        *b_nsj_jet_rc8_3;   //!
   TBranch        *b_pt_jet_rc10_3;   //!
   TBranch        *b_m_jet_rc10_3;   //!
   TBranch        *b_split12_jet_rc10_3;   //!
   TBranch        *b_split23_jet_rc10_3;   //!
   TBranch        *b_nsj_jet_rc10_3;   //!
   TBranch        *b_pt_jet_rc12_3;   //!
   TBranch        *b_m_jet_rc12_3;   //!
   TBranch        *b_split12_jet_rc12_3;   //!
   TBranch        *b_split23_jet_rc12_3;   //!
   TBranch        *b_nsj_jet_rc12_3;   //!
   TBranch        *b_multiplicity_jet_varR_top;   //!
   TBranch        *b_multiplicity_jet_varR_W;   //!
   TBranch        *b_m_variableR_top_jet_0;   //!
   TBranch        *b_m_variableR_W_jet_0;   //!
   TBranch        *b_pt_variableR_top_jet_0;   //!
   TBranch        *b_pt_variableR_W_jet_0;   //!
   TBranch        *b_nsj_variableR_top_jet_0;   //!
   TBranch        *b_nsj_variableR_W_jet_0;   //!
   TBranch        *b_m_variableR_top_jet_1;   //!
   TBranch        *b_m_variableR_W_jet_1;   //!
   TBranch        *b_pt_variableR_top_jet_1;   //!
   TBranch        *b_pt_variableR_W_jet_1;   //!
   TBranch        *b_nsj_variableR_top_jet_1;   //!
   TBranch        *b_nsj_variableR_W_jet_1;   //!
   TBranch        *b_m_variableR_top_jet_2;   //!
   TBranch        *b_m_variableR_W_jet_2;   //!
   TBranch        *b_pt_variableR_top_jet_2;   //!
   TBranch        *b_pt_variableR_W_jet_2;   //!
   TBranch        *b_nsj_variableR_top_jet_2;   //!
   TBranch        *b_nsj_variableR_W_jet_2;   //!
   TBranch        *b_m_variableR_top_jet_3;   //!
   TBranch        *b_m_variableR_W_jet_3;   //!
   TBranch        *b_pt_variableR_top_jet_3;   //!
   TBranch        *b_pt_variableR_W_jet_3;   //!
   TBranch        *b_nsj_variableR_top_jet_3;   //!
   TBranch        *b_nsj_variableR_W_jet_3;   //!
   TBranch        *b_multiplicity_jet_largeR;   //!
   TBranch        *b_multiplicity_topTag_smoothloose;   //!
   TBranch        *b_multiplicity_topTag_smoothtight;   //!
   TBranch        *b_multiplicity_topTag_loose;   //!
   TBranch        *b_multiplicity_topTag_tight;   //!
   TBranch        *b_jet_largeR_pt;   //!
   TBranch        *b_jet_largeR_eta;   //!
   TBranch        *b_jet_largeR_phi;   //!
   TBranch        *b_jet_largeR_m;   //!
   TBranch        *b_jet_largeR_isTopLoose;   //!
   TBranch        *b_jet_largeR_isTopTight;   //!
   TBranch        *b_jet_largeR_isTopSmooLoose;   //!
   TBranch        *b_jet_largeR_isTopSmooTight;   //!
   TBranch        *b_pt_jet_largeR_0;   //!
   TBranch        *b_m_jet_largeR_0;   //!
   TBranch        *b_split12_jet_largeR_0;   //!
   TBranch        *b_split23_jet_largeR_0;   //!
   TBranch        *b_nsj_jet_largeR_0;   //!
   TBranch        *b_topTag_Loose_jet_largeR_0;   //!
   TBranch        *b_topTag_Tight_jet_largeR_0;   //!
   TBranch        *b_topTag_SmoothLoose_jet_largeR_0;   //!
   TBranch        *b_topTag_SmoothTight_jet_largeR_0;   //!
   TBranch        *b_pt_jet_largeR_1;   //!
   TBranch        *b_m_jet_largeR_1;   //!
   TBranch        *b_split12_jet_largeR_1;   //!
   TBranch        *b_split23_jet_largeR_1;   //!
   TBranch        *b_nsj_jet_largeR_1;   //!
   TBranch        *b_topTag_Loose_jet_largeR_1;   //!
   TBranch        *b_topTag_Tight_jet_largeR_1;   //!
   TBranch        *b_topTag_SmoothLoose_jet_largeR_1;   //!
   TBranch        *b_topTag_SmoothTight_jet_largeR_1;   //!
   TBranch        *b_pt_jet_largeR_2;   //!
   TBranch        *b_m_jet_largeR_2;   //!
   TBranch        *b_split12_jet_largeR_2;   //!
   TBranch        *b_split23_jet_largeR_2;   //!
   TBranch        *b_nsj_jet_largeR_2;   //!
   TBranch        *b_topTag_Loose_jet_largeR_2;   //!
   TBranch        *b_topTag_Tight_jet_largeR_2;   //!
   TBranch        *b_topTag_SmoothLoose_jet_largeR_2;   //!
   TBranch        *b_topTag_SmoothTight_jet_largeR_2;   //!
   TBranch        *b_pt_jet_largeR_3;   //!
   TBranch        *b_m_jet_largeR_3;   //!
   TBranch        *b_split12_jet_largeR_3;   //!
   TBranch        *b_split23_jet_largeR_3;   //!
   TBranch        *b_nsj_jet_largeR_3;   //!
   TBranch        *b_topTag_Loose_jet_largeR_3;   //!
   TBranch        *b_topTag_Tight_jet_largeR_3;   //!
   TBranch        *b_topTag_SmoothLoose_jet_largeR_3;   //!
   TBranch        *b_topTag_SmoothTight_jet_largeR_3;   //!
   TBranch        *b_razor_ss_mass;   //!
   TBranch        *b_razor_ss_invgamma;   //!
   TBranch        *b_razor_ss_dphivis;   //!
   TBranch        *b_razor_ss_costheta;   //!
   TBranch        *b_razor_ss_dphidecayangle;   //!
   TBranch        *b_razor_ss_mdeltaR;   //!
   TBranch        *b_razor_s1_mass;   //!
   TBranch        *b_razor_s1_costheta;   //!
   TBranch        *b_razor_s2_mass;   //!
   TBranch        *b_razor_s2_costheta;   //!
   TBranch        *b_razor_i1_depth;   //!
   TBranch        *b_razor_i2_depth;   //!
   TBranch        *b_razor_v1_nelements;   //!
   TBranch        *b_razor_v2_nelements;   //!
   TBranch        *b_razor_ss_abs_costheta;   //!
   TBranch        *b_razor_s1_abs_costheta;   //!
   TBranch        *b_razor_s2_abs_costheta;   //!

   ChicagoBase(TTree *tree=0);
   virtual ~ChicagoBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef ChicagoBase_cxx
ChicagoBase::ChicagoBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("test_RJworkshop.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("test_RJworkshop.root");
      }
      f->GetObject("oTree",tree);

   }
   Init(tree);
}

ChicagoBase::~ChicagoBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ChicagoBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ChicagoBase::LoadTree(Long64_t entry)
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

void ChicagoBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_m = 0;
   jet_isB = 0;
   jet_largeR_pt = 0;
   jet_largeR_eta = 0;
   jet_largeR_phi = 0;
   jet_largeR_m = 0;
   jet_largeR_isTopLoose = 0;
   jet_largeR_isTopTight = 0;
   jet_largeR_isTopSmooLoose = 0;
   jet_largeR_isTopSmooTight = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event_weight", &event_weight, &b_event_weight);
   fChain->SetBranchAddress("event_number", &event_number, &b_event_number);
   fChain->SetBranchAddress("m_transverse", &m_transverse, &b_m_transverse);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("met_px", &met_px, &b_met_mpx);
   fChain->SetBranchAddress("met_py", &met_py, &b_met_mpy);
   fChain->SetBranchAddress("m_effective", &m_effective, &b_m_effective);
   fChain->SetBranchAddress("dPhiMETMin", &dPhiMETMin, &b_dPhiMETMin);
   fChain->SetBranchAddress("mTb", &mTb, &b_mTb);
   fChain->SetBranchAddress("pt_total", &pt_total, &b_pt_total);
   fChain->SetBranchAddress("multiplicity_jet", &multiplicity_jet, &b_multiplicity_jet);
   fChain->SetBranchAddress("multiplicity_jet_b", &multiplicity_jet_b, &b_multiplicity_jet_b);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_m", &jet_m, &b_jet_m);
   fChain->SetBranchAddress("jet_isB", &jet_isB, &b_jet_isB);
   fChain->SetBranchAddress("pt_jet_rc8_0", &pt_jet_rc8_0, &b_pt_jet_rc8_0);
   fChain->SetBranchAddress("m_jet_rc8_0", &m_jet_rc8_0, &b_m_jet_rc8_0);
   fChain->SetBranchAddress("split12_jet_rc8_0", &split12_jet_rc8_0, &b_split12_jet_rc8_0);
   fChain->SetBranchAddress("split23_jet_rc8_0", &split23_jet_rc8_0, &b_split23_jet_rc8_0);
   fChain->SetBranchAddress("nsj_jet_rc8_0", &nsj_jet_rc8_0, &b_nsj_jet_rc8_0);
   fChain->SetBranchAddress("pt_jet_rc10_0", &pt_jet_rc10_0, &b_pt_jet_rc10_0);
   fChain->SetBranchAddress("m_jet_rc10_0", &m_jet_rc10_0, &b_m_jet_rc10_0);
   fChain->SetBranchAddress("split12_jet_rc10_0", &split12_jet_rc10_0, &b_split12_jet_rc10_0);
   fChain->SetBranchAddress("split23_jet_rc10_0", &split23_jet_rc10_0, &b_split23_jet_rc10_0);
   fChain->SetBranchAddress("nsj_jet_rc10_0", &nsj_jet_rc10_0, &b_nsj_jet_rc10_0);
   fChain->SetBranchAddress("pt_jet_rc12_0", &pt_jet_rc12_0, &b_pt_jet_rc12_0);
   fChain->SetBranchAddress("m_jet_rc12_0", &m_jet_rc12_0, &b_m_jet_rc12_0);
   fChain->SetBranchAddress("split12_jet_rc12_0", &split12_jet_rc12_0, &b_split12_jet_rc12_0);
   fChain->SetBranchAddress("split23_jet_rc12_0", &split23_jet_rc12_0, &b_split23_jet_rc12_0);
   fChain->SetBranchAddress("nsj_jet_rc12_0", &nsj_jet_rc12_0, &b_nsj_jet_rc12_0);
   fChain->SetBranchAddress("pt_jet_rc8_1", &pt_jet_rc8_1, &b_pt_jet_rc8_1);
   fChain->SetBranchAddress("m_jet_rc8_1", &m_jet_rc8_1, &b_m_jet_rc8_1);
   fChain->SetBranchAddress("split12_jet_rc8_1", &split12_jet_rc8_1, &b_split12_jet_rc8_1);
   fChain->SetBranchAddress("split23_jet_rc8_1", &split23_jet_rc8_1, &b_split23_jet_rc8_1);
   fChain->SetBranchAddress("nsj_jet_rc8_1", &nsj_jet_rc8_1, &b_nsj_jet_rc8_1);
   fChain->SetBranchAddress("pt_jet_rc10_1", &pt_jet_rc10_1, &b_pt_jet_rc10_1);
   fChain->SetBranchAddress("m_jet_rc10_1", &m_jet_rc10_1, &b_m_jet_rc10_1);
   fChain->SetBranchAddress("split12_jet_rc10_1", &split12_jet_rc10_1, &b_split12_jet_rc10_1);
   fChain->SetBranchAddress("split23_jet_rc10_1", &split23_jet_rc10_1, &b_split23_jet_rc10_1);
   fChain->SetBranchAddress("nsj_jet_rc10_1", &nsj_jet_rc10_1, &b_nsj_jet_rc10_1);
   fChain->SetBranchAddress("pt_jet_rc12_1", &pt_jet_rc12_1, &b_pt_jet_rc12_1);
   fChain->SetBranchAddress("m_jet_rc12_1", &m_jet_rc12_1, &b_m_jet_rc12_1);
   fChain->SetBranchAddress("split12_jet_rc12_1", &split12_jet_rc12_1, &b_split12_jet_rc12_1);
   fChain->SetBranchAddress("split23_jet_rc12_1", &split23_jet_rc12_1, &b_split23_jet_rc12_1);
   fChain->SetBranchAddress("nsj_jet_rc12_1", &nsj_jet_rc12_1, &b_nsj_jet_rc12_1);
   fChain->SetBranchAddress("pt_jet_rc8_2", &pt_jet_rc8_2, &b_pt_jet_rc8_2);
   fChain->SetBranchAddress("m_jet_rc8_2", &m_jet_rc8_2, &b_m_jet_rc8_2);
   fChain->SetBranchAddress("split12_jet_rc8_2", &split12_jet_rc8_2, &b_split12_jet_rc8_2);
   fChain->SetBranchAddress("split23_jet_rc8_2", &split23_jet_rc8_2, &b_split23_jet_rc8_2);
   fChain->SetBranchAddress("nsj_jet_rc8_2", &nsj_jet_rc8_2, &b_nsj_jet_rc8_2);
   fChain->SetBranchAddress("pt_jet_rc10_2", &pt_jet_rc10_2, &b_pt_jet_rc10_2);
   fChain->SetBranchAddress("m_jet_rc10_2", &m_jet_rc10_2, &b_m_jet_rc10_2);
   fChain->SetBranchAddress("split12_jet_rc10_2", &split12_jet_rc10_2, &b_split12_jet_rc10_2);
   fChain->SetBranchAddress("split23_jet_rc10_2", &split23_jet_rc10_2, &b_split23_jet_rc10_2);
   fChain->SetBranchAddress("nsj_jet_rc10_2", &nsj_jet_rc10_2, &b_nsj_jet_rc10_2);
   fChain->SetBranchAddress("pt_jet_rc12_2", &pt_jet_rc12_2, &b_pt_jet_rc12_2);
   fChain->SetBranchAddress("m_jet_rc12_2", &m_jet_rc12_2, &b_m_jet_rc12_2);
   fChain->SetBranchAddress("split12_jet_rc12_2", &split12_jet_rc12_2, &b_split12_jet_rc12_2);
   fChain->SetBranchAddress("split23_jet_rc12_2", &split23_jet_rc12_2, &b_split23_jet_rc12_2);
   fChain->SetBranchAddress("nsj_jet_rc12_2", &nsj_jet_rc12_2, &b_nsj_jet_rc12_2);
   fChain->SetBranchAddress("pt_jet_rc8_3", &pt_jet_rc8_3, &b_pt_jet_rc8_3);
   fChain->SetBranchAddress("m_jet_rc8_3", &m_jet_rc8_3, &b_m_jet_rc8_3);
   fChain->SetBranchAddress("split12_jet_rc8_3", &split12_jet_rc8_3, &b_split12_jet_rc8_3);
   fChain->SetBranchAddress("split23_jet_rc8_3", &split23_jet_rc8_3, &b_split23_jet_rc8_3);
   fChain->SetBranchAddress("nsj_jet_rc8_3", &nsj_jet_rc8_3, &b_nsj_jet_rc8_3);
   fChain->SetBranchAddress("pt_jet_rc10_3", &pt_jet_rc10_3, &b_pt_jet_rc10_3);
   fChain->SetBranchAddress("m_jet_rc10_3", &m_jet_rc10_3, &b_m_jet_rc10_3);
   fChain->SetBranchAddress("split12_jet_rc10_3", &split12_jet_rc10_3, &b_split12_jet_rc10_3);
   fChain->SetBranchAddress("split23_jet_rc10_3", &split23_jet_rc10_3, &b_split23_jet_rc10_3);
   fChain->SetBranchAddress("nsj_jet_rc10_3", &nsj_jet_rc10_3, &b_nsj_jet_rc10_3);
   fChain->SetBranchAddress("pt_jet_rc12_3", &pt_jet_rc12_3, &b_pt_jet_rc12_3);
   fChain->SetBranchAddress("m_jet_rc12_3", &m_jet_rc12_3, &b_m_jet_rc12_3);
   fChain->SetBranchAddress("split12_jet_rc12_3", &split12_jet_rc12_3, &b_split12_jet_rc12_3);
   fChain->SetBranchAddress("split23_jet_rc12_3", &split23_jet_rc12_3, &b_split23_jet_rc12_3);
   fChain->SetBranchAddress("nsj_jet_rc12_3", &nsj_jet_rc12_3, &b_nsj_jet_rc12_3);
   fChain->SetBranchAddress("multiplicity_jet_varR_top", &multiplicity_jet_varR_top, &b_multiplicity_jet_varR_top);
   fChain->SetBranchAddress("multiplicity_jet_varR_W", &multiplicity_jet_varR_W, &b_multiplicity_jet_varR_W);
   fChain->SetBranchAddress("m_variableR_top_jet_0", &m_variableR_top_jet_0, &b_m_variableR_top_jet_0);
   fChain->SetBranchAddress("m_variableR_W_jet_0", &m_variableR_W_jet_0, &b_m_variableR_W_jet_0);
   fChain->SetBranchAddress("pt_variableR_top_jet_0", &pt_variableR_top_jet_0, &b_pt_variableR_top_jet_0);
   fChain->SetBranchAddress("pt_variableR_W_jet_0", &pt_variableR_W_jet_0, &b_pt_variableR_W_jet_0);
   fChain->SetBranchAddress("nsj_variableR_top_jet_0", &nsj_variableR_top_jet_0, &b_nsj_variableR_top_jet_0);
   fChain->SetBranchAddress("nsj_variableR_W_jet_0", &nsj_variableR_W_jet_0, &b_nsj_variableR_W_jet_0);
   fChain->SetBranchAddress("m_variableR_top_jet_1", &m_variableR_top_jet_1, &b_m_variableR_top_jet_1);
   fChain->SetBranchAddress("m_variableR_W_jet_1", &m_variableR_W_jet_1, &b_m_variableR_W_jet_1);
   fChain->SetBranchAddress("pt_variableR_top_jet_1", &pt_variableR_top_jet_1, &b_pt_variableR_top_jet_1);
   fChain->SetBranchAddress("pt_variableR_W_jet_1", &pt_variableR_W_jet_1, &b_pt_variableR_W_jet_1);
   fChain->SetBranchAddress("nsj_variableR_top_jet_1", &nsj_variableR_top_jet_1, &b_nsj_variableR_top_jet_1);
   fChain->SetBranchAddress("nsj_variableR_W_jet_1", &nsj_variableR_W_jet_1, &b_nsj_variableR_W_jet_1);
   fChain->SetBranchAddress("m_variableR_top_jet_2", &m_variableR_top_jet_2, &b_m_variableR_top_jet_2);
   fChain->SetBranchAddress("m_variableR_W_jet_2", &m_variableR_W_jet_2, &b_m_variableR_W_jet_2);
   fChain->SetBranchAddress("pt_variableR_top_jet_2", &pt_variableR_top_jet_2, &b_pt_variableR_top_jet_2);
   fChain->SetBranchAddress("pt_variableR_W_jet_2", &pt_variableR_W_jet_2, &b_pt_variableR_W_jet_2);
   fChain->SetBranchAddress("nsj_variableR_top_jet_2", &nsj_variableR_top_jet_2, &b_nsj_variableR_top_jet_2);
   fChain->SetBranchAddress("nsj_variableR_W_jet_2", &nsj_variableR_W_jet_2, &b_nsj_variableR_W_jet_2);
   fChain->SetBranchAddress("m_variableR_top_jet_3", &m_variableR_top_jet_3, &b_m_variableR_top_jet_3);
   fChain->SetBranchAddress("m_variableR_W_jet_3", &m_variableR_W_jet_3, &b_m_variableR_W_jet_3);
   fChain->SetBranchAddress("pt_variableR_top_jet_3", &pt_variableR_top_jet_3, &b_pt_variableR_top_jet_3);
   fChain->SetBranchAddress("pt_variableR_W_jet_3", &pt_variableR_W_jet_3, &b_pt_variableR_W_jet_3);
   fChain->SetBranchAddress("nsj_variableR_top_jet_3", &nsj_variableR_top_jet_3, &b_nsj_variableR_top_jet_3);
   fChain->SetBranchAddress("nsj_variableR_W_jet_3", &nsj_variableR_W_jet_3, &b_nsj_variableR_W_jet_3);
   fChain->SetBranchAddress("multiplicity_jet_largeR", &multiplicity_jet_largeR, &b_multiplicity_jet_largeR);
   fChain->SetBranchAddress("multiplicity_topTag_smoothloose", &multiplicity_topTag_smoothloose, &b_multiplicity_topTag_smoothloose);
   fChain->SetBranchAddress("multiplicity_topTag_smoothtight", &multiplicity_topTag_smoothtight, &b_multiplicity_topTag_smoothtight);
   fChain->SetBranchAddress("multiplicity_topTag_loose", &multiplicity_topTag_loose, &b_multiplicity_topTag_loose);
   fChain->SetBranchAddress("multiplicity_topTag_tight", &multiplicity_topTag_tight, &b_multiplicity_topTag_tight);
   fChain->SetBranchAddress("jet_largeR_pt", &jet_largeR_pt, &b_jet_largeR_pt);
   fChain->SetBranchAddress("jet_largeR_eta", &jet_largeR_eta, &b_jet_largeR_eta);
   fChain->SetBranchAddress("jet_largeR_phi", &jet_largeR_phi, &b_jet_largeR_phi);
   fChain->SetBranchAddress("jet_largeR_m", &jet_largeR_m, &b_jet_largeR_m);
   fChain->SetBranchAddress("jet_largeR_isTopLoose", &jet_largeR_isTopLoose, &b_jet_largeR_isTopLoose);
   fChain->SetBranchAddress("jet_largeR_isTopTight", &jet_largeR_isTopTight, &b_jet_largeR_isTopTight);
   fChain->SetBranchAddress("jet_largeR_isTopSmooLoose", &jet_largeR_isTopSmooLoose, &b_jet_largeR_isTopSmooLoose);
   fChain->SetBranchAddress("jet_largeR_isTopSmooTight", &jet_largeR_isTopSmooTight, &b_jet_largeR_isTopSmooTight);
   fChain->SetBranchAddress("pt_jet_largeR_0", &pt_jet_largeR_0, &b_pt_jet_largeR_0);
   fChain->SetBranchAddress("m_jet_largeR_0", &m_jet_largeR_0, &b_m_jet_largeR_0);
   fChain->SetBranchAddress("split12_jet_largeR_0", &split12_jet_largeR_0, &b_split12_jet_largeR_0);
   fChain->SetBranchAddress("split23_jet_largeR_0", &split23_jet_largeR_0, &b_split23_jet_largeR_0);
   fChain->SetBranchAddress("nsj_jet_largeR_0", &nsj_jet_largeR_0, &b_nsj_jet_largeR_0);
   fChain->SetBranchAddress("topTag_Loose_jet_largeR_0", &topTag_Loose_jet_largeR_0, &b_topTag_Loose_jet_largeR_0);
   fChain->SetBranchAddress("topTag_Tight_jet_largeR_0", &topTag_Tight_jet_largeR_0, &b_topTag_Tight_jet_largeR_0);
   fChain->SetBranchAddress("topTag_SmoothLoose_jet_largeR_0", &topTag_SmoothLoose_jet_largeR_0, &b_topTag_SmoothLoose_jet_largeR_0);
   fChain->SetBranchAddress("topTag_SmoothTight_jet_largeR_0", &topTag_SmoothTight_jet_largeR_0, &b_topTag_SmoothTight_jet_largeR_0);
   fChain->SetBranchAddress("pt_jet_largeR_1", &pt_jet_largeR_1, &b_pt_jet_largeR_1);
   fChain->SetBranchAddress("m_jet_largeR_1", &m_jet_largeR_1, &b_m_jet_largeR_1);
   fChain->SetBranchAddress("split12_jet_largeR_1", &split12_jet_largeR_1, &b_split12_jet_largeR_1);
   fChain->SetBranchAddress("split23_jet_largeR_1", &split23_jet_largeR_1, &b_split23_jet_largeR_1);
   fChain->SetBranchAddress("nsj_jet_largeR_1", &nsj_jet_largeR_1, &b_nsj_jet_largeR_1);
   fChain->SetBranchAddress("topTag_Loose_jet_largeR_1", &topTag_Loose_jet_largeR_1, &b_topTag_Loose_jet_largeR_1);
   fChain->SetBranchAddress("topTag_Tight_jet_largeR_1", &topTag_Tight_jet_largeR_1, &b_topTag_Tight_jet_largeR_1);
   fChain->SetBranchAddress("topTag_SmoothLoose_jet_largeR_1", &topTag_SmoothLoose_jet_largeR_1, &b_topTag_SmoothLoose_jet_largeR_1);
   fChain->SetBranchAddress("topTag_SmoothTight_jet_largeR_1", &topTag_SmoothTight_jet_largeR_1, &b_topTag_SmoothTight_jet_largeR_1);
   fChain->SetBranchAddress("pt_jet_largeR_2", &pt_jet_largeR_2, &b_pt_jet_largeR_2);
   fChain->SetBranchAddress("m_jet_largeR_2", &m_jet_largeR_2, &b_m_jet_largeR_2);
   fChain->SetBranchAddress("split12_jet_largeR_2", &split12_jet_largeR_2, &b_split12_jet_largeR_2);
   fChain->SetBranchAddress("split23_jet_largeR_2", &split23_jet_largeR_2, &b_split23_jet_largeR_2);
   fChain->SetBranchAddress("nsj_jet_largeR_2", &nsj_jet_largeR_2, &b_nsj_jet_largeR_2);
   fChain->SetBranchAddress("topTag_Loose_jet_largeR_2", &topTag_Loose_jet_largeR_2, &b_topTag_Loose_jet_largeR_2);
   fChain->SetBranchAddress("topTag_Tight_jet_largeR_2", &topTag_Tight_jet_largeR_2, &b_topTag_Tight_jet_largeR_2);
   fChain->SetBranchAddress("topTag_SmoothLoose_jet_largeR_2", &topTag_SmoothLoose_jet_largeR_2, &b_topTag_SmoothLoose_jet_largeR_2);
   fChain->SetBranchAddress("topTag_SmoothTight_jet_largeR_2", &topTag_SmoothTight_jet_largeR_2, &b_topTag_SmoothTight_jet_largeR_2);
   fChain->SetBranchAddress("pt_jet_largeR_3", &pt_jet_largeR_3, &b_pt_jet_largeR_3);
   fChain->SetBranchAddress("m_jet_largeR_3", &m_jet_largeR_3, &b_m_jet_largeR_3);
   fChain->SetBranchAddress("split12_jet_largeR_3", &split12_jet_largeR_3, &b_split12_jet_largeR_3);
   fChain->SetBranchAddress("split23_jet_largeR_3", &split23_jet_largeR_3, &b_split23_jet_largeR_3);
   fChain->SetBranchAddress("nsj_jet_largeR_3", &nsj_jet_largeR_3, &b_nsj_jet_largeR_3);
   fChain->SetBranchAddress("topTag_Loose_jet_largeR_3", &topTag_Loose_jet_largeR_3, &b_topTag_Loose_jet_largeR_3);
   fChain->SetBranchAddress("topTag_Tight_jet_largeR_3", &topTag_Tight_jet_largeR_3, &b_topTag_Tight_jet_largeR_3);
   fChain->SetBranchAddress("topTag_SmoothLoose_jet_largeR_3", &topTag_SmoothLoose_jet_largeR_3, &b_topTag_SmoothLoose_jet_largeR_3);
   fChain->SetBranchAddress("topTag_SmoothTight_jet_largeR_3", &topTag_SmoothTight_jet_largeR_3, &b_topTag_SmoothTight_jet_largeR_3);
   fChain->SetBranchAddress("razor_ss_mass", &razor_ss_mass, &b_razor_ss_mass);
   fChain->SetBranchAddress("razor_ss_invgamma", &razor_ss_invgamma, &b_razor_ss_invgamma);
   fChain->SetBranchAddress("razor_ss_dphivis", &razor_ss_dphivis, &b_razor_ss_dphivis);
   fChain->SetBranchAddress("razor_ss_costheta", &razor_ss_costheta, &b_razor_ss_costheta);
   fChain->SetBranchAddress("razor_ss_dphidecayangle", &razor_ss_dphidecayangle, &b_razor_ss_dphidecayangle);
   fChain->SetBranchAddress("razor_ss_mdeltaR", &razor_ss_mdeltaR, &b_razor_ss_mdeltaR);
   fChain->SetBranchAddress("razor_s1_mass", &razor_s1_mass, &b_razor_s1_mass);
   fChain->SetBranchAddress("razor_s1_costheta", &razor_s1_costheta, &b_razor_s1_costheta);
   fChain->SetBranchAddress("razor_s2_mass", &razor_s2_mass, &b_razor_s2_mass);
   fChain->SetBranchAddress("razor_s2_costheta", &razor_s2_costheta, &b_razor_s2_costheta);
   fChain->SetBranchAddress("razor_i1_depth", &razor_i1_depth, &b_razor_i1_depth);
   fChain->SetBranchAddress("razor_i2_depth", &razor_i2_depth, &b_razor_i2_depth);
   fChain->SetBranchAddress("razor_v1_nelements", &razor_v1_nelements, &b_razor_v1_nelements);
   fChain->SetBranchAddress("razor_v2_nelements", &razor_v2_nelements, &b_razor_v2_nelements);
   fChain->SetBranchAddress("razor_ss_abs_costheta", &razor_ss_abs_costheta, &b_razor_ss_abs_costheta);
   fChain->SetBranchAddress("razor_s1_abs_costheta", &razor_s1_abs_costheta, &b_razor_s1_abs_costheta);
   fChain->SetBranchAddress("razor_s2_abs_costheta", &razor_s2_abs_costheta, &b_razor_s2_abs_costheta);
   Notify();
}

Bool_t ChicagoBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ChicagoBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ChicagoBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef ChicagoBase_cxx
