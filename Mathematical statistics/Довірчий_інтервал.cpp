#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int main(void) {

	int Size = 0;
	int k;
	int chastota = 0;
int n[k];
/*int A[3] = {1,5,7};
int B[3] = {2,8,1};
int m=0;
for (int i =1; i<=3; i++){
	m  = m + A[i]*B[i];
}
//cout << m;*/

double s=0;
int Array[37] = {84, 119, 100, 95, 101, 91, 97, 90, 121, 122, 87, 98, 88, 92, 109, 105, 86, 93, 96, 94, 115, 114, 81, 110, 117, 103, 102, 99, 106, 79, 104, 74, 111, 83, 107, 108, 89};
int Arr[37] = {1,1,6,2,6,4,2,3,1,1,5,5,1,2,2,2,2,4,4,5,2,3,2,4,1,2,2,4,2,2,2,1,2,1,3,1,2};
for (int i=0; i<37;i++){
	s = s + (Array[i]-98.46315789473684)*(Array[i]-98.46315789473684)*Arr[i];
}
//s= s/94;
cout << s;
/*cout << "Enter your elements";
for (int i = 0; i < Size; ++i)
{
    cout << "Enter " << i+1 << " element: ";
    cin >> Array[i];
    
    cin.sync();
}

for(int i=0;i< Size; ++i)
{
   for(int j = i+1;j < Size;++j)
   {
      if(Array[i]==Array[j])
        
        chastota = chastota + 1; 
        n[i] = chastota;
       
   }
}

for (int i=0; i<chastota; i++)
{cout << n[i];
}*/
}
