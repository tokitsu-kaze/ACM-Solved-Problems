#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
vector<int> res[MAX];
int pos[MAX];
int main()
{
	int T,n,m,i,j,x,y,cntx,cnty;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		map<int,int> mp;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			mp[x]++;
			res[i].clear();
		}
		map<int,vector<int>> ban;
		while(m--)
		{
			scanf("%d%d",&x,&y);
			ban[x].push_back(y);
			ban[y].push_back(x);
		}
		for(auto &it:ban)
		{
			sort(it.second.begin(),it.second.end());
			reverse(it.second.begin(),it.second.end());
		}
		for(auto &it:mp) res[it.second].push_back(it.first);
		vector<int> len;
		for(i=1;i<=n;i++)
		{
			sort(res[i].begin(),res[i].end());
			if(res[i].size()>0) len.push_back(i);
			pos[i]=((int)res[i].size())-1;
		}
		ans=0;
		for(auto &it:mp)
		{
			x=it.first;
			cntx=it.second;
			for(auto &it:ban[x])
			{
				cnty=mp[it];
				if(pos[cnty]<0) continue;
				if(res[cnty][pos[cnty]]==x) pos[cnty]--;
				if(pos[cnty]<0) continue;
				if(res[cnty][pos[cnty]]==it) pos[cnty]--;
			}
			for(auto &cnty:len)
			{
				if(pos[cnty]<0) continue;
				if(res[cnty][pos[cnty]]==x) pos[cnty]--;
				if(pos[cnty]<0) continue;
				ans=max(ans,1LL*(cntx+cnty)*(x+res[cnty][pos[cnty]]));
			}
			for(auto &it:ban[x])
			{
				cnty=mp[it];
				pos[cnty]=((int)res[cnty].size())-1;
			}
			pos[cntx]=((int)res[cntx].size())-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
cnt[x]的种类数是根号的，然后就随便做了。
可以O(sqrt^2 * log)，O(nsqrt) 也可以卡过去。
*/
