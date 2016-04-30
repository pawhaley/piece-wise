#ifndef PWF_HEDDER
#define PWF_HEDDER

//this is the pure virtual class that knows how to evaluate a pecewise function
class PWFunc{
public:
	//setup
	PWFunc(){
		_next=nullptr;
	}
	//add our mask after sompthing else
	void addAfter(PWFunc* prev){
		_next=prev->_next;
		prev->_next=this;
	}
	//how to evaluate the masks
	double evaluate(double position){
		double retval;
		if(internalEval(retval,position)){
			return retval;
		}
		//assert: we couldn't handel it
		if(_next==nullptr){
			//WE HAVE A BIG PROBLEM!!!
			return -1;
		}
		return _next->evaluate(position);
	}
	~PWFunc(){}
protected:
	//this must be written for each sub class accepts a place to store the answe and the value to be evaluated,
	//returns true if it could be handeled
	virtual bool internalEval(double& toStore,double position)=0;
private:
	PWFunc* _next;
};

#endif
