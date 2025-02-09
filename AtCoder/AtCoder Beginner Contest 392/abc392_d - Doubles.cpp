#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=3e5+10;
map<int,int> mp[105];
int cnt[105];
int main()
{
	int n,i,j,x;
	double fz,fm,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		scanf("%d",&cnt[i]);
		for(j=1;j<=cnt[i];j++)
		{
			scanf("%d",&x);
			mp[i][x]++;
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			fm=1LL*cnt[i]*cnt[j];
			fz=0;
			for(auto &it:mp[i])
			{
				if(!mp[j].count(it.first)) continue;
				fz+=1LL*it.second*mp[j][it.first];
			}
			ans=max(ans,fz/fm);
		}
	}
	printf("%.10f\n",ans);
	return 0;
}
