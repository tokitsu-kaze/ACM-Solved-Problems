#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct node{int x,y;}a[MAX],tmp[MAX];
int st1[MAX],st2[MAX],top1,top2;
ll ans;
int cal(int l,int r,int tar)
{
	int mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(a[st2[mid+1]].y>tar) l=mid+1;
		else r=mid;
	}
	if(a[st2[l]].y<tar) return 0;
	return l+1;
}
void dfs(int l,int r)
{
	if(l==r) return;
	int i,j,tot;
	int mid=(l+r)>>1;
	dfs(l,mid);
	dfs(mid+1,r);
	top1=top2=tot=0;
	for(i=l,j=mid+1;i<=mid;)
	{
		if(j>r||a[i].y>a[j].y)
		{
			ans+=top2;
			while(top1&&a[i].x>a[st1[top1-1]].x) top1--;
			if(top1&&top2) ans-=cal(0,top2-1,a[st1[top1-1]].y);
			st1[top1++]=i;
			tmp[tot++]=a[i++];
		}
		else
		{
			while(top2&&a[j].x<a[st2[top2-1]].x) top2--;
			st2[top2++]=j;
			tmp[tot++]=a[j++];
		}
	}
	while(j<=r) tmp[tot++]=a[j++];
	for(i=0;i<tot;i++) a[i+l]=tmp[i];
}
int main()
{
	int n,i;
	scanf("%d",&n);
	set<int> sx,sy;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		sx.insert(a[i].x);
		sy.insert(a[i].y);
	}
	assert(sx.size()==n);
	assert(sy.size()==n);
	sort(a+1,a+1+n,[](const node &a,const node &b){
		return a.x<b.x;
	});
	ans=0;
	dfs(1,n);
	printf("%lld\n",ans);
	return 0;
}
