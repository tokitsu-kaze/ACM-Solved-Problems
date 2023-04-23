#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t,n,i,j,loop,be;
	ll k,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		vector<ll> a,b(n);
		map<vector<ll>,int> pre;
		for(i=0;i<n;i++) scanf("%lld",&b[i]);
		a=b;
		pre[b]=0;
		loop=-1;
		for(j=1;j<=k;j++)
		{
			s=0;
			for(i=0;i<n;i++) s^=b[i];
			for(i=0;i<n;i++) b[i]=s^b[i];
			if(pre.count(b))
			{
				be=pre[b];
				loop=j-pre[b];
				break;
			}
			pre[b]=j;
		}
		if(loop==-1)
		{
			for(i=0;i<n;i++) printf("%lld%c",b[i]," \n"[i==n-1]);
			continue;
		}
		while(be>0)
		{
			be--;
			k--;
			s=0;
			for(i=0;i<n;i++) s^=a[i];
			for(i=0;i<n;i++) a[i]=s^a[i];
		}
		k%=loop;
		while(k>0)
		{
			k--;
			s=0;
			for(i=0;i<n;i++) s^=a[i];
			for(i=0;i<n;i++) a[i]=s^a[i];
		}
		for(i=0;i<n;i++) printf("%lld%c",a[i]," \n"[i==n-1]);
	}
}
