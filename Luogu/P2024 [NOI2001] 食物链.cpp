#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int pre[MAX];
int rel[MAX];
int ans;
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		pre[i]=i;
	}
}
int find(int x)
{
	int temp;
	if(pre[x]!=x)
	{
		temp=pre[x];
		pre[x]=find(pre[x]);
		rel[x]=(rel[x]+rel[temp])%3;
	}
	return pre[x];
}
void merge(int a,int b,int d)
{
	int ta,tb;
	ta=find(a);
	tb=find(b);
	if(ta==tb)
	{
		if((rel[a]-rel[b]+3)%3!=d-1) ans++;
	}
	else
	{
		pre[ta]=tb;
		rel[ta]=(rel[b]-rel[a]+d-1+3)%3;
	}
}
int main()
{
	int n,m,d,x,y;
	scanf("%d%d",&n,&m);
	init(n);
	memset(rel,0,sizeof rel);
	ans=0;
	while(m--)
	{
		scanf("%d%d%d",&d,&x,&y);
		if(d==2&&x==y) ans++;
		else if(x>n||y>n) ans++;
		else merge(x,y,d);
	}
	printf("%d\n",ans);
	return 0;
}
