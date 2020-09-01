#include <iostream>

using namespace std;

// C++ 11 std.
// program is generating numbers between x and y

int main (void)
{
	int x;
	int y;
	
	do{
		cout << "Input x: ";
		cin  >> x;
	} while (x < 10 || x > 100);
	
	do{
		cout << "Input y: ";
		cin  >> y;
	} while (y < 10 || y > 100);
	
	if (x >= y){
		for (int i=y; i <= x; i++){
			cout << i << ' ';
		}
	} else {
		for (int i=x; i <= y; i++){
			cout << i << ' ';
		}
	}
	cout << endl;
}