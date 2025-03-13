#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	int T,i;
	ll n,m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		vector<ll> res;
		res.push_back(n);
		for(i=0;i<60;i++)
		{
			if((n>>i)&1) continue;
			if((n|(1LL<<i))<=m) res.push_back(n|(1LL<<i));
		}
		if(res.size()==1) puts("-1");
		else
		{
			printf("%d\n",(int)res.size());
			for(i=0;i<res.size();i++) printf("%lld%c",res[i]," \n"[i+1==(int)res.size()]);
		}
	}
	return 0;
}
