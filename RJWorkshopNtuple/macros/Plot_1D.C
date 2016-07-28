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
#include <TH1D.h>
#include <TStyle.h>

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

void Plot_1D(){
   g_PlotTitle = "compressed SR4A - 1";

  // g_File.push_back("../../samples/v44_pT50/BKG/Diboson.root");
  // g_Tree.push_back("Diboson_SRAll");
  // g_Title.push_back("Dibons v44 no PU");

  // g_File.push_back("../../samples/v44_pT50_noPUw/BKG/Diboson.root");
  // g_Tree.push_back("Diboson_SRAll");
  // g_Title.push_back("Diboson v44 PU");

  // g_File.push_back("../../../../v47_pT50/BKG/Diboson.root");
  // g_Tree.push_back("Diboson_SRAll");
  // g_Title.push_back("Diboson v47");
   
   //  g_File.push_back("/Users/crogan/v51_Nov07_nosys_pT50/BKG/Zjets.root");
  // g_Tree.push_back("Z_SRAll");
  // g_Title.push_back("Z+jets");

  // g_File.push_back("/Users/crogan/v51_Nov07_nosys_pT50/BKG/Wjets.root");
  // g_Tree.push_back("W_SRAll");
  // g_Title.push_back("W+jets");

  //  g_File.push_back("/Users/crogan/v51_Nov07_nosys_pT50/BKG/Top.root");
  // g_Tree.push_back("Top_SRAll");
  // g_Title.push_back("top (t#bar{t} + single top)");
   
  // g_File.push_back("../../samples/v44/GG_direct.root");
  // g_Tree.push_back("GG_direct_1400_0_SRAll");
  // g_Title.push_back("m_{#tilde{g}} = 1400, m_{#tilde{#chi}} = 0");

  // g_File.push_back("../../samples/v44_pT50/GG_direct.root");
  // g_Tree.push_back("GG_direct_1100_500_SRAll");
  // g_Title.push_back("m_{#tilde{g}} = 1100, m_{#tilde{#chi}} = 500");

  //  g_File.push_back("../../samples/v44_pT50/GG_direct.root");
  // g_Tree.push_back("GG_direct_1100_700_SRAll");
  // g_Title.push_back("m_{#tilde{g}} = 1100, m_{#tilde{#chi}} = 700");

  // g_File.push_back("SIG_v44/GG_onestepCC.root");
  // g_Tree.push_back("GG_onestepCC_1385_705_25_SRAll_opt_tree");
  // g_Title.push_back("m_{#tilde{g}} = 1385, m_{#tilde{#chi}^{#pm}}= 705, m_{#tilde{#chi}} = 25");

   // g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/GG_direct.root");
   // g_Tree.push_back("GG_direct_612_587_SRAll");
   // g_Title.push_back("m_{#tilde{g}} = 712, m_{#tilde{#chi}} = 687");

   //  g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50//GG_direct.root");
   // g_Tree.push_back("GG_direct_750_650_SRAll");
   // g_Title.push_back("m_{#tilde{g}} = 750, m_{#tilde{#chi}} = 650");

   //  g_File.push_back("/Users/crogan/v51_SIG_nosys_pT50/GG_direct.root");
   // g_Tree.push_back("GG_direct_700_500_SRAll");
   // g_Title.push_back("m_{#tilde{g}} = 700, m_{#tilde{#chi}} = 500");

   //  g_File.push_back("/Users/crogan/v51_SIG_pT50/GG_direct.root");
   // g_Tree.push_back("GG_direct_725_675_SRAll");
   // g_Title.push_back("m_{#tilde{g}} = 650, m_{#tilde{#chi}} = 550");

   //  g_File.push_back("/Users/crogan/v51_SIG_pT50/GG_direct.root");
   // g_Tree.push_back("GG_direct_812_787_SRAll");
   // g_Title.push_back("m_{#tilde{g}} = 812, m_{#tilde{#chi}} = 787");

   g_File.push_back("/Users/crogan/STOP/BKG/ttbar_lep.root");
   g_Tree.push_back("Analysis");
   g_Title.push_back("leptonic t#bar{t}");

   g_File.push_back("/Users/crogan/STOP/BKG/Wjets.root");
   g_Tree.push_back("Analysis");
   g_Title.push_back("W(#it{l}#nu)+jets");

   g_File.push_back("/Users/crogan/STOP/BKG/Zjets.root");
   g_Tree.push_back("Analysis");
   g_Title.push_back("Z(#nu#nu)+jets");

   g_File.push_back("/Users/crogan/STOP/BKG/QCD.root");
   g_Tree.push_back("Analysis");
   g_Title.push_back("QCD multijets");

   g_File.push_back("/Users/crogan/STOP/SIG/TT_400_228.root");
   g_Tree.push_back("Analysis");
   g_Title.push_back("m_{#tilde{t}} = 400, m_{#tilde{#chi}} = 228");

   g_File.push_back("/Users/crogan/STOP/SIG/TT_450_278.root");
   g_Tree.push_back("Analysis");
   g_Title.push_back("m_{#tilde{t}} = 450, m_{#tilde{#chi}} = 278");


  int Nsample = g_File.size();

  g_Xname = "M_{S} [GeV]";
  //g_Xname = "#vec{p}_{I}^{ CM}. #hat{p}_{T S}^{ CM} / p_{T S}^{ CM}";
  g_Xmin = 0.;
  g_Xmax = 800.;
  g_NX = 16;


  TH1D* hist[Nsample];
  for(int i = 0; i < Nsample; i++)
    hist[i] = new TH1D(("h"+to_string(i)).c_str(),
		       ("h"+to_string(i)).c_str(),
		       g_NX,g_Xmin,g_Xmax);

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

      // trigger
      // if(base->MDR < 300.)
      // 	continue;

      // QCD
      // if(base->deltaQCD < 0.05*(base->Rsib-1.))
      //   continue;
      // if(base->RPT > 0.3)
      // 	continue;
      // if(((base->dphiPPV < 0.5)||(acos(-1)-base->dphiPPV < 0.2)) && base->RPT > 0.2)
      // 	continue;

      // gluino-gluino
      // if(base->NJa < 2. || base->NJb < 2.)
      // 	continue;

     //  double dphiA = base->dphiPCa;
     //  double dphiB = base->dphiPCb;
     //  if(dphiA > acos(-1.))
     // 	dphiA = 2.*acos(-1.) - dphiA;
     //  if(dphiB > acos(-1.))
     // 	dphiB = 2.*acos(-1.) - dphiB;
     // double dphiVP = (base->dphiVP-acos(-1.)/2.)/(acos(-1.)/2.);

     // double HT6PP = base->pTPP_V1a+base->pTPP_V2a+base->pTPP_V1b+
     //   base->pTPP_V2b+base->pTPP_Ia+base->pTPP_Ib;
     
     // double minPT2o1PP = min(base->pTPP_jet2a/base->pTPP_jet1a,base->pTPP_jet2b/base->pTPP_jet1b);
     // double minPToP1PP = min(base->pTPP_jet1a/base->pPP_jet1a,base->pTPP_jet1b/base->pPP_jet1b);

     // double minPT2 = min(base->pTPP_jet2a,base->pTPP_jet2b);

     //    double  H2P = (base->H2Pa+base->H2Pb)/2.;
     //  double  H2Pnew = sqrt(base->H2Pa*base->H2Pb);
     //  double minH2P = min(base->H2Pa,base->H2Pb);
     //  double dH2P = base->H2Pa-base->H2Pb;
     //  double  H3P = (base->H3Pa+base->H3Pb)/2.;
     //  double dH3P = base->H3Pa-base->H3Pb;
     //  double minH3P = min(base->H3Pa,base->H3Pb);
     //  double H2o3Pa = base->H2Pa/base->H3Pa;
     //  double H2o3Pb = base->H2Pb/base->H3Pb;
     //  double H2o3P = (H2o3Pa+H2o3Pb)/2.;
     //  double dH2o3P = (H2o3Pa-H2o3Pb);

     //   double sangle = fabs(base->cosP+dphiVP)/2.;
     //  double dangle = (base->cosP-dphiVP)/2.;

      // if(base->H2PP/HT6PP < 0.4)
      // 	continue;

      // if(HT6PP/base->H6PP < 0.6)
      // 	continue;
      
      // if(minPToP1PP < 0.6)
      // 	continue;

      // if(minPT2 < 80.)
      // 	continue;

      // if(minPT2o1PP < 0.3)
      // 	continue;

      // if(minH3P < 500.)
      // 	continue;

      // if(base->H2PP < 1000.)
      // 	continue;

      // if(base->RPT_HT1CM > 0.15)
      // 	continue;

       if(base->HT1CM < 700.)
       	continue;

       if(base->PIoHT1CM < 0.6)
	 continue;

       if(base->dphiCMV < 0.3)
	 continue;

        if(base->NbV < 1)
	 continue;

       hist[s]->Fill(base->MS,base->weight);

    }

    delete base;
    delete chain;
  }

  int imax = -1;
  double hmax = -1.;
  for(int i = 0; i < Nsample; i++){
    hist[i]->SetFillColor(kWhite);
    hist[i]->SetLineWidth(3);
    hist[i]->SetMarkerSize(0);

    if(i == 0)
      hist[i]->SetLineColor(kBlue+1);
    if(i == 1)
      hist[i]->SetLineColor(kGreen+2);
    if(i == 2)
      hist[i]->SetLineColor(kRed+1);
    if(i == 3)
      hist[i]->SetLineColor(kCyan+2);
    if(i == 4)
      hist[i]->SetLineColor(kOrange+2);
    if(i == 5)
      hist[i]->SetLineColor(kMagenta+3);


    // if(hist[i]->Integral() > 0.)
    //   hist[i]->Scale(1./hist[i]->Integral());
    if(hist[i]->GetMaximum() > hmax){
      hmax = hist[i]->GetMaximum();
      imax = i;
    }
  }
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
    TCanvas* can = (TCanvas*) new TCanvas("can","can",600.,500);

    can->SetLeftMargin(0.15);
    can->SetRightMargin(0.04);
    can->SetBottomMargin(0.15);
    can->SetGridx();
    can->SetGridy();
    can->Draw();
    can->cd();
    hist[imax]->Draw();
    hist[imax]->GetXaxis()->CenterTitle();
    hist[imax]->GetXaxis()->SetTitleFont(132);
    hist[imax]->GetXaxis()->SetTitleSize(0.06);
    hist[imax]->GetXaxis()->SetTitleOffset(1.13);
    hist[imax]->GetXaxis()->SetLabelFont(132);
    hist[imax]->GetXaxis()->SetLabelSize(0.05);
    hist[imax]->GetXaxis()->SetTitle(g_Xname.c_str());
    hist[imax]->GetYaxis()->CenterTitle();
    hist[imax]->GetYaxis()->SetTitleFont(132);
    hist[imax]->GetYaxis()->SetTitleSize(0.06);
    hist[imax]->GetYaxis()->SetTitleOffset(1.2);
    hist[imax]->GetYaxis()->SetLabelFont(132);
    hist[imax]->GetYaxis()->SetLabelSize(0.05);
    hist[imax]->GetYaxis()->SetTitle("a. u.");
    hist[imax]->GetYaxis()->SetTitle("N_{evt} / fb^{-1}");

    for(int i = 0; i < Nsample; i++)
      hist[i]->Draw("SAME");

    TLegend* leg = new TLegend(0.688,0.22,0.93,0.42);
    leg->SetTextFont(132);
    leg->SetTextSize(0.045);
    leg->SetFillColor(kWhite);
    leg->SetLineColor(kWhite);
    leg->SetShadowColor(kWhite);
    for(int i = 0; i < Nsample; i++)
      leg->AddEntry(hist[i],g_Title[i].c_str());
    leg->Draw("SAME");

    TLatex l;
    l.SetTextFont(132);
    l.SetNDC();
    l.SetTextSize(0.05);
    l.SetTextFont(132);
    // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
    l.DrawLatex(0.65,0.943,g_PlotTitle.c_str());
    l.SetTextSize(0.04);
    l.SetTextFont(42);
    l.DrawLatex(0.15,0.943,"#bf{#it{ATLAS}} Internal 13 TeV Simulation");
    // l.SetTextSize(0.045);
    // l.SetTextFont(132);
    // string bla = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(g_lumi))+" fb^{-1},  #Delta_{N#scale[0.8]{bkg}} = ";
    // bla += to_string(int(g_deltaNbkg))+" %";
    // l.DrawLatex(0.61,0.943,bla.c_str());


}
