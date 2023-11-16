#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
//x is a prime if prime[x]==x(x>=2)
int p[MAX],tot,prime[MAX];
void init(int n)
{
	int i,j;
	tot=0;
	memset(prime,0,sizeof prime);
	prime[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!prime[i]) prime[i]=p[tot++]=i;
		for(j=0;j<tot&&p[j]*i<=n;j++)
		{
			prime[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
struct Disjoint_Set_Union
{
	int pre[MAX],sz[MAX];
	void init(int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			pre[i]=i;
			sz[i]=1;
		}
	}
	int find(int x)
	{
		if(pre[x]!=x) pre[x]=find(pre[x]);
		return pre[x];
	}
	bool merge(int a,int b)
	{
		int ra,rb;
		ra=find(a);
		rb=find(b);
		if(ra!=rb)
		{
			pre[ra]=rb;
			sz[rb]+=sz[ra];
			return 1;
		}
		return 0;
	}
}dsu;
int main()
{
	int l,r,x,i,j,ans;
	scanf("%d%d%d",&l,&r,&x);
	init(r);
	dsu.init(r);
	for(i=0;i<tot;i++)
	{
		if(p[i]<x) continue;
		for(j=p[i];j<=r;j+=p[i]) dsu.merge(p[i],j);
	}
	ans=0;
	for(i=l;i<=r;i++) ans+=dsu.find(i)==i;
	printf("%d\n",ans);
	return 0;
}
