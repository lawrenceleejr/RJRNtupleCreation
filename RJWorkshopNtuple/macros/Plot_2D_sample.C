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

#include "include/ZeroLeptonBase.hh"

#include "RestFrames/RestFrames.hh"

using namespace std;

vector<string> g_File;
vector<string> g_Tree;
vector<string> g_Title;
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

void Plot_2D_sample(){
  HistPlot::SetStyle();
  SetLogPrint(LogVerbose,true);

  int SKIP = 1;

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=600,m_{#tilde{#chi}}=575}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51/SS_direct.root");
  // g_Tree.push_back("SS_direct_600_575_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=600,m_{#tilde{#chi}}=550}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51/SS_direct.root");
  // g_Tree.push_back("SS_direct_600_550_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=600,m_{#tilde{#chi}}=500}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51/SS_direct.root");
  // g_Tree.push_back("SS_direct_600_500_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=1000,m_{#tilde{#chi}}=0}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51/SS_direct.root");
  // g_Tree.push_back("SS_direct_1000_0_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=612,m_{#tilde{#chi}}=587}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51/GG_direct.root");
  // g_Tree.push_back("GG_direct_612_587_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=625,m_{#tilde{#chi}}=575}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51/GG_direct.root");
  // g_Tree.push_back("GG_direct_625_575_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=650,m_{#tilde{#chi}}=550}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51/GG_direct.root");
  // g_Tree.push_back("GG_direct_650_550_SRAll");

  //  g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=700,m_{#tilde{#chi}}=500}";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51/GG_direct.root");
  // g_Tree.push_back("GG_direct_700_500_SRAll");

  //  g_PlotTitle = "#scale[0.7]{#tilde{g} #tilde{g} #rightarrow 2 (qq #tilde{#chi}^{#pm}(W #tilde{#chi}))} #scale[0.6]{m_{#tilde{g}}=1385,m_{#tilde{#chi}^{#pm}}=705,m_{#tilde{#chi}}=25}";
  // g_File.push_back("../../samples/v44/GG_onestepCC.root");
  // g_Tree.push_back("GG_onestepCC_1385_705_25_SRAll");

  // g_PlotTitle = "top (t#bar{t}, single top)";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Oct17/Top.root");
  // g_Tree.push_back("Top_SRAll");

  // g_PlotTitle = "W+jets";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Oct17/WMassiveCB.root");
  // g_Tree.push_back("W_SRAll");
  // SKIP = 1;

  // g_PlotTitle = "Z+jets";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Nov7nosys/ZMassiveCB.root");
  // g_Tree.push_back("Z_SRAll");
  // SKIP = 10;

  g_PlotTitle = "DiBoson";
  g_File.push_back("/Users/crogan/Dropbox/SAMPLES/ZeroLeptonRun2/v51_Nov7nosys/DibosonMassiveCB.root");
  g_Tree.push_back("Diboson_SRAll");


  int Nsample = g_File.size();

  //string g_Label = "#splitline{H_{2,1}^{ Pi} > 400 GeV H_{1,1}^{ PP} > 500 GeV}{H_{T 4,2}^{ PP} > 1000 GeV}";
  string g_Label = "Baseline+p_{T S}^{ CM} > 600";

  g_Xname = "PI / PS";
  g_Xmin = 0.;
  g_Xmax = 1.; 
  g_NX = 30;
  g_Yname = "M_{S}";
  g_Ymin = 0.;
  g_Ymax = 1000.;
  g_NY = 30;

  TH2D* hist = new TH2D("hist","hist",
			g_NX,g_Xmin,g_Xmax,
			g_NY,g_Ymin,g_Ymax);

  /////////////////////////////////////////////////

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

  const HistPlotVar& PTS = hist_plot->GetNewVar("PTS","p_{T S}^{ CM}",0.,1500.,"[GeV]");
  const HistPlotVar& RI = hist_plot->GetNewVar("RI","#vec{p}_{I}^{ CM}. #hat{p}_{S}^{ CM} / p_{S}^{ CM}",0.0,1.);
  const HistPlotVar& RTI = hist_plot->GetNewVar("RTI","p_{T I}^{ CM} / p_{T S}^{ CM}",0.,1.);
  const HistPlotVar& RMET = hist_plot->GetNewVar("RMET","E_{T}^{miss} / p_{T j1}",0.,1.4);
  const HistPlotVar& cosS = hist_plot->GetNewVar("cosS","cos #theta_{S}",-1.,1.);
  const HistPlotVar& dphiS = hist_plot->GetNewVar("dphiS","#Delta #phi_{S}",0.,acos(-1.));
  const HistPlotVar& NISR = hist_plot->GetNewVar("NISR","N_{ISR}",0.5,4.5);
  const HistPlotVar& NVS = hist_plot->GetNewVar("NVS","N_{V}",-0.5,4.5);
  const HistPlotVar& PTJ1 = hist_plot->GetNewVar("PTj1","p_{T j1}",0.,1500., "[GeV/c]");
  const HistPlotVar& RPT = hist_plot->GetNewVar("RPT","p_{T CM}^{ lab} / p_{T S}^{ CM}",0.,1.);
  const HistPlotVar& deltaQCD = hist_plot->GetNewVar("deltaQCD","#Delta_{QCD}",-1.,1.);
  const HistPlotVar& Rsib = hist_plot->GetNewVar("Rsib","Rsib",0.,1.);
  const HistPlotVar& MS = hist_plot->GetNewVar("MS","M_{S}",0.,1000.,"[GeV]");
  const HistPlotVar& MVS = hist_plot->GetNewVar("MVS","M_{VS}",0.,800.,"[GeV]");
  const HistPlotVar& MISR = hist_plot->GetNewVar("MISR","M_{ISR}",0.,800.,"[GeV]");
  const HistPlotVar& MVSoMS = hist_plot->GetNewVar("MVSoMS","M_{VS} / M_{S}",0.,1.1);

  // hist_plot->AddHist(PTS);
  // hist_plot->AddHist(RI);
  // hist_plot->AddHist(RTI);
  // hist_plot->AddHist(RPT);
  // hist_plot->AddHist(PTS,RPT);
  // hist_plot->AddHist(cosS);
  // hist_plot->AddHist(dphiS);
  // hist_plot->AddHist(PTS,cosS);
  // hist_plot->AddHist(PTS,dphiS);
  // hist_plot->AddHist(PTS,RI);
  // hist_plot->AddHist(PTS,RTI);
  hist_plot->AddHist(RI, cosS);
  hist_plot->AddHist(RI, MS);
  hist_plot->AddHist(RI, MVS);
  hist_plot->AddHist(RI, MISR);
  hist_plot->AddHist(MS, cosS);
  hist_plot->AddHist(MVS, cosS);
  hist_plot->AddHist(MISR, cosS);
  hist_plot->AddHist(MS, MVS);
  hist_plot->AddHist(MS, MISR);
  hist_plot->AddHist(MVS, MISR);
  hist_plot->AddHist(MS, MVSoMS);
  hist_plot->AddHist(RI, MVSoMS);
  hist_plot->AddHist(NVS, MVSoMS);
  
  // hist_plot->AddHist(RI, dphiS);
  // hist_plot->AddHist(RTI, cosS);
  // hist_plot->AddHist(RTI, dphiS);
  // hist_plot->AddHist(cosS, dphiS);
  // hist_plot->AddHist(RMET);
  // hist_plot->AddHist(RMET,RI);
  // hist_plot->AddHist(RMET,RTI);
  // hist_plot->AddHist(PTS,PTJ1);
  // hist_plot->AddHist(PTS,deltaQCD);
  // hist_plot->AddHist(PTS,Rsib);
  // hist_plot->AddHist(dphiS,deltaQCD);
  // hist_plot->AddHist(dphiS,Rsib);
  // hist_plot->AddHist(RI,deltaQCD);
  // hist_plot->AddHist(RI,Rsib);


  TreePlot* tree_plot = new TreePlot("TreePlot","TreePlot");

  //////////////////////////////////////////////////////////////////


  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain(g_Tree[s].c_str());
    chain->Add(g_File[s].c_str());

    ZeroLeptonBase* base = new ZeroLeptonBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      if(e%SKIP != 0) continue;
      if(e%(max(1,Nentry/10)) == 0)
	cout << "Event " << e << " | " << Nentry << endl;
      base->GetEntry(e);

      vector<TLorentzVector> JETs;

      int Njet = base->jetPt->size();
      if(Njet < 2) continue;

      for(int i = 0; i < Njet; i++){
	if((base->jetPt->at(i) >= 50.) && (fabs(base->jetEta->at(i)) < 2.8)){
	  TLorentzVector JET;
	  JET.SetPtEtaPhiM(base->jetPt->at(i),base->jetEta->at(i),base->jetPhi->at(i),base->jetM->at(i));
	  JETs.push_back(JET);
	}
      }

      if(JETs.size() < 2) continue;

      TVector3 MET;
      MET.SetPtEtaPhi(base->NTVars_met,0.0,base->NTVars_metPhi);

      LAB_bkg.ClearEvent();
      double HT = 0.;
      vector<RFKey> jetID_bkg; 
      for(int i = 0; i < int(JETs.size()); i++){
	JETs[i].SetPtEtaPhiM(JETs[i].Pt(),0.0,JETs[i].Phi(),JETs[i].M());
	jetID_bkg.push_back(VIS_bkg.AddLabFrameFourVector(JETs[i]));
	HT += JETs[i].Pt();
      }
      INV_bkg.SetLabFrameThreeVector(MET);
      if(!LAB_bkg.AnalyzeEvent()) cout << "Something went wrong..." << endl;



      // QCD clean-up
      TLorentzVector Psib = I_bkg.GetSiblingFrame().GetFourVector(LAB_bkg);
      TLorentzVector Pmet = I_bkg.GetFourVector(LAB_bkg);
      
      Rsib = max(0.,Psib.Vect().Dot(Pmet.Vect().Unit()));
      Rsib = Rsib / (Pmet.Pt() + Rsib);
      
      TVector3 boostQCD = (Pmet+Psib).BoostVector();
      Psib.Boost(-boostQCD);
      double cosQCD = -1.*Psib.Vect().Unit().Dot(boostQCD.Unit());
      cosQCD = (1.-cosQCD)/2.;
      deltaQCD = (cosQCD-Rsib)/(cosQCD+Rsib);    

      if(S_bkg.GetFrameDepth(I_bkg) < 2)
	continue;
      
      const RestFrame& fS = S_bkg.GetFrameAtDepth(1, I_bkg);
      const RestFrame& fISR = fS.GetSiblingFrame();

      TLorentzVector vPV = fS.GetFourVector(S_bkg) - I_bkg.GetFourVector(S_bkg);
      TLorentzVector vPI = I_bkg.GetFourVector(S_bkg);
      PTS = fS.GetTransverseMomentum(S_bkg);
      double PTV = vPV.P();
      double PTI = I_bkg.GetTransverseMomentum(S_bkg);

      double PS = (vPV+vPI).P(); 
      if(PS < 600)
	continue;

      double PIdot = max(0.,vPI.Vect().Dot((vPV+vPI).Vect().Unit()));
      RI = PIdot / PS;
      RTI = PTI / PTS;				
      RMET = MET.Mag() / JETs[0].Pt();
      double HT3 = PTS+PTV+PTI;
      TLorentzVector PCM = S_bkg.GetFourVector();
      // RPZ = fabs(PCM.Pz()) / ( fabs(PCM.Pz()) + HT3 );
      // RPT = fabs(PCM.Pt()) / ( fabs(PCM.Pt()) + HT3 );
    
      if(RI < 0.6)
	continue;

      cosS = -1.*fS.GetCosDecayAngle(I_bkg);
      dphiS = fS.GetDeltaPhiDecayAngle();

      // if(fabs(cosS+fS.GetCosDecayAngle(I_bkg)) > 0.0001)
      // 	cout << cosS << " " << fS.GetCosDecayAngle(I_bkg) << endl;

      PTJ1 = JETs[0].Pt();
      RPT = PCM.Pt() / PTS;
      MS = fS.GetMass();
      MVS = vPV.M();
      MISR = fISR.GetMass();
      MVSoMS = MVS / MS;

      NVS = fS.GetListVisibleFrames().GetN();
      

      double weight = 1000.*base->NTVars_eventWeight*base->NTVars_normWeight;
      //hist->Fill(MET.Mag(), JETs[0].Pt(), weight);
      hist_plot->Fill(weight);
    }

    delete base;
    delete chain;
  }

  hist_plot->Draw();
  hist_plot->WriteOutput((g_Tree[0]+".root").c_str());

  // gStyle->SetOptTitle(0);
  // gStyle->SetOptStat(0);
  // gStyle->SetOptFit(11111111);
  //   TCanvas* can = (TCanvas*) new TCanvas("can","can",700.,600);

  //   can->SetLeftMargin(0.15);
  //   can->SetRightMargin(0.22);
  //   can->SetBottomMargin(0.15);
  //   can->SetGridx();
  //   can->SetGridy();
  //   can->SetLogz();
  //   can->Draw();
  //   can->cd();
  //   hist->Draw("COLZ");
  //   hist->GetXaxis()->CenterTitle();
  //   hist->GetXaxis()->SetTitleFont(132);
  //   hist->GetXaxis()->SetTitleSize(0.06);
  //   hist->GetXaxis()->SetTitleOffset(1.06);
  //   hist->GetXaxis()->SetLabelFont(132);
  //   hist->GetXaxis()->SetLabelSize(0.05);
  //   hist->GetXaxis()->SetTitle(g_Xname.c_str());
  //   hist->GetYaxis()->CenterTitle();
  //   hist->GetYaxis()->SetTitleFont(132);
  //   hist->GetYaxis()->SetTitleSize(0.06);
  //   hist->GetYaxis()->SetTitleOffset(1.12);
  //   hist->GetYaxis()->SetLabelFont(132);
  //   hist->GetYaxis()->SetLabelSize(0.05);
  //   hist->GetYaxis()->SetTitle(g_Yname.c_str());
  //   hist->GetZaxis()->CenterTitle();
  //   hist->GetZaxis()->SetTitleFont(132);
  //   hist->GetZaxis()->SetTitleSize(0.06);
  //   hist->GetZaxis()->SetTitleOffset(1.3);
  //   hist->GetZaxis()->SetLabelFont(132);
  //   hist->GetZaxis()->SetLabelSize(0.05);
  //   hist->GetZaxis()->SetTitle("N_{evt} / bin / fb^{-1}");
  //   hist->GetZaxis()->SetRangeUser(0.9*hist->GetMinimum(0.0),1.1*hist->GetMaximum());

  //   TLatex l;
  //   l.SetTextFont(132);
  //   l.SetNDC();
  //   l.SetTextSize(0.05);
  //   l.SetTextFont(132);
  //   // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
  //   l.DrawLatex(0.5,0.943,g_PlotTitle.c_str());
  //   l.SetTextSize(0.04);
  //   l.SetTextFont(42);
  //   l.DrawLatex(0.01,0.943,"#bf{#it{ATLAS}} Internal 13 TeV Simulation");

  //   l.SetTextSize(0.035);
  //   l.SetTextFont(132);
  //   l.DrawLatex(0.64,0.04,g_Label.c_str());


}
