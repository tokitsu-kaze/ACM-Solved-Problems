#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],b[MAX],c[MAX],x[MAX],n,m;
int get_mex(int a,int b)
{
	if(a>b) swap(a,b);
	if(a>0) return 0;
	if(b!=1) return 1;
	return 2;
}
int check(int posc0,int cv)
{
	int i,j,nowg,f,cnt[5],tmpcnt[5];
	c[posc0]=cv;
	nowg=0;
	f=0;
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++) b[i]=a[i];
	for(i=1;i<=m;i++)
	{
		if(c[i]==2) nowg=__gcd(nowg,x[i]);
		else
		{
			if(f)
			{
				if(nowg>0) return 1;
				memset(tmpcnt,0,sizeof tmpcnt);
				for(j=0;j<=2;j++) tmpcnt[get_mex(j,x[i])]+=cnt[j];
				for(j=0;j<=2;j++) cnt[j]=tmpcnt[j];
			}
			else
			{
				for(j=1;j<=n;j++)
				{
					b[j]=__gcd(b[j],nowg);
					b[j]=get_mex(b[j],x[i]);
					cnt[b[j]]++;
				}
				nowg=0;
				f=1;
			}
			for(j=0;j<=2;j++)
			{
				if(cnt[j]==n) return 1;
			}
		}
	}
	if(!f)
	{
		for(i=1;i<=n;i++) b[i]=__gcd(b[i],nowg);
		for(i=2;i<=n;i++)
		{
			if(b[i]!=b[1]) return 0;
		}
		return 1;
	}
	else
	{
		map<int,int> mp;
		for(j=0;j<=2;j++) mp[__gcd(j,nowg)]+=cnt[j];
		for(auto &it:mp)
		{
			if(it.second==n) return 1;
		}
		return 0;
	}
}
int main()
{
	int T,i,cntc0,posc0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		cntc0=0;
		posc0=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&c[i],&x[i]);
			assert(x[i]>=1);
			if(c[i]==0)
			{
				cntc0++;
				posc0=i;
			}
		}
		if(cntc0>1)
		{
			puts("Yes");
			continue;
		}
		if(check(posc0,1) || check(posc0,2)) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
用了gcd，只会变成 1 或者 > 1。
再用 mex，由于 xi>=1，会变成 0。
所以 ci=0 的个数 >1 一定 yes。
*/
