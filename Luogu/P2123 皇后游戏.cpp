#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e4+10;
struct node{int a,b;}tmp[MAX];
bool cmp(node x,node y)
{
	if(min(x.a,y.b)==min(y.a,x.b)) return x.a<y.a;
	return min(x.a,y.b)<min(y.a,x.b);
}
ll c[MAX];
int main()
{
	int T,n,i;
	ll ans,suma;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&tmp[i].a,&tmp[i].b);
		sort(tmp+1,tmp+1+n,cmp);
		c[1]=tmp[1].a+tmp[1].b;
		suma=tmp[1].a;
		ans=c[1];
		for(i=2;i<=n;i++)
		{
			suma+=tmp[i].a;
			c[i]=max(c[i-1],suma)+tmp[i].b;
			ans=max(ans,c[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
