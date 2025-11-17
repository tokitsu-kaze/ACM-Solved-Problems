#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int mod=1e9+7;
int main()
{
	int T,i;
	ll n,sd;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		vector<ll> res;
		sd=10;
		for(i=0;i<18;i++)
		{
			if(n%(sd+1)==0) res.push_back(n/(sd+1));
			sd*=10;
		}
		sort(res.begin(),res.end());
		printf("%d\n",res.size());
		for(i=0;i<res.size();i++) printf("%lld%c",res[i]," \n"[i+1==res.size()]);
	}
	return 0;
}

