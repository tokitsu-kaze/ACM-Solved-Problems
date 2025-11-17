#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int n,q,i,x,v;
	ll ans;
	char op[2];
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	ans=0;
	for(i=1;i<=n;i++) ans+=min(a[i],b[i]);
	while(q--)
	{
		scanf("%s%d%d",op,&x,&v);
		ans-=min(a[x],b[x]);
		if(op[0]=='A') a[x]=v;
		else b[x]=v;
		ans+=min(a[x],b[x]);
		printf("%lld\n",ans);
	}
	return 0;
}
