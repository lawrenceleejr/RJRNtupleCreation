
// RestFrames package include
#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

{
  
  /////////////////////////////////////////////////
  // Tree set-up - outside of event loop
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

  /////////////////////////////////////////////////////////

  /////////////////////////////////////////////////
  // observables we will calculate for each event
  /////////////////////////////////////////////////

  int Nj_ISR;
  int Nj_V;
  int Nb_ISR;
  int Nb_V;
  double pT_ISR;
  double pT_I;
  double R_ISR;
  double cosS;
  double dphiCMI;
  double MS;
  double MV;
  double MISR;

  //////////////////////////////////////////////////////////////////

      /////////////////////////////////////////////////
      // Event analysis with tree - inside of event loop
      /////////////////////////////////////////////////
      
      // we assume that this vector is filled with all the
      // jet 4-vectors from this event
      vector<TLorentzVector> JETs;

      // we assume that this 3-vector has the MET for this event
      TVector3 MET;

      if(JETs.size() < 1){
	// continue event loop if not at least one jet
      }

      //// analyze event ////
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
      ////////////////////////

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
	  if(false /*put b-tag for ith jet here*/)
	    Nb_ISR = Nb_ISR+1;
	} else {                           // sparticle group
	  temp_V++;
	  if(false /*put b-tag for ith jet here*/)
	    Nb_V = Nb_V+1;
	}
      }

      TVector3 vP_ISR = ISR.GetFourVector(CM).Vect();
      TVector3 vP_I   = I.GetFourVector(CM).Vect();

      pT_ISR = vP_ISR.Mag();
      pT_I   = vP_I.Mag();
      R_ISR = fabs(vP_I.Dot(vP_ISR.Unit())) / pT_ISR;
      cosS = S.GetCosDecayAngle();
      MS = S.GetMass();
      MV = V.GetMass();
      MISR = ISR.GetMass();
}
