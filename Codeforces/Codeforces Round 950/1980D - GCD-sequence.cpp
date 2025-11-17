#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],b[MAX],n;
int ck(int pos)
{
	if(pos<1||pos>n) return 0;
	int i,tot;
	tot=0;
	for(i=1;i<n;i++)
	{
		if(i==pos || i+1==pos)
		{
			if(i+1==pos && i+2<=n) b[++tot]=__gcd(a[i],a[i+2]);
			continue;
		}
		b[++tot]=__gcd(a[i],a[i+1]);
	}
//	printf("%d\n",pos);
//	for(i=1;i<=tot;i++) printf("%d%c",b[i]," \n"[i==tot]);
	for(i=2;i<=tot;i++)
	{
		if(b[i]<b[i-1]) return 0;
	}
	return 1;
}
int main()
{
	int T,i,ok,pos;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<n;i++) b[i]=__gcd(a[i],a[i+1]);
		ok=1;
		for(i=2;i<n;i++)
		{
			if(b[i]<b[i-1])
			{
				ok=0;
				pos=i;
			}
		}
		if(ok)
		{
			puts("YES");
			continue;
		}
		ok=0;
		for(i=-3;i<=3;i++)
		{
			if(ck(pos+i)) ok=1;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
