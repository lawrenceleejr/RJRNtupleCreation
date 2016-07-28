double EvaluateMetric(double Nsig, double Nbkg, double Dbkg){
  double Nobs = Nsig+Nbkg;
  double tau = 1./Nbkg/(Dbkg/Nbkg)/(Dbkg/Nbkg);
  double aux = Nbkg*tau;
  double Pvalue = TMath::BetaIncomplete(1./(1.+tau),Nobs,aux+1.);
  return sqrt(2.)*TMath::ErfcInverse(Pvalue*2);
}
