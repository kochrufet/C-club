/*
Algorithm designed by Fuad teacher.
Full name Fuad Qurbanov
Code writed by kochrufet
Full name Rufat Talibzada

Version v1.0 --> supports x1,x2,x3

Date: 08.10.2022
*/

#include <iostream>

using namespace std;

int fmin(int x, int y, int z)
{
	int min = (x<y)?x:y;
	min = (min<z)?min:z;
	return min;
}

int fmin(int x, int y){return (x<y)?x:y;}

int main()
{
int n = 3;
int x[n] = {1,2,5};
int k = 12;cout<<"Meblegi daxil edin:";cin>>k;

int f[k+1] = {0};

f[0] = 0;
f[1] = x[0];

for(int i=2; i<=k; i++)
{

if( i >= x[2] )
f[i] = fmin(f[ i - x[0] ], f[ i - x[1] ], f[ i - x[2] ]) + 1;
else if( i >= x[1] )
f[i] = fmin(f[ i - x[0] ], f[ i - x[1] ]) + 1;
else if( i >= x[0] )
f[i] = f[ i - x[0] ] + 1;
else {cout<<"Qaytarmaq mumkun deyil."<<endl;return 0;}

}

cout << "Minimum " << f[k] << " sayda eskinasla qaytara bilersiniz." <<  endl;

return 0;
}
