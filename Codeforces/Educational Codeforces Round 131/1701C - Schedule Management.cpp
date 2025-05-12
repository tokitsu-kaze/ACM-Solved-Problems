#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n,m,a[MAX],now[MAX];
int ck(int x)
{
	int i,cnt;
	cnt=0;
	for(i=1;i<=n;i++) now[i]=0;
	for(i=1;i<=m;i++)
	{
		if(now[a[i]]<x) now[a[i]]++;
		else cnt++;
	}
	for(i=1;i<=n;i++)
	{
		while(cnt>0 && now[i]+2<=x)
		{
			cnt--;
			now[i]+=2;
		}
	}
	return cnt==0;
}
int main()
{
	int T,i,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++) scanf("%d",&a[i]);
		l=0;
		r=2*m;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
