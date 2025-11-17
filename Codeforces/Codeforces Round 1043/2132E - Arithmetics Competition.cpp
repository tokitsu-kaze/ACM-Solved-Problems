#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
struct node{int v,f;}c[MAX];
int a[MAX],b[MAX],ca[MAX],cb[MAX];
ll sa[MAX],sb[MAX],sc[MAX];
int main()
{
	int T,n,m,q,i,x,y,z,cnt;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) c[i]={a[i],0};
		for(i=n+1;i<=n+m;i++) c[i]={b[i-n],1};
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		sort(b+1,b+1+m);
		reverse(b+1,b+1+m);
		sort(c+1,c+1+n+m,[](node x,node y){
			return x.v>y.v;
		});
		sa[0]=sb[0]=sc[0]=ca[0]=cb[0]=0;
		for(i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
		for(i=1;i<=m;i++) sb[i]=sb[i-1]+b[i];
		for(i=1;i<=n+m;i++)
		{
			sc[i]=sc[i-1]+c[i].v;
			ca[i]=ca[i-1]+(!c[i].f);
			cb[i]=cb[i-1]+c[i].f;
		}
		while(q--)
		{
			scanf("%d%d%d",&x,&y,&z);
			ans=sc[z];
			if(ca[z]>x)
			{
				ans-=sa[ca[z]]-sa[x];
				cnt=ca[z]-x;
				ans+=sb[min(cb[z]+cnt,m)]-sb[cb[z]];
			}
			else if(cb[z]>y)
			{
				ans-=sb[cb[z]]-sb[y];
				cnt=cb[z]-y;
				ans+=sa[min(ca[z]+cnt,n)]-sa[ca[z]];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
