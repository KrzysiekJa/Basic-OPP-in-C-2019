#include <iostream>

using namespace std;

// C++ 11 std.
// n number' factorial generation with use of class

class factorial {
private:
	long long number;
	long long factorialF (long long x);
	
public:
	factorial (long long x) {
	  	number = x;
	};
	long long factorialF();
};

long long factorial::factorialF (long long x) {
	if (x == 0){
		return 1;
	} else {
		return (x * factorialF (x - 1));
	}
}

long long factorial::factorialF () {
	return factorialF (number);
}

int main (void)
{
	long long n=0;
	
	cout << "Number of factorial iterations: ";
	cin >> n;
	factorial fact(n);
	
	cout << fact.factorialF() << endl;
}