#ifndef SquarkOptimization_h
#define SquarkOptimization_h

#include "OptimizationBase.hh"
#include "RJWorkshopBase.hh"

class SquarkOptimization : public OptimizationBase<RJWorkshopBase> {

public:
  SquarkOptimization();
  virtual ~SquarkOptimization();

protected:
  virtual double GetEventWeight();

private:
  virtual void InitCuts();
  virtual bool PassBaseline();
  virtual int EvaluateCuts();

};

#endif
