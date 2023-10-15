#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll n;
	cin>>n;

	vector<bool> isPrime(n+1,true);

	isPrime[0]=isPrime[1]=false;

	for(ll i=2; i*i<=n;i++)
	{
		if(isPrime[i]==true)
		{
			for(ll j=i*i;j<=n;j+=i)
			{
				isPrime[j]=false;
			}
		}
		
	}

	cout<<isPrime[7919];
}