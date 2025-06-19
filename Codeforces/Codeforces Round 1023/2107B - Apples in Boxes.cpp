#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int a[MAX];
int main()
{
	int T,n,k,i,mx,mn,mxcnt;
	ll sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		sum=0;
		mx=0;
		mn=1e9;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
		}
		if(mx-mn<=k)
		{
			if(sum&1) puts("Tom");
			else puts("Jerry");
			continue;
		}
		mxcnt=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==mx) mxcnt++;
		}
		if(mxcnt==1 && mx-1-mn<=k)
		{
			if(sum&1) puts("Tom");
			else puts("Jerry");
		}
		else puts("Jerry");
	}
	return 0;
}
