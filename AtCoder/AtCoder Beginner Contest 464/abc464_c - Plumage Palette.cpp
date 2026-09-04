#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct node{int a,b;};
vector<node> res[MAX];
int cnt[MAX];
int main()
{
	int n,m,i,a,d,b,ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) res[i].clear();
	for(i=1;i<=n;i++) cnt[i]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&d,&b);
		res[d].push_back({a,b});
		cnt[a]++;
	}
	ans=0;
	for(i=1;i<=n;i++) ans+=(cnt[i]>0);
	for(i=1;i<=m;i++)
	{
		for(auto &it:res[i])
		{
			cnt[it.a]--;
			if(cnt[it.a]==0) ans--;
			cnt[it.b]++;
			if(cnt[it.b]==1) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
