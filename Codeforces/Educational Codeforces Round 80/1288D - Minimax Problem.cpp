#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int n,m,a[MAX][9],x,y,id[(1<<8)+10];
int ck(int mn)
{
	int i,j,now;
	memset(id,0,sizeof id);
	for(i=1;i<=n;i++)
	{
		now=0;
		for(j=1;j<=m;j++)
		{
			if(a[i][j]>=mn) now|=(1<<(j-1));
		}
		id[now]=i;
	}
	for(i=0;i<(1<<m);i++)
	{
		for(j=0;j<(1<<m);j++)
		{
			if(id[i]==0 || id[j]==0) continue;
			if(__builtin_popcount(i|j)<m) continue;
			x=id[i];
			y=id[j];
			return 1;
		}
	}
	return 0;
}
int main()
{
	int i,j,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	l=0;
	r=1e9;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	ck(l);
	printf("%d %d\n",x,y);
	return 0;
}
/*
二分答案。
知道答案后，把每行符合答案的位置状压一下。
然后枚举(2^8)^2，暴力一下。
*/
