#include <iostream>
#include <cmath>

using namespace std;

// C++ 11 std.

class triangle_numerics
{
public:
	double a, b, c; // triangle sides
	double circumference (double a, double b, double c);
private:
	bool   isIttriangle (double, double, double);
};

double triangle_numerics::circumference (double a, double b, double c)
{
	if (isIttriangle (a, b, c) == false){
		cout << "This isn't sides of triangle.\n";
		return(false);
	} else {
		return a + b + c; 
	}
}

bool triangle_numerics::isIttriangle (double a, double b, double c)
{
	// finding if Pythagoras' statement is fulfilled
	double max=0, el1=0, el2=0;
	
	if (a >= b && a >= c){ 
		max = a;
		el1 = b;
		el2 = c;
	} else {
		if (b >= a && b >= c){
			max = b;
			el1 = a;
			el2 = c;
		} else {
			max = c;
			el1 = a;
			el2 = b;
		}
	}
	
	if (pow (max, 2) == pow (el1, 2) + pow (el2, 2)){
		return true;
	} else {
		return false;
	}
}


int main (void)
{
	double a=0, b=0, c=0; // triangle sides
	
	cout<< "If you want to stop use Crtl + D"
		<< endl
		<< "Please put sides of the tringle :"
		<< endl;
	
	while (1){
		cin >> a >> b >> c;
		triangle_numerics* trian_1 = new triangle_numerics;
		cout << "Circumference of tringle: " << trian_1 -> circumference (a, b, c) << endl;
		delete trian_1;
	}
}