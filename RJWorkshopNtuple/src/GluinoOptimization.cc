#include "GluinoOptimization.hh"

GluinoOptimization::GluinoOptimization()
  : OptimizationBase<RJWorkshopBase>() {}

GluinoOptimization::~GluinoOptimization() {}

double GluinoOptimization::GetEventWeight(){
  if(m_Base)
    return m_Base->weight;
  else
    return 0.;
}

bool GluinoOptimization::PassBaseline(){
  // trigger
  if(m_Base->MET <= 200.)
    return false;
  // gluino-gluino
  if(m_Base->NJa < 2. || m_Base->NJb < 2.)
    return false;


  if(m_Base->deltaQCD <= 0.0)
    return false;

  double RPT = m_Base->pTCM / (m_Base->pTCM + m_Base->HT5PP);

  if(RPT > 0.09)
    return false;
  // if(((m_Base->dphiPPV < 0.5)||(acos(-1)-m_Base->dphiPPV < 0.2)) && RPT > 0.08)
  //   return false;

  // if(m_Base->RPT >= 0.4)
  //   return false;
  // if(((m_Base->dphiPPV < 0.5)||(acos(-1)-m_Base->dphiPPV < 0.2)) && m_Base->RPT > 0.2)
  //   return false;
  
   // 1st lead jet pT
  // if(m_Base->pT_jet1 <= 50.)
  //   return false;
  
  // // 2nd lead jet pT
  // if(m_Base->pT_jet2 <= 50.)
  //   return false;

  // if(m_Base->dphiR < 0.4)
  //   return false;

  // if(m_Base->dphi < 0.2)
  //   return false;

  // if(m_Base->Aplan < 0.04)
  //   return false;


  if(m_Base->R_H2PP_H5PP <= 0.2)
    return false;

  if(m_Base->R_HT5PP_H5PP < 0.65)
    return false;

  if(m_Base->RPZ_HT5PP > 0.6)
    return false;

  if(m_Base->minR_pTj2i_HT3PPi < 0.09)
    return false;

  if(m_Base->maxR_H1PPi_H2PPi > 0.98)
    return false;

  // if(fabs(m_Base->dangle) > 0.5)
  //   return false;

  return true;
}

void GluinoOptimization::InitCuts(){
  m_CutMin.clear();
  m_CutMax.clear();
  m_CutN.clear();
  m_CutVal.clear();

  // HT5PP
  m_CutMin.push_back(1600.);
  m_CutMax.push_back(3100.);
  m_CutN.push_back(15);
  m_CutVal.push_back(0.);

  // H2PP
  m_CutMin.push_back(400.);
  m_CutMax.push_back(1200.);
  m_CutN.push_back(64);
  m_CutVal.push_back(0.);

  // R_H2PP_H5PP 
  // m_CutMin.push_back(0.0);
  // m_CutMax.push_back(0.5);
  // m_CutN.push_back(50);
  // m_CutVal.push_back(0.);

  // R_HT5PP_H5PP
  // m_CutMin.push_back(0.);
  // m_CutMax.push_back(1.);
  // m_CutN.push_back(100);
  // m_CutVal.push_back(0.);

  // Rpz
  // m_CutMin.push_back(0.8);
  // m_CutMax.push_back(0.3);
  // m_CutN.push_back(50);
  // m_CutVal.push_back(0.);

  // minR_pTj2i_HT3PPi
  // m_CutMin.push_back(0.0);
  // m_CutMax.push_back(0.2);
  // m_CutN.push_back(80);
  // m_CutVal.push_back(0.);

  // maxR_H1PPi_H2PPi
  // m_CutMin.push_back(1.);
  // m_CutMax.push_back(.9);
  // m_CutN.push_back(100);
  // m_CutVal.push_back(0.);

  // dangle
  // m_CutMin.push_back(1.);
  // m_CutMax.push_back(0.3);
  // m_CutN.push_back(56);
  // m_CutVal.push_back(0.); 


  m_N_Cut = m_CutN.size();
}

int GluinoOptimization::EvaluateCuts(){
  int icut = 0;

  double MeffN = m_Base->pT_jet1+m_Base->pT_jet2+m_Base->pT_jet3+m_Base->pT_jet4+m_Base->MET;

 
  if(m_Base->HT5PP < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->H2PP < m_CutVal[icut])
    return icut;
  icut++;

  // if(m_Base->R_H2PP_H5PP < m_CutVal[icut])
  //    return icut;
  // icut++;

  //  if(m_Base->R_HT5PP_H5PP < m_CutVal[icut])
  //    return icut;
  // icut++;

  // if(m_Base->RPZ_HT5PP > m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->minR_pTj2i_HT3PPi < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->maxR_H1PPi_H2PPi > m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(fabs(m_Base->dangle) > m_CutVal[icut])
  //   return icut;
  // icut++;
  
  
  return -1;
}
