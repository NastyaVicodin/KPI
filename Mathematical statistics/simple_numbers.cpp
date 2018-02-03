#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

int main ()
{
//	int n = 2;
	signed long k;
//	int s;
	cout << "Enter your number:";
	cin >> k;
//	int k = pow(n, s) - 1;
	cout << k;
    int i;
    for (i = 3; i<k-2; i=i+2 ){
    	double b = k%i;
    	if (b == 0) {
		cout << "not simple :c, because of " << i;
		break;}
		if ((b!=0)&(i=k-4)) 
		cout << "SIMPLE!!!!!!!!"; 
    }
    
    _getch();
    return 0;
}
