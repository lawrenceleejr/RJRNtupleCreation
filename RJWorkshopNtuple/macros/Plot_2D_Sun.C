#include <iostream>
#include <string>

#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TH2D.h>
#include <TStyle.h>

#include "include/SunBase.hh"

#include "RestFrames/RestFrames.hh"

using namespace std;

vector<string> g_File;
vector<string> g_Tree;
vector<string> g_Title;
vector<double> g_Scale;
string g_PlotTitle;
string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;
string g_Yname;
double g_Ymin;
double g_Ymax;
double g_NY;

using namespace RestFrames;

void Plot_2D_Sun(){
  HistPlot::SetStyle();

  int SKIP = 1;

  // g_PlotTitle = "leptonic t #bar{t}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP/ttbar_lep.root");
  // g_Tree.push_back("FiducialEventsTree");
  // g_Scale.push_back(1.);
  // SKIP = 1;

  // g_PlotTitle = "hadronic t #bar{t}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP/ttbar_had.root");
  // g_Tree.push_back("FiducialEventsTree");
  // g_Scale.push_back(1.);

  // g_PlotTitle = "Z+jets";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP/Zjets_nunu.root");
  // g_Tree.push_back("FiducialEventsTree");
  // g_Scale.push_back(1.);
  // SKIP = 1;

  g_PlotTitle = "QCD multijets";
  g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP/QCD.root");
  g_Tree.push_back("FiducialEventsTree");
  g_Scale.push_back(1.);
  SKIP = 1;

  // g_PlotTitle = "W+jets";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP/Wjets_lep.root");
  // g_Tree.push_back("FiducialEventsTree");
  // g_Scale.push_back(1.);
  // SKIP = 1;

  // g_PlotTitle = "#tilde{t} #tilde{t} #rightarrow (bW #tilde{#chi})(bW #tilde{#chi}) #scale[0.75]{m_{#tilde{t}}=450,m_{#tilde{#chi}}=278}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP/TT_450_278.root");
  // g_Tree.push_back("FiducialEventsTree");
  // g_Scale.push_back(-1.);

  // g_PlotTitle = "#tilde{t} #tilde{t} #rightarrow (bW #tilde{#chi})(bW #tilde{#chi}) #scale[0.75]{m_{#tilde{t}}=350,m_{#tilde{#chi}}=150}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP/TT_350_150.root");
  // g_Tree.push_back("FiducialEventsTree");
  // g_Scale.push_back(-1.);

  // g_PlotTitle = "#tilde{t} #tilde{t} #rightarrow (bW #tilde{#chi})(bW #tilde{#chi}) #scale[0.75]{m_{#tilde{t}}=400,m_{#tilde{#chi}}=228}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP/TT_400_228.root");
  // g_Tree.push_back("FiducialEventsTree");
  // g_Scale.push_back(-1.);

  int Nsample = g_File.size();

  //string g_Label = "#splitline{H_{2,1}^{ Pi} > 400 GeV H_{1,1}^{ PP} > 500 GeV}{H_{T 4,2}^{ PP} > 1000 GeV}";
  string g_Label = "#splitline{Baseline + p_{T}^{ISR} > 600 + N_{b}^{ V} > 0}{+ #vec{p}_{T I}^{ CM}. #hat{p}_{T ISR}^{ CM} / p_{T ISR}^{ CM} > 0.6}";

  //g_Xname = "#vec{p}_{T I}^{ CM}. #hat{p}_{T ISR}^{ CM} / p_{T ISR}^{ CM}";
  g_Xname = "RISR";
  g_Xmin = 0.0;
  g_Xmax = 1.; 
  g_NX = 20;
  g_Yname = "dphiCMV";
  g_Ymin = 0.;
  g_Ymax = acos(-1.);
  g_NY = 20;

  TH2D* hist = new TH2D("hist","hist",
			g_NX,g_Xmin,g_Xmax,
			g_NY,g_Ymin,g_Ymax);

  /////////////////////////////////////////////////

  // Define the frames in our reconstruction tree
  LabRecoFrame       LAB("LAB","lab");
  DecayRecoFrame     CM("CM","CM");
  DecayRecoFrame     S("S","S");
  VisibleRecoFrame   ISR("ISR","ISR");
  VisibleRecoFrame   V("V","Vis");
  InvisibleRecoFrame I("I","Inv");

  // connect the tree according to our interpretation
  LAB.SetChildFrame(CM);
  CM.AddChildFrame(ISR);
  CM.AddChildFrame(S);
  S.AddChildFrame(V);
  S.AddChildFrame(I);

  // Initialize the tree skeleton (check for problems)
  if(!LAB.InitializeTree())
    cout << "PROBLEM with reco tree structure" << endl;

  InvisibleGroup INV("INV","Invisible System");
  INV.AddFrame(I);

  CombinatoricGroup VIS("VIS","Visible Objects");
  VIS.AddFrame(ISR);
  VIS.SetNElementsForFrame(ISR,1,false);
  VIS.AddFrame(V);
  VIS.SetNElementsForFrame(V,0,false);

  // set the invisible system mass to zero
  SetMassInvJigsaw InvMass("InvMass", "Invisible system mass Jigsaw");
  INV.AddJigsaw(InvMass);

  // define the rule for partitioning objects between "ISR" and "V"
  MinMassesCombJigsaw SplitVis("SplitVis","Minimize M_{ISR} and M_{S} Jigsaw");
  VIS.AddJigsaw(SplitVis);
  // "0" group (ISR)
  SplitVis.AddFrame(ISR, 0);
  // "1" group (V + I)
  SplitVis.AddFrame(V,1);
  SplitVis.AddFrame(I,1);

  if(!LAB.InitializeAnalysis())
    cout << "PROBLEM with analysis set-up of tree" << endl;
 
  LabRecoFrame LAB_bkg("LAB","lab");
  SelfAssemblingRecoFrame S_bkg("CM","CM");
  VisibleRecoFrame V_bkg("V_bkg","Vis");
  InvisibleRecoFrame I_bkg("I_bkg","Inv");
  LAB_bkg.SetChildFrame(S_bkg);
  S_bkg.AddChildFrame(V_bkg);
  S_bkg.AddChildFrame(I_bkg);
  LAB_bkg.InitializeTree(); 
  InvisibleGroup INV_bkg("INV_bkg","Invisible State Jigsaws");
  INV_bkg.AddFrame(I_bkg);
  CombinatoricGroup VIS_bkg("VIS_bkg","Visible Object Jigsaws");
  VIS_bkg.AddFrame(V_bkg);
  VIS_bkg.SetNElementsForFrame(V_bkg,1,false);
  SetMassInvJigsaw InvMass_bkg("InvMass_bkg", "Invisible system mass Jigsaw");
  INV_bkg.AddJigsaw(InvMass_bkg);
  SetRapidityInvJigsaw InvRapidity_bkg("InvRapidity_bkg", "Invisible system rapidity Jigsaw");
  INV_bkg.AddJigsaw(InvRapidity_bkg);
  InvRapidity_bkg.AddVisibleFrames(LAB_bkg.GetListVisibleFrames());
  LAB_bkg.InitializeAnalysis(); 

  /////////////////////////////////////////////////////////

  HistPlot* hist_plot = new HistPlot("Hist",  g_PlotTitle, g_Label); 
  hist_plot->SetScale(1.);
  hist_plot->SetScaleLabel("N_{evt} / bin / fb^{-1}");

  const HistPlotVar& Nj_ISR = hist_plot->GetNewVar("NjISR","N_{j}^{ISR}",-0.5,8.5);
  const HistPlotVar& Nj_V = hist_plot->GetNewVar("NjV","N_{j}^{V}",-0.5,8.5);
  const HistPlotVar& Nb_ISR = hist_plot->GetNewVar("NbISR","N_{b}^{ISR}",-0.5,4.5);
  const HistPlotVar& Nb_V = hist_plot->GetNewVar("NbV","N_{b}^{V}",-0.5,4.5);
  const HistPlotVar& pT_ISR = hist_plot->GetNewVar("pT_ISR","p_{T ISR}^{ CM}",0.,1500.,"[GeV]");
  const HistPlotVar& pT_I = hist_plot->GetNewVar("pT_I","p_{T I}^{ CM}",0.,1500.,"[GeV]");
  const HistPlotVar& R_ISR = hist_plot->GetNewVar("R_ISR","#vec{p}_{T I}^{ CM}. #hat{p}_{T ISR}^{ CM} / p_{T ISR}^{ CM}",0.,1.);
  const HistPlotVar& cosS = hist_plot->GetNewVar("cosS","cos #theta_{S}",-1., 1.);  
  const HistPlotVar& MS = hist_plot->GetNewVar("MS","M_{S}",0.,1500.,"[GeV]");
  const HistPlotVar& MV = hist_plot->GetNewVar("MV","M_{V}",0.,1500.,"[GeV]");
  const HistPlotVar& MISR = hist_plot->GetNewVar("MISR","M_{ISR}",0.,1500.,"[GeV]");
  const HistPlotVar& MVoMS = hist_plot->GetNewVar("MVoMS","M_{V} / M_{S}",0.,1.1);

  hist_plot->AddHist(Nj_ISR);
  hist_plot->AddHist(Nj_V);
  hist_plot->AddHist(Nb_ISR);
  hist_plot->AddHist(Nb_V);
  hist_plot->AddHist(pT_ISR);
  hist_plot->AddHist(pT_I);
  hist_plot->AddHist(R_ISR);
  hist_plot->AddHist(cosS);
  hist_plot->AddHist(MS);
  hist_plot->AddHist(MV);
  hist_plot->AddHist(MISR);
  hist_plot->AddHist(MVoMS);

  hist_plot->AddHist(Nj_ISR, pT_ISR);
  hist_plot->AddHist(Nj_V, pT_ISR);
  hist_plot->AddHist(Nb_ISR, pT_ISR);
  hist_plot->AddHist(Nb_V, pT_ISR);
  hist_plot->AddHist(pT_I, pT_ISR);
  hist_plot->AddHist(R_ISR, pT_ISR);
  hist_plot->AddHist(cosS, pT_ISR);
  hist_plot->AddHist(MS, pT_ISR);
  hist_plot->AddHist(MV, pT_ISR);
  hist_plot->AddHist(MISR, pT_ISR);
  hist_plot->AddHist(MVoMS, pT_ISR);
  
  hist_plot->AddHist(Nj_ISR, R_ISR);
  hist_plot->AddHist(Nj_V, R_ISR);
  hist_plot->AddHist(Nb_ISR, R_ISR);
  hist_plot->AddHist(Nb_V, R_ISR);
  hist_plot->AddHist(pT_I, R_ISR);
  hist_plot->AddHist(cosS, R_ISR);
  hist_plot->AddHist(MS, R_ISR);
  hist_plot->AddHist(MV, R_ISR);
  hist_plot->AddHist(MISR, R_ISR);
  hist_plot->AddHist(MVoMS, R_ISR);

  TreePlot* tree_plot = new TreePlot("TreePlot","TreePlot");

  //////////////////////////////////////////////////////////////////

  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain(g_Tree[s].c_str());
    chain->Add(g_File[s].c_str());

    SunBase* base = new SunBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      if(e%SKIP != 0) continue;
      if(e%(max(1,Nentry/10)) == 0)
	cout << "Event " << e << " | " << Nentry << endl;
      base->GetEntry(e);

      vector<TLorentzVector> JETs;
      vector<bool> JETs_btag;

      int Njet = base->m_jet_n;
      if(Njet < 2) continue;

      double HT = 0.;

      for(int i = 0; i < Njet; i++){
	if((base->m_jet_pt->at(i) >= 30.) && (fabs(base->m_jet_eta->at(i)) < 2.8)){
	  TLorentzVector JET;
	  JET.SetPtEtaPhiE(base->m_jet_pt->at(i),base->m_jet_eta->at(i),base->m_jet_phi->at(i), base->m_jet_E->at(i));
	  JETs.push_back(JET);
	  JETs_btag.push_back(base->m_jet_btag->at(i));
	  HT += base->m_jet_pt->at(i);
	}
      }

      if(JETs.size() < 2) continue;

      TVector3 MET;
      MET.SetPtEtaPhi(base->m_met_Et,0.0,base->m_met_phi);

      LAB.ClearEvent();
      vector<RFKey> jetID; 
      for(int i = 0; i < int(JETs.size()); i++){
	TLorentzVector jet = JETs[i];
	jet.SetPtEtaPhiM(jet.Pt(),0.0,jet.Phi(),jet.M());
	jetID.push_back(VIS.AddLabFrameFourVector(jet));
      }
      INV.SetLabFrameThreeVector(MET);
      if(!LAB.AnalyzeEvent()) 
	cout << "PROBLEM with event analysis" << endl;

      /*
      LAB_bkg.ClearEvent();
      vector<RFKey> jetID_bkg; 
      for(int i = 0; i < int(JETs.size()); i++){
	TLorentzVector jet = JETs[i];
	jet.SetPtEtaPhiM(jet.Pt(),0.0,jet.Phi(),jet.M());
	jetID_bkg.push_back(VIS_bkg.AddLabFrameFourVector(JETs[i]));
      }
      INV_bkg.SetLabFrameThreeVector(MET);
      if(!LAB_bkg.AnalyzeEvent()) cout << "Something went wrong..." << endl;

      // QCD clean-up
      TLorentzVector Psib = I_bkg.GetSiblingFrame().GetFourVector(LAB_bkg);
      TLorentzVector Pmet = I_bkg.GetFourVector(LAB_bkg);
      
      double Rsib = max(0.,Psib.Vect().Dot(Pmet.Vect().Unit()));
      Rsib = Rsib / (Pmet.Pt() + Rsib);
      
      TVector3 boostQCD = (Pmet+Psib).BoostVector();
      Psib.Boost(-boostQCD);
      double cosQCD = -1.*Psib.Vect().Unit().Dot(boostQCD.Unit());
      cosQCD = (1.-cosQCD)/2.;
      double deltaQCD = (cosQCD-Rsib)/(cosQCD+Rsib); 
      */

      //// calculate observables from tree ////
      Nj_ISR = VIS.GetNElementsInFrame(ISR);
      Nj_V   = VIS.GetNElementsInFrame(V);

      int temp_ISR = 0;
      int temp_V = 0;
      Nb_ISR = 0;
      Nb_V   = 0;

      // count jets in hemispheres
      int Nj = jetID.size();
      for(int i = 0; i < Nj; i++){
	if(VIS.GetFrame(jetID[i]) == ISR){ // ISR group
	  temp_ISR++;
	  if(JETs_btag[i])
	    Nb_ISR = Nb_ISR+1;
	} else {                           // sparticle group
	  temp_V++;
	  if(JETs_btag[i])
	    Nb_V = Nb_V+1;
	}
      }

      if(Nj_V < 1)
	continue;

      TVector3 vP_ISR = ISR.GetFourVector(CM).Vect();
      TVector3 vP_I   = I.GetFourVector(CM).Vect();

      // if(vP_ISR.Pt() < 700.)
      // 	continue;

      pT_ISR = vP_ISR.Mag();
      pT_I   = vP_I.Mag();
      R_ISR = fabs(vP_I.Dot(vP_ISR.Unit())) / pT_ISR;
      cosS = S.GetCosDecayAngle();
      MS = S.GetMass();
      MV = V.GetMass();
      MISR = ISR.GetMass();
      MVoMS = MV/MS;

      double dphiCMV = CM.GetDeltaPhiBoostVisible();
      double Rpt = CM.GetFourVector().Pt();
      Rpt = Rpt / (Rpt + MS);

      if(pT_ISR < 600.)
	continue;

      // if(R_ISR < 0.6)
      // 	continue;

      if(Nb_V < 1)
	continue;

      double ETISR = sqrt(MISR*MISR+pT_ISR*pT_ISR);

      hist->Fill(R_ISR, 
		 dphiCMV, base->m_weight*g_Scale[s]);
      //hist_plot->Fill(base->m_weight*g_Scale[s]);
    }

    delete base;
    delete chain;
  }

  // hist_plot->Draw();
  // hist_plot->WriteOutput((g_Tree[0]+".root").c_str());

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
    TCanvas* can = (TCanvas*) new TCanvas("can","can",700.,600);

    can->SetLeftMargin(0.15);
    can->SetRightMargin(0.22);
    can->SetBottomMargin(0.15);
    can->SetGridx();
    can->SetGridy();
    can->SetLogz();
    can->Draw();
    can->cd();
    hist->Draw("COLZ");
    hist->GetXaxis()->CenterTitle();
    hist->GetXaxis()->SetTitleFont(132);
    hist->GetXaxis()->SetTitleSize(0.06);
    hist->GetXaxis()->SetTitleOffset(1.06);
    hist->GetXaxis()->SetLabelFont(132);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetXaxis()->SetTitle(g_Xname.c_str());
    hist->GetYaxis()->CenterTitle();
    hist->GetYaxis()->SetTitleFont(132);
    hist->GetYaxis()->SetTitleSize(0.06);
    hist->GetYaxis()->SetTitleOffset(1.12);
    hist->GetYaxis()->SetLabelFont(132);
    hist->GetYaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetTitle(g_Yname.c_str());
    hist->GetZaxis()->CenterTitle();
    hist->GetZaxis()->SetTitleFont(132);
    hist->GetZaxis()->SetTitleSize(0.06);
    hist->GetZaxis()->SetTitleOffset(1.3);
    hist->GetZaxis()->SetLabelFont(132);
    hist->GetZaxis()->SetLabelSize(0.05);
    hist->GetZaxis()->SetTitle("N_{evt} / bin / fb^{-1}");
    hist->GetZaxis()->SetRangeUser(0.9*hist->GetMinimum(0.0),1.1*hist->GetMaximum());

    TLatex l;
    l.SetTextFont(132);
    l.SetNDC();
    l.SetTextSize(0.05);
    l.SetTextFont(132);
    // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
    l.DrawLatex(0.5,0.943,g_PlotTitle.c_str());
    l.SetTextSize(0.04);
    l.SetTextFont(42);
    l.DrawLatex(0.01,0.943,"#bf{#it{ATLAS}} Internal 13 TeV Simulation");

    l.SetTextSize(0.035);
    l.SetTextFont(132);
    l.DrawLatex(0.64,0.04,g_Label.c_str());


}
