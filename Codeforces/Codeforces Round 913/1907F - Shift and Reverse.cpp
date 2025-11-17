#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct node{int l,r;};
int a[MAX],c[MAX];
int ckr(int n,int stp,int revcnt)
{
//	cout<<stp<<endl;
	int i,tot;
	tot=0;
	for(i=n-stp+1;i<=n;i++) c[++tot]=a[i];
	for(i=1;i<=n-stp;i++) c[++tot]=a[i];
	while(revcnt--) reverse(c+1,c+1+n);
	for(i=2;i<=n;i++)
	{
		if(c[i]<c[i-1]) return 0;
	}
	return 1;
}
int ckl(int n,int stp,int revcnt)
{
//	cout<<stp<<endl;
	int i,tot;
	tot=0;
	for(i=stp+1;i<=n;i++) c[++tot]=a[i];
	for(i=1;i<=stp;i++) c[++tot]=a[i];
	while(revcnt--) reverse(c+1,c+1+n);
	for(i=2;i<=n;i++)
	{
		if(c[i]<c[i-1]) return 0;
	}
	return 1;
}
int main()
{
	int T,n,i,mn,pre,l,r,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		mn=1e9;
		for(i=1;i<=n;i++) mn=min(mn,a[i]);
		vector<node> res;
		pre=-1;
		for(i=1;i<=n;i++)
		{
			if(a[i]==mn)
			{
				if(pre!=mn) l=r=i;
				else r++;
			}
			else
			{
				if(pre==mn) res.push_back({l,r});
			}
			pre=a[i];
		}
		if(pre==mn) res.push_back({l,r});
		if(res.size()>2)
		{
			puts("-1");
			continue;
		}
		ans=INF;
		if(res.size()==2)
		{
			if(res[0].l!=1 || res[1].r!=n)
			{
				puts("-1");
				continue;
			}
			if(ckr(n,res[1].r-res[1].l+1,0)) ans=min(ans,res[1].r-res[1].l+1);
			if(ckl(n,res[0].r-res[0].l+1,1)) ans=min(ans,res[0].r-res[0].l+1+1);
		}
		else
		{
			if(ckr(n,n-res[0].l+1,0)) ans=min(ans,n-res[0].l+1);
			if(ckr(n,n-res[0].r,1)) ans=min(ans,n-res[0].r+1);
			if(ckl(n,res[0].l-1,2)) ans=min(ans,res[0].l-1+2);
			if(ckl(n,res[0].r,1)) ans=min(ans,res[0].r+1);
			if(ckr(n,0,0)) ans=0;
		}
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}
