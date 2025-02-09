#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
vector<int> mp[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			mp[a[i]].push_back(b[i]);
			mp[b[i]].push_back(a[i]);
		}
		ans=0;
		for(i=1;i<n;i++)
		{
			ans=max(ans,((int)mp[a[i]].size())+((int)mp[b[i]].size())-2);
		}
		set<pair<int,int>> s;
		for(i=1;i<=n;i++) s.insert({mp[i].size(),i});
		for(i=1;i<=n;i++)
		{
			s.erase({mp[i].size(),i});
			for(auto &to:mp[i]) s.erase({mp[to].size(),to});
			if(s.size()>0) ans=max(ans,((int)mp[i].size())+(*s.rbegin()).first-1);
			for(auto &to:mp[i]) s.insert({mp[to].size(),to});
			s.insert({mp[i].size(),i});
		}
		printf("%d\n",ans);
	}
	return 0;
}
