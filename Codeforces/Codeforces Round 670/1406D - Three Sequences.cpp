#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
ll a[MAX],d[MAX];
int main()
{
	int n,i,q,l,r,x;
	ll ans,sumd;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sumd=0;
	for(i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
		if(d[i]>0) sumd+=d[i];
	}
	ans=a[1]+sumd;
	if(ans<0) printf("%lld\n",ans/2);
	else printf("%lld\n",(ans+1)/2);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&x);
		if(l>1 && d[l]>0) sumd-=d[l];
		if(r+1<=n && d[r+1]>0) sumd-=d[r+1];
		d[l]+=x;
		d[r+1]-=x;
		if(l>1 && d[l]>0) sumd+=d[l];
		if(r+1<=n && d[r+1]>0) sumd+=d[r+1];
		if(l==1) a[1]+=x;
		ans=a[1]+sumd;
		if(ans<0) printf("%lld\n",ans/2);
		else printf("%lld\n",(ans+1)/2);
	}
	return 0;
}
/*
通过观察发现，a增加的时候由b贡献，a减少的时候由c贡献。
贡献时，整个后缀会进行修改。
列式子化简后得到，
ans=((b1+c1)+sum{b对a的贡献})/2 向上取整
ans=(a1+sum{max(0,a[i]-a[i-1])})/2 向上取整。
修改随便维护一下。注意边界和负数的情况。
*/
