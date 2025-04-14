#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int ans[MAX];
int main()
{
	int T,n,m,q,i,x,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		vector<int> res;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			res.push_back(x);
		}
		sort(res.begin(),res.end());
		for(i=1;i<=q;i++)
		{
			scanf("%d",&x);
			auto itl=upper_bound(res.begin(),res.end(),x);
			auto itr=lower_bound(res.begin(),res.end(),x);
			if(itl==res.begin())
			{
				ans[i]=(*itr)-1;
				continue;
			}
			itl--;
			if(itr==res.end())
			{
				ans[i]=n-(*itl);
				continue;
			}
			p=((*itl)+(*itr))>>1;
			ans[i]=min(p-(*itl),(*itr)-p);
		}
		for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
