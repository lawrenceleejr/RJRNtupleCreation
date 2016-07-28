#include "CompressedOptimization.hh"

CompressedOptimization::CompressedOptimization()
  : OptimizationBase<RJWorkshopBase>() {}

CompressedOptimization::~CompressedOptimization() {}

double CompressedOptimization::GetEventWeight(){
  if(m_Base)
    return m_Base->weight;
  else
    return 0.;
}

bool CompressedOptimization::PassBaseline(){
  // trigger
  // if(m_Base->MDR <= 300.)
  //   return false;
  
  //  1st lead jet pT
  // if(m_Base->pT_jet1 <= 50.)
  //   return false;
  
  // 2nd lead jet pT
  // if(m_Base->pT_jet2 <= 200.)
  //   return false;

  // if(m_Base->dphiR < 0.8)
  //   return false;

  // if(m_Base->dphi < 0.2)
  //   return false;

  // if(m_Base->MET < 200.)
  //   return false;

  // compressed
   if(m_Base->NV < 1)
    return false;

  // if(m_Base->deltaQCD <= 0.0)
  //   return false;
  
  // if(m_Base->PIoHT1CM < 0.5)
  //   return false;

  // if(m_Base->MS < 400.)
  //   return false;

  // if(m_Base->cosS < 0.8)
  //   return false;

  // if(m_Base->RPT_HT1CM > 0.15)
  //   return false;

  return true;
}

void CompressedOptimization::InitCuts(){
  m_CutMin.clear();
  m_CutMax.clear();
  m_CutN.clear();
  m_CutVal.clear();

  // PTISR
  m_CutMin.push_back(700.);
  m_CutMax.push_back(1600.);
  m_CutN.push_back(3);
  m_CutVal.push_back(0.);

  // RISR
  m_CutMin.push_back(0.55);
  m_CutMax.push_back(0.95);
  m_CutN.push_back(8);
  m_CutVal.push_back(0.);

  // dphiISRI
  m_CutMin.push_back(2.95);
  m_CutMax.push_back(3.15);
  m_CutN.push_back(4);
  m_CutVal.push_back(0.);

  // pTjV1
  // m_CutMin.push_back(50.);
  // m_CutMax.push_back(80.);
  // m_CutN.push_back(6);
  // m_CutVal.push_back(0.);

  // MS
  m_CutMin.push_back(0.);
  m_CutMax.push_back(700.);
  m_CutN.push_back(7);
  m_CutVal.push_back(0.);

  // NV
  m_CutMin.push_back(1.);
  m_CutMax.push_back(6.);
  m_CutN.push_back(5);
  m_CutVal.push_back(0.);

  // dphiCMI
  // m_CutMin.push_back(0.0);
  // m_CutMax.push_back(2.0);
  // m_CutN.push_back(20);
  // m_CutVal.push_back(0.);

  // dphiCMI
  // m_CutMin.push_back(0.);
  // m_CutMax.push_back(2.8);
  // m_CutN.push_back(28);
  // m_CutVal.push_back(0.);
  
  // // // cosS
  // m_CutMin.push_back(0.4);
  // m_CutMax.push_back(1.);
  // m_CutN.push_back(60);
  // m_CutVal.push_back(0.);

  // // RPT_HT1CM
  // m_CutMin.push_back(0.3);
  // m_CutMax.push_back(0.);
  // m_CutN.push_back(30);
  // m_CutVal.push_back(0.);

   // deltaQCD
  // m_CutMin.push_back(-1.);
  // m_CutMax.push_back(1.);
  // m_CutN.push_back(100);
  // m_CutVal.push_back(0.);

  // Rsib
  // m_CutMin.push_back(0.5);
  // m_CutMax.push_back(0.);
  // m_CutN.push_back(200);
  // m_CutVal.push_back(0.);

  m_N_Cut = m_CutN.size();
}

int CompressedOptimization::EvaluateCuts(){
  int icut = 0;

  double MeffN = m_Base->pT_jet1+m_Base->pT_jet2+m_Base->pT_jet3+m_Base->pT_jet4+m_Base->MET;
  double HTN = m_Base->pT_jet1+m_Base->pT_jet2;
  //double METsig = m_Base->MET/sqrt(HTN);
  double METsig = m_Base->MET/sqrt(m_Base->Meff-m_Base->MET);
 

  if(m_Base->PTISR < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->RISR < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->dphiISRI < m_CutVal[icut])
    return icut;
  icut++;
  
  // if(m_Base->pTjV1 < m_CutVal[icut])
  //   return icut;
  // icut++;

  if(m_Base->MS < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->NV < m_CutVal[icut])
    return icut;
  icut++;

  // if(m_Base->dphiCMI < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(acos(-1.)-m_Base->dphiCMI < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->cosS < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->RPT_HT1CM > m_CutVal[icut])
  //   return icut;
  // icut++;
  
  // if(m_Base->deltaQCD < m_CutVal[icut])
  //   return false;

  // if(m_Base->Rsib > m_CutVal[icut])
  //   return false;
      
  return -1;
}
