#include "SquarkOptimization.hh"

SquarkOptimization::SquarkOptimization()
  : OptimizationBase<RJWorkshopBase>() {}

SquarkOptimization::~SquarkOptimization() {}

double SquarkOptimization::GetEventWeight(){
  if(m_Base)
    return m_Base->weight;
  else
    return 0.;
}

bool SquarkOptimization::PassBaseline(){
  // trigger
  // if(m_Base->MDR <= 300.)
  //   return false;
  // gluino-gluino
  // if(m_Base->NJa < 1. || m_Base->NJb < 1.)
  //   return false;

  if(m_Base->MET <= 200.)
    return false;

  if(m_Base->deltaQCD <= 0.0)
    return false;

  double RPT = m_Base->pTCM / (m_Base->pTCM + m_Base->HT3PP);

  if(RPT > 0.08)
    return false;
  
   // 1st lead jet pT
  // if(m_Base->pT_jet1 <= 50.)
  //   return false;
  
  // // 2nd lead jet pT
  // if(m_Base->pT_jet2 <= 200.)
  //   return false;

  // if(m_Base->dphiR < 0.8)
  //   return false;

  // if(m_Base->dphi < 0.2)
  //   return false;


  // if(m_Base->R_H2PP_H3PP <= 0.4)
  //   return false;

  // if(m_Base->R_H2PP_H3PP > 0.99)
  //   return false;
   
  // if(m_Base->pTPP_jet2a < 140. || m_Base->pTPP_jet2b < 140. )
  //   return false;

  // if(m_Base->pTPP_jet2/m_Base->HT3PP < 0.13)
  //   return false;

  // if(m_Base->RPZ_HT3PP >= 0.63)
  //   return false;

  // if(fabs(m_Base->cosP) > 0.65)
  //   return false;

  // if(fabs(m_Base->sangle) > 0.8)
  //   return false;

  return true;
}

void SquarkOptimization::InitCuts(){
  m_CutMin.clear();
  m_CutMax.clear();
  m_CutN.clear();
  m_CutVal.clear();



  // HT3PP
  m_CutMin.push_back(1700.);
  m_CutMax.push_back(2300.);
  m_CutN.push_back(6);
  m_CutVal.push_back(0.);

  // // H2PP
  m_CutMin.push_back(1300.);
  m_CutMax.push_back(1900.);
  m_CutN.push_back(6);
  m_CutVal.push_back(0.);

  // H2PP / H3PP down
  m_CutMin.push_back(0.5);
  m_CutMax.push_back(0.7);
  m_CutN.push_back(1);
  m_CutVal.push_back(0.);

   // H2PP / H3PP up
  m_CutMin.push_back(0.98);
  m_CutMax.push_back(0.87);
  m_CutN.push_back(1);
  m_CutVal.push_back(0.);

  // Rpz
  m_CutMin.push_back(0.63);
  m_CutMax.push_back(0.45);
  m_CutN.push_back(1);
  m_CutVal.push_back(0.);

  // // pT2 / HT3PP
  m_CutMin.push_back(0.0);
  m_CutMax.push_back(0.25);
  m_CutN.push_back(100);
  m_CutVal.push_back(0.);

   // cosP
  m_CutMin.push_back(0.8);
  m_CutMax.push_back(0.5);
  m_CutN.push_back(1);
  m_CutVal.push_back(0.); 

  // Meff
  // m_CutMin.push_back(1600.);
  // m_CutMax.push_back(2400.);
  // m_CutN.push_back(2);
  // m_CutVal.push_back(0.);

   // MET sig
  // m_CutMin.push_back(20.);
  // m_CutMax.push_back(25.);
  // m_CutN.push_back(1);
  // m_CutVal.push_back(0.);

  // 2nd lead jet pT
  // m_CutMin.push_back(150.);
  // m_CutMax.push_back(250.);
  // m_CutN.push_back(50);
  // m_CutVal.push_back(0.);


  m_N_Cut = m_CutN.size();
}

int SquarkOptimization::EvaluateCuts(){
  int icut = 0;

  // double MeffN = m_Base->pT_jet1+m_Base->pT_jet2+m_Base->pT_jet3+m_Base->pT_jet4+m_Base->MET;
  // double HTN = m_Base->pT_jet1+m_Base->pT_jet2;
  // //double METsig = m_Base->MET/sqrt(HTN);
  // double METsig = m_Base->MET/sqrt(m_Base->Meff-m_Base->MET);
  // // double METsig = m_Base->MET/sqrt(m_Base->pT_jet1+m_Base->pT_jet2+max(m_Base->pT_jet3,0.)+max(m_Base->pT_jet4,0.));

  // double minPT2o1PP = min(m_Base->pTPP_jet2a/m_Base->pTPP_jet1a,m_Base->pTPP_jet2b/m_Base->pTPP_jet1b);
  // double minPToP1PP = min(m_Base->pTPP_jet1a/m_Base->pPP_jet1a,m_Base->pTPP_jet1b/m_Base->pPP_jet1b);
  
  if(m_Base->HT3PP < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->H2PP < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->R_H2PP_H3PP < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->R_H2PP_H3PP > m_CutVal[icut])
    return icut;
  icut++;
  
  if(m_Base->RPZ_HT3PP > m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->pTPP_jet2/m_Base->HT3PP < m_CutVal[icut])
    return icut;
  icut++;

  if(fabs(m_Base->cosP) > m_CutVal[icut])
    return icut;
  icut++;
  
   // double pT_V1a = max(m_Base->pTPP_V1a,m_Base->pTPP_V2a);
   // double pT_V1b = max(m_Base->pTPP_V1b,m_Base->pTPP_V2b); 
   // double pT_V2a = min(m_Base->pTPP_V1a,m_Base->pTPP_V2a);
   // double pT_V2b = min(m_Base->pTPP_V1b,m_Base->pTPP_V2b);
  
  // if(min(m_Base->pTPP_jet1a,m_Base->pTPP_jet1b)/m_Base->HT3PP < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(min(m_Base->pTPP_Va,m_Base->pTPP_Vb)/m_Base->HT3PP < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->pTPP_jet2/m_Base->HT3PP < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->Meff < m_CutVal[icut])
  //   return icut;
  // icut++;

  //  if(METsig < m_CutVal[icut])
  //   return icut;
  //  icut++;

  // if(m_Base->pT_jet2 < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->pTPP_jet1a < m_CutVal[icut] || m_Base->pTPP_jet1b < m_CutVal[icut] )
  //   return icut;
  // icut++;

  // if(m_Base->deltaQCD < m_CutVal[icut])
  //   return false;
      
  return -1;
}
