/*
Author: kochrufet
Fullname: Rufat Talibzada

Money exchanging program in C++ with Greedy Algorithm

Interface language support: Azerbaijan

Date: 08.10.2022
*/

#include <iostream>
using namespace std;

void input(int* p, int n){while(--n)cin>>*(++p);}
void print(int* p, int n){while(--n)cout<<*(++p)<<' ';}

int main()
{
int k;cout<<" Meblegi daxil edin k=";cin>>k;cout<<" Vahidlerin olcusunu daxil edin n=";
int n; cin >> n;
int a[n+1]; // 1 2 5
int b[n+1] = {0};cout<<"Vahidleri daxil edin: ";
input(a,n+1);
int res = 0;
for(int i=n; i>0; i--)
{
	if(k < a[i])continue;
	b[i] = k / a[i];
	k -= b[i] * a[i];
	res+=b[i];
}

if(k)cout<<"Bolune bilmez.";
else
{
for(int j=n; j>0; j--)
{
	if(j!=n)cout<<"+";
	cout << b[j] << "*" << a[j];
}
cout<<" usulla "<<res<<" sayda eskinasla bolmek olar.";
}
cout<<endl;

return 0;
}
