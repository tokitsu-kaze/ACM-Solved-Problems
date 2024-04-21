#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
struct Point{ll x,y;}a[MAX],tmp[MAX];
ll sqr(ll x){return x*x;}
ll get_dis(Point a,Point b){return sqr(a.x-b.x)+sqr(a.y-b.y);}
ll dfs(int l,int r)
{
	if(l==r) return 1e18;
	int i,j,tot,mid;
	ll ans,midx;
	mid=(l+r)>>1;
	midx=a[mid].x;
	ans=min(dfs(l,mid),dfs(mid+1,r));
	
	i=l;
	j=mid+1;
	tot=0;
	while(i<=mid&&j<=r)
	{
		if(a[i].y<a[j].y) tmp[++tot]=a[i++];
		else tmp[++tot]=a[j++];
	}
	while(i<=mid) tmp[++tot]=a[i++];
	while(j<=r) tmp[++tot]=a[j++];
	for(i=1;i<=tot;i++) a[l+i-1]=tmp[i];
	
	tot=0;
	for(i=l;i<=r;i++)
	{
		if(sqr(a[i].x-midx)<ans) tmp[++tot]=a[i];
	}
	for(i=1;i<=tot;i++)
	{
		for(j=i+1;j<=tot;j++)
		{
			if(sqr(tmp[i].y-tmp[j].y)>=ans) break;
			ans=min(ans,get_dis(tmp[i],tmp[j]));
		}
	}
	return ans;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,[&](Point a,Point b){
		return a.x<b.x;
	});
	printf("%lld\n",dfs(1,n));
	return 0;
}
