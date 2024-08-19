#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
struct Q{int l,id;};
vector<Q> qst[MAX];
unsigned int a[MAX],b[MAX],c[MAX];
unsigned int ans[5*MAX],bit[MAX],tagsum[MAX];
int t[MAX];
int main()
{
	int n,m,i,j,l,r,p;
	unsigned int x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%u",&a[i]);
	for(i=1;i<=n;i++) scanf("%u",&b[i]);
	for(i=1;i<=n;i++) scanf("%u",&c[i]);
	for(i=1;i<=n;i++) qst[i].clear();
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		qst[r].push_back({l,i});
	}
	bit[0]=0;
	tagsum[0]=0;
	for(i=1;i<=n;i++)
	{
		p=i;
		for(j=i-1;j;j--)
		{
			x=a[j]&a[j+1];
			y=b[j]|b[j+1];
			z=__gcd(c[j],c[j+1]);
			if(x==a[j]&&y==b[j]&&z==c[j]) break;
			p=j;
			a[j]=x;
			b[j]=y;
			c[j]=z;
		}
		bit[i]=bit[i-1]+tagsum[i-1];
		for(j=p;j<=i;j++)
		{
			bit[j]+=tagsum[j]*(i-t[j]);
			tagsum[j]=tagsum[j-1]+a[j]*b[j]*c[j];
			t[j]=i;
		}
		for(auto &it:qst[i])
		{
			ans[it.id]=bit[i]+tagsum[i];
			ans[it.id]-=bit[it.l-1]+tagsum[it.l-1]*(i-t[it.l-1]+1);
		}
	}
	for(i=1;i<=m;i++) printf("%u\n",ans[i]);
	return 0;
}
