#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int c,v;}a[MAX];
int cnt[MAX],vis[MAX];
int main()
{
	int n,k,m,i;
	ll ans;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i].c,&a[i].v);
	sort(a+1,a+1+n,[](node x,node y){
		return x.v>y.v;
	});
	for(i=1;i<=n;i++) cnt[i]=vis[i]=0;
	ans=0;
	for(i=1;i<=n && m>0;i++)
	{
		if(cnt[a[i].c]) continue;
		cnt[a[i].c]++;
		vis[i]=1;
		ans+=a[i].v;
		m--;
		k--;
	}
	for(i=1;i<=n && k>0;i++)
	{
		if(vis[i]) continue;
		ans+=a[i].v;
		k--;
	}
	printf("%lld\n",ans);
	return 0;
}
