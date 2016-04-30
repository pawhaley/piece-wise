#ifndef DERIVEDPWF_HEADDER
#define DERIVEDPWF_HEADDER
#include "base.h"

//a mask class that sets evrything outside of a range to zero
class zeroOut : public PWFunc{
public:
	//accepts a min and max and will become a mask zeroing out anything outside of that range
	zeroOut(double min,double max){
		_min=min;
		_max=max;
	}
	~zeroOut(){}
private:
	//this will be used only by the PWFunc class
	bool internalEval(double& toStore,double position) override{
		if(position>_max || position<_min){
			toStore=0;
			return true;
		}
		return false;
	}
	double _min;
	double _max;
};


//a class that squares its input
class square : public PWFunc{
	//always works
	bool internalEval(double& toStore,double position) override{
		toStore=position*position;
		return true;
	}
public:
	~square(){}
};


#endif
