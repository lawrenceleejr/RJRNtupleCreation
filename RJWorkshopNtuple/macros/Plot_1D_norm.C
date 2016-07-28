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
#include <TColor.h>
#include <TColorWheel.h>
#include <TH1D.h>
#include <TStyle.h>

#include "include/RJWorkshopBase.hh"


using namespace std;

vector<string> g_File;
vector<string> g_Tree;
vector<int> g_Hist;
vector<string> g_Title;
vector<bool> g_Bkg;
double g_Lumi;
string g_PlotTitle;
string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;

TColor *icolor[9][2];
int color_list[4][10];
int style_list[4][10];

void setstyle(int istyle);

void Plot_1D_norm(){
  setstyle(0);

  //g_PlotTitle = "Baseline Selection";
  g_PlotTitle = "p_{T}^{ ISR} > 600 GeV";

   int ihist = 0;

   // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/GG_direct_comb.root");
   // g_Tree.push_back("GG_direct_812_787_SRAll");
   // g_Hist.push_back(ihist);
   // g_Bkg.push_back(false);
   // g_Title.push_back("m_{#tilde{g}} = 812, m_{#tilde{#chi}} = 797");
   // ihist++;

   // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/GG_direct_comb.root");
   // g_Tree.push_back("GG_direct_825_775_SRAll");
   // g_Hist.push_back(ihist);
   // g_Bkg.push_back(false);
   // g_Title.push_back("m_{#tilde{g}} = 825, m_{#tilde{#chi}} = 775");
   // ihist++;

   // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/GG_direct_comb.root");
   // g_Tree.push_back("GG_direct_850_750_SRAll");
   // g_Hist.push_back(ihist);
   // g_Bkg.push_back(false);
   // g_Title.push_back("m_{#tilde{g}} = 850, m_{#tilde{#chi}} = 750");
   // ihist++;

   // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/GG_direct_comb.root");
   // g_Tree.push_back("GG_direct_900_700_SRAll");
   // g_Hist.push_back(ihist);
   // g_Bkg.push_back(false);
   // g_Title.push_back("m_{#tilde{g}} = 900, m_{#tilde{#chi}} = 700");
   // ihist++;

   // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/SS_direct_comb.root");
   // g_Tree.push_back("SS_direct_600_575_SRAll");
   // g_Hist.push_back(ihist);
   // g_Title.push_back("m_{#tilde{q}} = 600, m_{#tilde{#chi}} = 575");
   // ihist++;

   // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/SS_direct_comb.root");
   // g_Tree.push_back("SS_direct_600_550_SRAll");
   // g_Hist.push_back(ihist);
   // g_Title.push_back("m_{#tilde{q}} = 600, m_{#tilde{#chi}} = 550");
   // ihist++;

   // g_File.push_back("/Users/crogan/ALL_v57_pT50/SIG/SS_direct_comb.root");
   // g_Tree.push_back("SS_direct_600_500_SRAll");
   // g_Hist.push_back(ihist);
   // g_Title.push_back("m_{#tilde{q}} = 600, m_{#tilde{#chi}} = 500");
   // ihist++;

   // g_File.push_back("/Users/crogan/ALL_v57_pT40/SS_direct.root");
   // g_Tree.push_back("SS_direct_600_400_SRAll");
   // g_Hist.push_back(ihist);
   // g_Title.push_back("m_{#tilde{q}} = 600, m_{#tilde{#chi}} = 400");
   // ihist++;

   //  g_File.push_back("/Users/crogan/ALL_v57_pT50/BKG/GG_direct.root");
   // g_Tree.push_back("GG_direct_700_500_SRAll");
   // g_Title.push_back("m_{#tilde{g}} = 700, m_{#tilde{#chi}} = 500");

   //  g_File.push_back("/Users/crogan/ALL_v57_pT50/BKG/GG_direct.root");
   // g_Tree.push_back("GG_direct_725_675_SRAll");
   // g_Title.push_back("m_{#tilde{g}} = 650, m_{#tilde{#chi}} = 550");

   //  g_File.push_back("/Users/crogan/ALL_v57_pT50/BKG/GG_direct.root");
   // g_Tree.push_back("GG_direct_812_787_SRAll");
   // g_Title.push_back("m_{#tilde{g}} = 812, m_{#tilde{#chi}} = 787");


   /*
   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Dec15/BKG/ttbar_lep.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/ttbar_had.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/SingleTop.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("Top + X");
   g_Bkg.push_back(true);
   ihist++;

   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/QCD.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("QCD multijets");
   g_Bkg.push_back(true);
   ihist++;

   
   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/Wjets.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/Zjets.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("V + jets");
   g_Bkg.push_back(true);
   ihist++;
   

   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/DiBoson.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("Di-boson");
   g_Bkg.push_back(true);
   ihist++;
   */
   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/SIG/TT_300_127.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("m_{#tilde{t}} = 300, m_{#tilde{#chi}} = 127");
   g_Bkg.push_back(false);
   ihist++;

   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/SIG/TT_350_177.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("m_{#tilde{t}} = 350, m_{#tilde{#chi}} = 177");
   g_Bkg.push_back(false);
   ihist++;

   g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/SIG/TT_500_327.root");
   g_Tree.push_back("Analysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("m_{#tilde{t}} = 500, m_{#tilde{#chi}} = 327");
   g_Bkg.push_back(false);
   ihist++;
   
  


  int Nsample = g_File.size();
  int Nhist = ihist;

  //g_Xname = "N_{jet}^{ V_{S}}";
  g_Xname = "#vec{p}_{I}^{ CM}. #hat{p}_{T S}^{ CM} / p_{T S}^{ CM}";
  g_Xmin = 0.0;
  g_Xmax = 1.;
  g_NX = 50;


  TH1D* hist[Nhist];
  for(int i = 0; i < Nhist; i++)
    hist[i] = new TH1D(("h"+to_string(i)).c_str(),
		       ("h"+to_string(i)).c_str(),
		       g_NX,g_Xmin,g_Xmax);

  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain(g_Tree[s].c_str());
    chain->Add(g_File[s].c_str());

    RJWorkshopBase* base = new RJWorkshopBase(chain);

    int Nentry = base->fChain->GetEntries();

    cout << "Sample " << s << " | " << Nsample << endl;
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);
      if(e%(max(1,Nentry/10)) == 0)
	cout << "event " << e << " | " << Nentry << endl;

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

       // if(base->Idepth < 2)
       // 	continue;

       // if(base->Meff < 800.)
       // 	continue;

       // if(base->MET < 150.)
       // 	continue;
      
       if(base->HT1CM < 600.)
       	continue;

       // if(base->PIoHT1CM < 0.7)
       // 	 continue;

       // if(base->MS < 250)
       // 	 continue;

       // if(base->NV < 5)
       // 	 continue;

       // if(base->LepVeto)
       // 	 continue;

       // if(base->dphiCMV < 1.)
       // 	 continue;

       // if(acos(-1.)-base->dphiCMV < 0.1)
       // 	 continue;

        // if(base->NbV < 1)
       	//  continue;

      // if(base->RPT_HT1CM > 0.1)
      // 	 continue;

       hist[g_Hist[s]]->Fill(base->PIoHT1CM, base->weight);

    }

    delete base;
    delete chain;
  }
  
  double max = -1.;
  int imax = -1;
  for(int i = 0; i < Nhist; i++){
    cout << hist[i]->Integral() << " bla" << endl;
    hist[i]->Scale(1./hist[i]->Integral());
    if(hist[i]->GetMaximum() > max){
      max = hist[i]->GetMaximum();
      imax = i;
    }
  }
  
  float width = hist[0]->GetBinWidth(1);
  char *yaxis = new char[100];
  sprintf(yaxis,"Events / %f", width);

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
    TCanvas* can = (TCanvas*) new TCanvas("can","can",600.,500);

    can->SetLeftMargin(0.13);
    can->SetRightMargin(0.04);
    can->SetBottomMargin(0.15);
    can->SetTopMargin(0.085);
    can->SetGridx();
    can->SetGridy();
    can->Draw();
    can->cd();
    hist[imax]->Draw();
    hist[imax]->GetXaxis()->CenterTitle();
    hist[imax]->GetXaxis()->SetTitleFont(132);
    hist[imax]->GetXaxis()->SetTitleSize(0.06);
    hist[imax]->GetXaxis()->SetTitleOffset(1.06);
    hist[imax]->GetXaxis()->SetLabelFont(132);
    hist[imax]->GetXaxis()->SetLabelSize(0.05);
    hist[imax]->GetXaxis()->SetTitle(g_Xname.c_str());
    hist[imax]->GetYaxis()->CenterTitle();
    hist[imax]->GetYaxis()->SetTitleFont(132);
    hist[imax]->GetYaxis()->SetTitleSize(0.06);
    hist[imax]->GetYaxis()->SetTitleOffset(1.);
    hist[imax]->GetYaxis()->SetLabelFont(132);
    hist[imax]->GetYaxis()->SetLabelSize(0.05);
    hist[imax]->GetYaxis()->SetTitle("a. u.");
    //hist[imax]->GetYaxis()->SetTitle(yaxis);
    //hist[imax]->GetYaxis()->SetTitle("N_{evt} / fb^{-1}");
    int Ntype[3];

    Ntype[0] = 0;
    for(int i = 0; i < Nhist; i++){
      hist[i]->SetLineColor(1393+2*Ntype[0]);
      hist[i]->SetLineWidth(3);
      hist[i]->SetMarkerColor(1393+2*Ntype[0]);
      hist[i]->SetMarkerSize(0);
      hist[i]->SetFillColor(kWhite);
      Ntype[0]++;
      hist[i]->Draw("SAME");
    }

    TLegend* leg = new TLegend(0.688,0.22,0.93,0.42);
    leg->SetTextFont(132);
    leg->SetTextSize(0.045);
    leg->SetFillColor(kWhite);
    leg->SetLineColor(kWhite);
    leg->SetShadowColor(kWhite);
    for(int i = 0; i < Nhist; i++)
	leg->AddEntry(hist[i],g_Title[i].c_str());
    leg->SetLineColor(kWhite);
    leg->SetFillColor(kWhite);
    leg->SetShadowColor(kWhite);
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

void setstyle(int istyle) {
	
	// For the canvas:
	gStyle->SetCanvasBorderMode(0);
	gStyle->SetCanvasColor(kWhite);
	gStyle->SetCanvasDefH(300); //Height of canvas
	gStyle->SetCanvasDefW(600); //Width of canvas
	gStyle->SetCanvasDefX(0);   //POsition on screen
	gStyle->SetCanvasDefY(0);
	
	// For the Pad:
	gStyle->SetPadBorderMode(0);
	// gStyle->SetPadBorderSize(Width_t size = 1);
	gStyle->SetPadColor(kWhite);
	gStyle->SetPadGridX(false);
	gStyle->SetPadGridY(false);
	gStyle->SetGridColor(0);
	gStyle->SetGridStyle(3);
	gStyle->SetGridWidth(1);
	
	// For the frame:
	gStyle->SetFrameBorderMode(0);
	gStyle->SetFrameBorderSize(1);
	gStyle->SetFrameFillColor(0);
	gStyle->SetFrameFillStyle(0);
	gStyle->SetFrameLineColor(1);
	gStyle->SetFrameLineStyle(1);
	gStyle->SetFrameLineWidth(1);
	
	// set the paper & margin sizes
	gStyle->SetPaperSize(20,26);
	gStyle->SetPadTopMargin(0.065);
	gStyle->SetPadRightMargin(0.065);
	gStyle->SetPadBottomMargin(0.15);
	gStyle->SetPadLeftMargin(0.17);
	
	// use large Times-Roman fonts
	gStyle->SetTitleFont(132,"xyz");  // set the all 3 axes title font
	gStyle->SetTitleFont(132," ");    // set the pad title font
	gStyle->SetTitleSize(0.06,"xyz"); // set the 3 axes title size
	gStyle->SetTitleSize(0.06," ");   // set the pad title size
	gStyle->SetLabelFont(132,"xyz");
	gStyle->SetLabelSize(0.05,"xyz");
	gStyle->SetLabelColor(1,"xyz");
	gStyle->SetTextFont(132);
	gStyle->SetTextSize(0.08);
	gStyle->SetStatFont(132);
	
	// use bold lines and markers
	gStyle->SetMarkerStyle(8);
	gStyle->SetHistLineWidth(1.85);
	gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
	
	//..Get rid of X error bars
	gStyle->SetErrorX(0.001);
	
	// do not display any of the standard histogram decorations
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	gStyle->SetOptFit(11111111);
	
	// put tick marks on top and RHS of plots
	gStyle->SetPadTickX(1);
	gStyle->SetPadTickY(1);
	
	// set a decent palette
	gStyle->SetPalette(1);
	
	gStyle->cd();
	
	TColorWheel *w = new TColorWheel();
	
	icolor[0][1] = new TColor(1390, 0.90, 0.60, 0.60, ""); //red
	icolor[0][0] = new TColor(1391, 0.70, 0.25, 0.25, "");
	icolor[1][1] = new TColor(1392, 0.87, 0.87, 0.91, ""); //blue
	icolor[1][0] = new TColor(1393, 0.59, 0.58, 0.91, "");
	icolor[2][1] = new TColor(1394, 0.65, 0.55, 0.85, ""); //violet (gamma)
	icolor[2][0] = new TColor(1395, 0.49, 0.26, 0.64, "");
	icolor[3][1] = new TColor(1396, 0.95, 0.95, 0.60, ""); // yellow (alpha)
	icolor[3][0] = new TColor(1397, 0.95, 0.95, 0.00, "");
	icolor[4][1] = new TColor(1398, 0.75, 0.92, 0.68, ""); //green (2beta+gamma)
	icolor[4][0] = new TColor(1399, 0.36, 0.57, 0.30, "");
	icolor[5][1] = new TColor(1400, 0.97, 0.50, 0.09, ""); // orange
	icolor[5][0] = new TColor(1401, 0.76, 0.34, 0.09, "");
	icolor[6][1] = new TColor(1402, 0.97, 0.52, 0.75, ""); // pink
	icolor[6][0] = new TColor(1403, 0.76, 0.32, 0.51, "");
	icolor[7][1] = new TColor(1404, 0.49, 0.60, 0.82, ""); // dark blue (kpnn)
	icolor[7][0] = new TColor(1405, 0.43, 0.48, 0.52, "");
	icolor[8][1] = new TColor(1406, 0.70, 0.70, 0.70, "");  // black
	icolor[8][0] = new TColor(1407, 0.40, 0.40, 0.40, "");
	
	
	if(istyle == 0){
		
		//SM MC
		color_list[3][0] = kCyan+3;
		
		//DATA
		color_list[0][0] = 1;
		color_list[0][1] = 2;
		color_list[0][2] = 4;
		style_list[0][0] = 20;
		style_list[0][1] = 23;
		
		//BKG MC
		color_list[1][0] = 0;
		color_list[1][3] = kGreen-9; //Light green
		color_list[1][5] = kOrange-2; //dark blue
		color_list[1][4] = kGreen+3; //yellow
		color_list[1][1] = kBlue-10; //light blue
		color_list[1][2] = kBlue+4; //dark green
		style_list[1][0] = 1001;
		style_list[1][1] = 1001;
		style_list[1][2] = 3002;
		style_list[1][3] = 1001;
		style_list[1][4] = 1001;
		style_list[1][5] = 1001;
		
		//SIG MC
		color_list[2][0] = 1;
		color_list[2][1] = 1;
		color_list[2][2] = 1;
		style_list[2][0] = 2;
		style_list[2][1] = 5;
	}
	if(istyle == 1){
		
		//SM MC
		color_list[3][0] = kSpring+4;
		
		//DATA
		color_list[0][0] = 1;
		color_list[0][1] = 2;
		color_list[0][2] = 4;
		style_list[0][0] = 20;
		style_list[0][1] = 23;
		
		//BKG MC
		color_list[1][0] = 0;
		color_list[1][1] = kGreen-9; //Light green
		color_list[1][2] = kGreen+3; //dark blue
		color_list[1][3] = kYellow-7; //yellow
		color_list[1][4] = kBlue-10; //light blue
		color_list[1][5] = kBlue+4; //dark blue
		style_list[1][0] = 1001;
		style_list[1][1] = 1001;
		style_list[1][2] = 3002;
		style_list[1][3] = 1001;
		style_list[1][4] = 1001;
		style_list[1][5] = 1001;
		
		//SIG MC
		color_list[2][0] = 1;
		color_list[2][1] = 1;
		color_list[2][2] = 1;
		style_list[2][0] = 2;
		style_list[2][1] = 5;
	}
	if(istyle == 2){
		
		//SM MC
		color_list[3][0] = kMagenta+2;
		
		//DATA
		color_list[0][0] = 1;
		color_list[0][1] = 2;
		color_list[0][2] = 4;
		style_list[0][0] = 20;
		style_list[0][1] = 23;
		
		//BKG MC
		color_list[1][0] = 0;
		color_list[1][3] = kRed-9; //Light green
		color_list[1][5] = kRed+3; //dark blue
		color_list[1][4] = kYellow-7; //yellow
		color_list[1][1] = kMagenta-10; //light blue
		color_list[1][2] = kMagenta+4; //dark green
		style_list[1][0] = 1001;
		style_list[1][1] = 1001;
		style_list[1][2] = 3002;
		style_list[1][3] = 1001;
		style_list[1][4] = 1001;
		style_list[1][5] = 1001;
		
		//SIG MC
		color_list[2][0] = 1;
		color_list[2][1] = 1;
		color_list[2][2] = 1;
		style_list[2][0] = 2;
		style_list[2][1] = 5;
	}
	
}
