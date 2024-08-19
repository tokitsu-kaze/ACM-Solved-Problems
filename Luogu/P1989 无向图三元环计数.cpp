#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<int> mp[MAX];
int a[MAX],b[MAX],in[MAX],cnt[MAX];
int main()
{
	int n,m,i,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		in[i]=cnt[i]=0;
		mp[i].clear();
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		in[a[i]]++;
		in[b[i]]++;
	}
	for(i=1;i<=m;i++)
	{
		if(in[a[i]]>in[b[i]]) swap(a[i],b[i]);
		else if(in[a[i]]==in[b[i]])
		{
			if(a[i]>b[i]) swap(a[i],b[i]);
		}
		mp[a[i]].push_back(b[i]);
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(auto &j:mp[i]) cnt[j]++;
		for(auto &j:mp[i])
		{
			for(auto &k:mp[j]) ans+=cnt[k];
		}
		for(auto &j:mp[i]) cnt[j]--;
	}
	printf("%d\n",ans);
	return 0;
}
