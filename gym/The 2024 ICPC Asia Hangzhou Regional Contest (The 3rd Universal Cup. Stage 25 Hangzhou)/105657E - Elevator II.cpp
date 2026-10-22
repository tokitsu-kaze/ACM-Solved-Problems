#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int l[MAX],r[MAX],id[MAX];
int main()
{
	int T,n,now,i,p;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&now);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			ans+=r[i]-l[i];
			id[i]=i;
		}
		sort(id+1,id+1+n,[&](int x,int y){
			return l[x]<l[y];
		});
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			if(r[id[i]]>=now)
			{
				ans+=max(0,l[id[i]]-now);
				now=r[id[i]];
				l[id[i]]=r[id[i]]=-1;
				res.push_back(id[i]);
			}
		}
		sort(id+1,id+1+n,[&](int x,int y){
			if(r[x]==r[y]) return l[x]>l[y];
			return r[x]<r[y];
		});
		for(i=n;i;i--)
		{
			if(r[id[i]]==-1) break;
			res.push_back(id[i]);
		}
		assert(res.size()==n);
		printf("%lld\n",ans);
		for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i+1==n]);
	}
	return 0;
}
/*
按l排序，每次选1-now中最远的，先走到顶，走到的点的r设置成-1。
再按r排序从顶往下走没有额外开销。
*/
