#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll n;
	cin>>n;

	int c=0;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			cout<<i<<' '<<n/i<<' '<<n-(n/i)<<endl;
			c++;
		}
	}
	cout<<"Total "<<2*c<<endl;
}