#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],n,suf[MAX],d[MAX];
int cald(int x)
{
	int s;
	s=1;
	while(s<x) s<<=1;
	return s-x;
}
int cal(int x)
{
	int i,j,res,now,sum;
	res=INF;
	now=0;
	sum=0;
	for(i=1,j=1;i<=n-2;i++)
	{
		if(j<=i)
		{
			while(j<=i) j++;
			now=d[j];
		}
		else now-=d[i];
		while(j+1<=n && now+d[j+1]<=x) now+=d[++j];
		sum+=d[i];
		if(now<=x) res=min(res,cald(sum)+x-now+suf[j+1]);
	}
	return res;
}
int main()
{
	int T,i,s,ans,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		if(n==1)
		{
			puts("2");
			continue;
		}
		if(n==2)
		{
			if(a[1]!=a[2]) puts("1");
			else puts("2");
			continue;
		}
		for(i=1;i<=n;i++) d[i]=0;
		for(i=1;i<=n;i++) d[a[i]]++;
		suf[n+1]=1;
		now=0;
		for(i=n;i;i--)
		{
			now+=d[i];
			suf[i]=cald(now);
		}
		ans=INF;
		for(s=1;s<12*n;s<<=1) ans=min(ans,cal(s));
		printf("%d\n",ans);
	}
	return 0;
}
