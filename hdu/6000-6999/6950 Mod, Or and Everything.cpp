#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	ll x,res;
	cin>>T;
	while(T--)
	{
		cin>>x;
		res=2;
		while(res<x) res*=2;
		res>>=1;
		cout<<res-1<<"\n";
	}
	return 0;
}

