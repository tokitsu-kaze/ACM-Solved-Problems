#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX],b[MAX];
int la[MAX],ra[MAX],lb[MAX],rb[MAX],st[MAX];
void workr(int *x,int m,int *res)
{
	int i,top;
	top=0;
	for(i=1;i<=m;i++)
	{
		while(top && x[st[top-1]]>x[i])
		{
			res[st[top-1]]=i;
			top--;
		}
		st[top++]=i;
	}
	while(top>0)
	{
		res[st[top-1]]=m+1;
		top--;
	}
}
void workl(int *x,int m,int *res)
{
	int i,top;
	top=0;
	for(i=m;i;i--)
	{
		while(top && x[st[top-1]]>x[i])
		{
			res[st[top-1]]=i;
			top--;
		}
		st[top++]=i;
	}
	while(top>0)
	{
		res[st[top-1]]=0;
		top--;
	}
}
int ck(int x)
{
	int i;
	workl(a,x,la);
	workr(a,x,ra);
	workl(b,x,lb);
	workr(b,x,rb);
	for(i=1;i<=x;i++)
	{
		if(la[i]!=lb[i] || ra[i]!=rb[i]) return 0;
	}
	return 1;
}
int main()
{
	int n,i,l,r,mid;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		l=1;
		r=n;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}
