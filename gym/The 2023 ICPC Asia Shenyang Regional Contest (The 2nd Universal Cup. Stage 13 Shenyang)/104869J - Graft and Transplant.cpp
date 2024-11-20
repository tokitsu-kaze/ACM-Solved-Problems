#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=50+10;
vector<int> mp[MAX];
int main()
{
	int n,i,a,b,cnt;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	cnt=0;
	for(i=1;i<=n;i++)
	{
		if(mp[i].size()>1) cnt++;
	}
	if((cnt&1) || cnt==0) puts("Bob");
	else puts("Alice");
	return 0;
}
