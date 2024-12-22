#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
vector<int> mp[MAX];
int main()
{
	int n,i,a,b,ans,mn,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		vector<int> tmp;
		for(auto &to:mp[i]) tmp.push_back(mp[to].size());
		sort(tmp.begin(),tmp.end());
		reverse(tmp.begin(),tmp.end());
		cnt=0;
		for(auto &it:tmp)
		{
			cnt++;
			ans=max(ans,1+cnt*it);
		}
	}
	printf("%d\n",n-ans);
	return 0;
}
