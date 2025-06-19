#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
ll sqr(ll x){return x*x%mod;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	ll n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<2*sqr(n%mod)*sqr((n-1)%mod)%mod<<"\n";
	}
	return 0;
}
