#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int l[MAX],sum[MAX];
const int delta=1e5;
int main()
{
	int n,i,ans,now;
	scanf("%d",&n);
	sum[delta]=0;
	memset(l,0,sizeof l);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=(a[i]==0?-1:1);
		sum[i]+=sum[i-1];
		now=sum[i]+delta;
		if(sum[i]==0) ans=i;
		else if(!l[now]) l[now]=i;
		else ans=max(ans,i-l[now]);
	}
	printf("%d\n",ans);
	return 0;
}
