#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e3+10;
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
	bool merge(int x,int y,bool dir=false)
	{
		x=find(x);
		y=find(y);
		if(x==y) return 0;
		if(!dir && sz[x]>sz[y]) swap(x,y);
		pre[x]=y; // x -> y
		sz[y]+=sz[x];
		return 1;
	}
}dsu;
char a[MAX],b[MAX],c[MAX];
int main()
{
	int T,n,m,k,i,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s%s",a,b,c);
		n=strlen(a);
		m=strlen(b);
		k=strlen(c);
		if(n!=m)
		{
			puts("NO");
			continue;
		}
		if(n==m && n!=k)
		{
			puts("YES");
			continue;
		}
		dsu.init(256);
		for(i=0;i<n;i++) dsu.merge(a[i],b[i]);
		ok=0;
		for(i=0;i<m;i++)
		{
			if(dsu.find(b[i])!=dsu.find(c[i])) ok=1;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
