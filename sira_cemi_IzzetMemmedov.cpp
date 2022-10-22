/*
Algorithm designed by Izzet Memmedov
Code writed by kochrufet

Problem : Calculating subset of given array where the subset has max length and
the sum is max


*/


#include <iostream>

using namespace std;

int main()
{
	int n = 0;

	cout << " n=";
	cin >> n;
	
	cout << "Massiv: ";
	
	int a[n] = {0};
	for(int i=0; i<n; i++)cin>>a[i];

	int bell[n] = {a[0]};
	int left = 0;
	int right = 0;
	int maxi = 0;
	for(int i=1; i<n; i++)
	{
	bell[i] = (a[i]>a[i]+bell[i-1]) ? a[i] : a[i]+bell[i-1];
	maxi = (bell[i] >= bell[maxi]) ? i : maxi;
	}

	long long sum = bell[maxi];
	int i = maxi;
	while(sum)
	{
		sum -= a[i];
		i--;
	}

	for(int j=i+1; j<=maxi; j++)cout << a[j] << ' ';

	cout << endl;

	return 0;
}
