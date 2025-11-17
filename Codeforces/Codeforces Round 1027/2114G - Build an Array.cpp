#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int lowbit(int x){return x&-x;}
ll pre[MAX],suf[MAX];
int a[MAX],bs[MAX];
int main()
{
	int T,n,k,i,ok,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			bs[i]=a[i]/lowbit(a[i]);
		}
		pre[0]=0;
		for(i=1;i<=n;i++)
		{
			if(i<n && bs[i]==bs[i+1]&& a[i]>a[i+1]) now=(a[i]-a[i+1]*2)/bs[i]+1;
			else now=a[i]/bs[i];
			pre[i]=pre[i-1]+now;
		}
		suf[n+1]=0;
		for(i=n;i;i--)
		{
			if(i>1 && bs[i]==bs[i-1] && a[i]>a[i-1]) now=(a[i]-a[i-1]*2)/bs[i]+1;
			else now=a[i]/bs[i];
			suf[i]=suf[i+1]+now;
		}
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(pre[i-1]+suf[i+1]+a[i]/bs[i]>=k) ok=1;
//			printf("%d %d\n",i,pre[i-1]+suf[i+1]+a[i]/bs[i]);
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}

