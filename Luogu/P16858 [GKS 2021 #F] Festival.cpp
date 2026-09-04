#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct node{int v,f;};
vector<node> res[MAX];
int main()
{
	int T,cas,d,n,k,i,h,l,r;
	ll ans,sum;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d%d%d",&d,&n,&k);
		for(i=1;i<=d;i++) res[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&h,&l,&r);
			res[l].push_back({h,1});
			res[r+1].push_back({h,-1});
		}
		multiset<int> now,tmp;
		ans=sum=0;
		for(i=1;i<=d;i++)
		{
			for(auto &it:res[i])
			{
				if(it.f==1)
				{
					now.insert(it.v);
					sum+=it.v;
					if(now.size()>k)
					{
						sum-=*now.begin();
						tmp.insert(*now.begin());
						now.erase(now.begin());
					}
				}
				else
				{
					if(tmp.find(it.v)!=tmp.end())
					{
						tmp.erase(tmp.find(it.v));
						continue;
					}
					now.erase(now.find(it.v));
					sum-=it.v;
					if(tmp.size()>0)
					{
						sum+=*tmp.rbegin();
						now.insert(*tmp.rbegin());
						tmp.erase(tmp.find(*tmp.rbegin()));
					}
				}
			}
			ans=max(ans,sum);
		}
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}
/*
把区间差分一下，用两个multiset分别维护 当前时间的前k大值 和 不在前k大内的值。
*/
