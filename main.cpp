#include <iostream>
#include "derived.h"
#include "base.h"
using std::cout;


//a simple test main showing off the class
int main(){
	zeroOut zero(-10.,10.);
	square squ;
	square squWithZero;
	zeroOut zeroTwo(-10,10);
	squWithZero.addAfter(&zeroTwo);
	for(int i=-20;i<21;i++){
		cout << i << " " << zero.evaluate(i) << " " << squ.evaluate(i) << " " << zeroTwo.evaluate(i) << "\n";
	}
}
