#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const ll LIMT=4e18;
int ans[MAX];
int main()
{
	int T,n,q,i,op,x;
	ll tot,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		vector<pair<ll,int>> res;
		tot=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&op,&x);
			if(tot>=1e18) continue;
			if(op==1)
			{
				tot++;
				res.push_back({tot,x});
			}
			else
			{
				if(tot>LIMT/(x+1)) tot=LIMT;
				else tot*=(x+1);
			}
		}
		sort(res.begin(),res.end());
		for(i=1;i<=q;i++)
		{
			scanf("%lld",&k);
			while(k)
			{
				auto it=upper_bound(res.begin(),res.end(),
									pair<ll,int>{k,INF});
				it--;
				k%=(*it).first;
				if(k==0)
				{
					ans[i]=(*it).second;
					break;
				}
	//			printf("%d %lld\n",i,k);
			}
		}
		for(i=1;i<=q;i++) printf("%d%c",ans[i]," \n"[i==q]);
		
	}
	return 0;
}
