#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[n] = {0};
	for(int j=0; j<n; j++)cin>>a[j];

	int i = n-1;
	int Fmusbet = a[i];
	int Fmenfi = 0;

	i--;
	for(; i>=0; i--)
	{
		Fmusbet = a[i] + ( (Fmusbet > 0) ? Fmusbet:0 );
		Fmenfi = (Fmusbet > Fmenfi) ? Fmusbet : Fmenfi;
	}

	cout << Fmenfi << endl;
	
	return 0;
}