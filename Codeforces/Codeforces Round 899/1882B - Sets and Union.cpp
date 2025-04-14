#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
vector<int> pos[MAX];
int s[55];
int main()
{
	int T,n,k,i,j,cnt,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<vector<int>> res;
		memset(s,0,sizeof s);
		for(i=1;i<=50;i++) pos[i].clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			vector<int> tmp(k);
			for(auto &it:tmp)
			{
				scanf("%d",&it);
				s[it]++;
				pos[it].push_back(i);
			}
			res.push_back(tmp);
		}
		ans=0;
		for(i=1;i<=50;i++)
		{
			if(s[i]==0) continue;
			for(auto &p:pos[i])
			{
				for(auto &it:res[p]) s[it]--;
			}
			cnt=0;
			for(j=1;j<=50;j++) cnt+=(s[j]>0);
			ans=max(ans,cnt);
			for(auto &p:pos[i])
			{
				for(auto &it:res[p]) s[it]++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
