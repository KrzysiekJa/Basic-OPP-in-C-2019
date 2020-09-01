#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>


using namespace std;

// C++ 11 std.
// program is generating a matrix of intigers and then is finding, if x
// is in martix, and then calculating the sume of elements upon the
// diagonal

int main (void)
{
	srand(time(NULL));
	
	int tab[5][5] = {};
	
	for (int i=0; i < 5; i++){
		for (int j=0; j < 5; j++){
			tab[i][j] = rand() % 89 + 10;
			cout << tab[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
	int x = rand() % 89 + 10;
	int change = 0;
	
	for (int i=0; i < 5; i++){
		for (int j=0; j < 5; j++){
			if (tab[i][j] == x){
				change = 1;
				goto next;
			}
		}
	}
	
	next:
	if (change == 0){
		cout << "Liczba " << x << " nie wystepuje w tablicy." << endl;
	} else {
		cout << "Liczba " << x << " wystepuje w tablicy." << endl;
	}
	
	int sum = 0;
	
	for (int i=0; i < 5; i++){
		for (int j=i + 1; j < 5; j++){
			sum += tab[i][j];
		}
	}
	
	cout << "Suma elementow nad przkatna: " << sum << endl;
}