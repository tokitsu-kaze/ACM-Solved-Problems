#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
struct Point{double x,y;}a[MAX],tmp[MAX];
double sqr(double x){return x*x;}
double get_dis(Point a,Point b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
double dfs(int l,int r)
{
	if(l==r) return 2e9;
	int i,j,tot,mid;
	double ans,midx;
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
		if(fabs(a[i].x-midx)<ans) tmp[++tot]=a[i];
	}
	for(i=1;i<=tot;i++)
	{
		for(j=i+1;j<=tot;j++)
		{
			if(fabs(tmp[i].y-tmp[j].y)>ans) break;
			ans=min(ans,get_dis(tmp[i],tmp[j]));
		}
	}
	return ans;
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lf%lf",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,[&](Point a,Point b){
		return a.x<b.x;
	});
	printf("%.4f\n",dfs(1,n));
	return 0;
}
