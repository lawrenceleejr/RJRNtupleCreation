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

#include "RestFrames/RestFrames.hh"

#include "include/RJWorkshopBase.hh"

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

void Plot_2D(){
  HistPlot::SetStyle();

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=500,m_{#tilde{#chi}}=475}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/SS_direct.root");
  // g_Tree.push_back("SS_direct_500_475_SRAll");

  //  g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=500,m_{#tilde{#chi}}=450}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/SS_direct.root");
  // g_Tree.push_back("SS_direct_500_450_SRAll");

  //  g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=500,m_{#tilde{#chi}}=400}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/SS_direct.root");
  // g_Tree.push_back("SS_direct_500_400_SRAll");

  //  g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=600,m_{#tilde{#chi}}=400}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/SS_direct.root");
  // g_Tree.push_back("SS_direct_600_400_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=712,m_{#tilde{#chi}}=687}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/GG_direct.root");
  // g_Tree.push_back("GG_direct_712_687_SRAll");

  //  g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=725,m_{#tilde{#chi}}=675}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/GG_direct.root");
  // g_Tree.push_back("GG_direct_725_675_SRAll");

  //  g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=750,m_{#tilde{#chi}}=650}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/GG_direct.root");
  // g_Tree.push_back("GG_direct_750_650_SRAll");

  //  g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=700,m_{#tilde{#chi}}=500}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/GG_direct.root");
  // g_Tree.push_back("GG_direct_700_500_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=1000,m_{#tilde{#chi}}=300}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/SS_direct.root");
  // g_Tree.push_back("SS_direct_1000_300_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=1000,m_{#tilde{#chi}}=0}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/SS_direct.root");
  // g_Tree.push_back("SS_direct_1000_0_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{q}}=1200,m_{#tilde{#chi}}=0}";
  // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/SS_direct.root");
  // g_Tree.push_back("SS_direct_1200_0_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=1400,m_{#tilde{#chi}}=0}";
  // g_File.push_back("../../samples/v51_SIG_nosys_pT50/GG_direct.root");
  // g_Tree.push_back("GG_direct_1400_0_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.65]{m_{#tilde{g}}=1100,m_{#tilde{#chi}}=500}";
  // g_File.push_back("../../samples/v51_SIG_nosys_pT50/GG_direct.root");
  // g_Tree.push_back("GG_direct_1100_500_SRAll");

   // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.65]{m_{#tilde{g}}=1100,m_{#tilde{#chi}}=700}";
   // g_File.push_back("../../samples/v51_SIG_pT50/GG_direct.root");
   // g_Tree.push_back("GG_direct_1100_700_SRAll");

  //  g_PlotTitle = "#scale[0.7]{#tilde{g} #tilde{g} #rightarrow 2 (qq #tilde{#chi}^{#pm}(W #tilde{#chi}))} #scale[0.6]{m_{#tilde{g}}=1385,m_{#tilde{#chi}^{#pm}}=705,m_{#tilde{#chi}}=25}";
  // g_File.push_back("../../samples/v44/GG_onestepCC.root");
  // g_Tree.push_back("GG_onestepCC_1385_705_25_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=812,m_{#tilde{#chi}}=787}";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/GG_direct_comb.root");
  // g_Tree.push_back("GG_direct_812_787_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=825,m_{#tilde{#chi}}=775}";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/GG_direct_comb.root");
  // g_Tree.push_back("GG_direct_825_775_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=850,m_{#tilde{#chi}}=750}";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/GG_direct_comb.root");
  // g_Tree.push_back("GG_direct_850_750_SRAll");

  // g_PlotTitle = "#tilde{g} #tilde{g} #rightarrow (qq #tilde{#chi})(qq #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=900,m_{#tilde{#chi}}=700}";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/GG_direct_comb.root");
  // g_Tree.push_back("GG_direct_900_700_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=600,m_{#tilde{#chi}}=575}";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/SS_direct_comb.root");
  // g_Tree.push_back("SS_direct_600_575_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=600,m_{#tilde{#chi}}=550}";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/SS_direct_comb.root");
  // g_Tree.push_back("SS_direct_600_550_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=600,m_{#tilde{#chi}}=500}";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/SS_direct_comb.root");
  // g_Tree.push_back("SS_direct_600_500_SRAll");

  // g_PlotTitle = "#tilde{q} #tilde{q} #rightarrow (q #tilde{#chi})(q #tilde{#chi}) #scale[0.75]{m_{#tilde{g}}=600,m_{#tilde{#chi}}=400}";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/SS_direct_comb.root");
  // g_Tree.push_back("SS_direct_600_400_SRAll");
  
  // g_PlotTitle = "top (t#bar{t}, single top)";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/BKG/Top.root");
  // g_Tree.push_back("Top_SRAll");

  // g_PlotTitle = "W+jets";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/BKG/Wjets.root");
  // g_Tree.push_back("W_SRAll");

  // g_PlotTitle = "Z+jets";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/BKG/Zjets.root");
  // g_Tree.push_back("Z_SRAll");

  // g_PlotTitle = "Di-boson";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/BKG/Diboson.root");
  // g_Tree.push_back("Diboson_SRAll");

  // g_PlotTitle = "QCD mulit-jets";
  // g_File.push_back("/Users/crogan/ALL_v57_pT50/QCD.root");
  // g_Tree.push_back("QCD_SRAll");

  // g_PlotTitle = "top (t#bar{t}, single top)";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Dec15/BKG/ttbar_lep.root");
  // g_Tree.push_back("Analysis");
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/ttbar_had.root");
  // g_Tree.push_back("Analysis");
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/SingleTop.root");
  // g_Tree.push_back("Analysis");

  // g_PlotTitle = "QCD mulit-jets";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/QCD.root");
  // g_Tree.push_back("Analysis");

  // g_PlotTitle = "V+jets";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/Wjets.root");
  // g_Tree.push_back("Analysis");
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/Zjets.root");
  // g_Tree.push_back("Analysis");

  // g_PlotTitle = "m_{#tilde{t}} = 300, m_{#tilde{#chi}} = 127";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/SIG/TT_300_127.root");
  // g_Tree.push_back("Analysis");
  
  // g_PlotTitle = "m_{#tilde{t}} = 350, m_{#tilde{#chi}} = 177";
  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/SIG/TT_350_177.root");
  // g_Tree.push_back("Analysis");

  g_PlotTitle = "m_{#tilde{t}} = 500, m_{#tilde{#chi}} = 327";
  g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/SIG/TT_500_327.root");
  g_Tree.push_back("Analysis");

  int Nsample = g_File.size();

  //string g_Label = "#splitline{H_{2,1}^{ Pi} > 400 GeV H_{1,1}^{ PP} > 500 GeV}{H_{T 4,2}^{ PP} > 1000 GeV}";
  string g_Label = "Baseline+p_{T}^{ ISR} > 600 GeV";
  //string g_Label = "Baseline Selection";

  g_Xname = "N_{jet}^{ V}";
  g_Xmin = 0.5;
  g_Xmax = 7.5; 
  g_NX = 7;
  g_Yname = "#vec{p}_{I}^{ CM}. #hat{p}_{T S}^{ CM} / p_{T S}^{ CM}";
  g_Ymin = 0.;
  g_Ymax = 1.;
  g_NY = 32;

  TH2D* hist = new TH2D("hist","hist",
			g_NX,g_Xmin,g_Xmax,
			g_NY,g_Ymin,g_Ymax);

  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain(g_Tree[s].c_str());
    chain->Add(g_File[s].c_str());

     RJWorkshopBase* base = new RJWorkshopBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);

      /* BASELINE SELECTION */

      // if(base->Idepth < 2)
      // 	continue;

      // // trigger
      // if(base->MDR < 300.)
      // 	continue;

      // QCD
      // if(base->deltaQCD < 0.05*(base->Rsib-1.))
      //   continue;
      // if(base->RPT > 0.4)
      // 	continue;
      // if(((base->dphiPPV < 0.5)||(acos(-1)-base->dphiPPV < 0.2)) && base->RPT > 0.2)
      // 	continue;

      // // gluino-gluino
      // if(base->NJa < 2. || base->NJb < 2.)
      // 	continue;

      // double dphiA = base->dphiPCa;
      // double dphiB = base->dphiPCb;
      // if(dphiA > acos(-1.))
      // 	dphiA = 2.*acos(-1.) - dphiA;
      // if(dphiB > acos(-1.))
      // 	dphiB = 2.*acos(-1.) - dphiB;

      // double ddphiPC = (dphiA-dphiB)/acos(-1.);
      // double sdphiPC = fabs(dphiA+dphiB)/2./acos(-1.);


      // double MeffN = base->MET+
      // 	base->pT_jet1+
      // 	base->pT_jet2+
      // 	base->pT_jet3+
      // 	base->pT_jet4;

      // if(base->H2PP < 800.)
      // 	continue;
      // if(base->H4PP < 800.*1.35)
      // 	continue;
      // if(base->H2PP/base->H4PP < 0.4)
      // 	continue;
      // if(dphiVP > 0.7)
      // 	continue;
      // if(base->cosP > 0.9)
      // 	continue;
      // if(base->RPZ > 0.8)
      // 	continue;
      // if(base->PP_VisShape < 0.2)
      // 	continue;
      //cout << base->weight << endl;

      // if(minH3P < 500.)
      // 	continue;

      // if(base->H2PP < 700.)
      // 	continue;

      // if(base->MET < 200.)
      // 	continue;

      // if(base->minH3P < 400.)
      // 	continue;
      
      // if(base->H2PP < 500.)
      // 	continue;
      
      // if(base->HT6PP < 1000.)
      // 	continue;

      // double RH4Pa = base->H4Pa / (base->H4Pa+base->MET);
      // double RH2Ca = base->H2Ca / (base->H2Ca+base->MET);

      // double R1 = (atan2(base->pTPP_jet1a,base->pTPP_jet1b) - acos(-1.)/4.)*4./acos(-1.);
      // double R2 = (atan2(base->pTPP_jet2a,base->pTPP_jet2b) - acos(-1.)/4.)*4./acos(-1.);

      // double pT_V1a = max(base->pTPP_V1a,base->pTPP_V2a);
      // double pT_V1b = max(base->pTPP_V1b,base->pTPP_V2b); 
      // double pT_V2a = min(base->pTPP_V1a,base->pTPP_V2a);
      // double pT_V2b = min(base->pTPP_V1b,base->pTPP_V2b);

      // double bla1a = acos(base->pTPP_jet1a/base->pPP_jet1a)*2./acos(-1.);
      // double bla1b = acos(base->pTPP_jet1b/base->pPP_jet1b)*2./acos(-1.);
      // double bla2a = acos(base->pTPP_jet2a/base->pPP_jet2a)*2./acos(-1.);
      // double bla2b = acos(base->pTPP_jet2b/base->pPP_jet2b)*2./acos(-1.);

      // double blaIa = acos(base->pTPP_Ia/base->pPP_Ia)*2./acos(-1.);
      // double blaIb = acos(base->pTPP_Ib/base->pPP_Ib)*2./acos(-1.);


      // double HT6PP = base->pTPP_V1a+base->pTPP_V2a+base->pTPP_V1b+
      // 	base->pTPP_V2b+base->pTPP_Ia+base->pTPP_Ib;

      // double minPT2o1PP = min(base->pTPP_jet2a/base->pTPP_jet1a,base->pTPP_jet2b/base->pTPP_jet1b);
      // double minPToP1PP = min(base->pTPP_jet1a/base->pPP_jet1a,base->pTPP_jet1b/base->pPP_jet1b);

      // double newdangle = (2*base->dphiVP - base->cosP)/3.;
      // double v2 = (base->ddphiPC - base->cosP)/2.;

      // double minPT2PP =  min(base->pTPP_jet2a,base->pTPP_jet2b);
      // double minPTV2PP =  min(pT_V2a,pT_V2b);
      // double maxPTV1PP =  max(pT_V1a,pT_V1b);

      // double HT5PP = base->pTPP_V1a+base->pTPP_V2a+base->pTPP_V1b+
      // 	base->pTPP_V2b+base->H2PP/2.;

      //  double HT3PP = base->pTPP_Va+base->pTPP_Vb+base->H2PP/2.;

      // double minH2o3P = min(base->H2Pa/base->H3Pa,base->H2Pb/base->H3Pb);
      // double maxH2o3P = max(base->H2Pa/base->H3Pa,base->H2Pb/base->H3Pb);
      // double minH3o5P = min(base->H3Pa/base->H5Pa,base->H3Pb/base->H5Pb);

      // double HT20 = base->pTPP_Va+base->pTPP_Vb;
      // double HT40 = base->pTPP_V1a+base->pTPP_V2a+base->pTPP_V1b+
      // 	base->pTPP_V2b;

      // double HT3a = base->pTPP_V1a+base->pTPP_V2a+base->pTPP_Ia;
      // double HT3b = base->pTPP_V1b+base->pTPP_V2b+base->pTPP_Ib;
      // double HT2a = base->pTPP_Va+base->pTPP_Ia;
      // double HT2b = base->pTPP_Vb+base->pTPP_Ib;
      // double HT20a = base->pTPP_V1a+base->pTPP_V2a;
      // double HT20b = base->pTPP_V1b+base->pTPP_V2b;

      // double dHT3 = HT3a-HT3b;
      // double dHT2 = HT20a-HT20b;

      // double H5PP = base->pPP_V1a+base->pPP_V2a+base->pPP_V1b+
      // 	base->pPP_V2b+base->H2PP/2.;

      // double maxH1o2i = max(base->pPP_Va/(base->pPP_V1a+base->pPP_V2a), base->pPP_Vb/(base->pPP_V1b+base->pPP_V2b));

      // double RPT_HT3PP = base->pTCM / (base->pTCM + base->HT3PP);
      // double RPZ_HT3PP = base->pZCM / (base->pZCM + base->HT3PP);

      // double minpToHT3 = min(base->pTPP_jet1a,base->pTPP_jet1b)/base->HT3PP;

      if(base->HT1CM < 600.)
      	continue;

      // if(base->PIoHT1CM < 0.7)
      // 	continue;

      // if(base->RPT_HT1CM > 0.15)
      // 	continue;

     

      hist->Fill(base->NV, base->PIoHT1CM, base->weight);
     
      
    }

    delete base;
    delete chain;
  }

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

    l.SetTextSize(0.04);
    l.SetTextFont(132);
    l.DrawLatex(0.64,0.04,g_Label.c_str());


}
