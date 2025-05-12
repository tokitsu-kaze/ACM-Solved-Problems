#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],n,k;
int ck()
{
	int i,sum,cnt,pos,pre;
	sum=0;
	pre=0;
	pos=-1;
	for(i=1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>=0)
		{
			pre=sum;
			pos=i;
			break;
		}
	}
	if(pos==-1) return 0;
	sum=0;
	for(i=pos+1;i<=n;i++)
	{
		sum+=a[i];
		if(sum>=0) return 1;
	}
	if(pre>0)
	{
		sum=0;
		for(i=pos+2;i<=n;i++)
		{
			sum+=a[i];
			if(sum>=0) return 1;
		}
	}
	sum=0;
	for(i=n;i>pos;i--)
	{
		sum+=a[i];
		if(sum>=0) return 1;
	}
	return 0;
}
int main()
{
	int T,i,x,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x<=k) a[i]=1;
			else a[i]=-1;
		}
		ok=0;
		ok|=ck();
		reverse(a+1,a+1+n);
		ok|=ck();
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}

