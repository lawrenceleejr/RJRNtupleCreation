#ifndef GluinoOptimization_h
#define GluinoOptimization_h

#include "OptimizationBase.hh"
#include "RJWorkshopBase.hh"

class GluinoOptimization : public OptimizationBase<RJWorkshopBase> {

public:
  GluinoOptimization();
  virtual ~GluinoOptimization();

protected:
  virtual double GetEventWeight();

private:
  virtual void InitCuts();
  virtual bool PassBaseline();
  virtual int EvaluateCuts();

};

#endif
