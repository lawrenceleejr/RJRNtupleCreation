#ifndef CompressedOptimization_h
#define CompressedOptimization_h

#include "OptimizationBase.hh"
#include "RJWorkshopBase.hh"

class CompressedOptimization : public OptimizationBase<RJWorkshopBase> {

public:
  CompressedOptimization();
  virtual ~CompressedOptimization();

protected:
  virtual double GetEventWeight();

private:
  virtual void InitCuts();
  virtual bool PassBaseline();
  virtual int EvaluateCuts();

};

#endif
