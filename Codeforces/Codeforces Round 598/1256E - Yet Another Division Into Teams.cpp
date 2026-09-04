#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int v,id;}a[MAX];
ll dp[MAX];
int pre[MAX],col[MAX];
int main()
{
	int n,i,pos,tot;
	ll mn;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].id=i;
	}
	sort(a+1,a+1+n,[](node x,node y){
		return x.v<y.v;
	});
	mn=LLINF;
	memset(dp,0x3f,sizeof dp);
	memset(pre,0,sizeof pre);
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		if(i-3>=0)
		{
			if(-a[i-2].v+dp[i-3]<mn)
			{
				mn=-a[i-2].v+dp[i-3];
				pos=i-2;
			}
		}
		if(mn!=LLINF)
		{
			dp[i]=a[i].v+mn;
			pre[i]=pos;
		}
	}
	pos=n;
	tot=0;
	while(pos>0)
	{
		tot++;
		for(i=pre[pos];i<=pos;i++) col[a[i].id]=tot;
		pos=pre[pos]-1;
	}
	printf("%lld %d\n",dp[n],tot);
	for(i=1;i<=n;i++) printf("%d%c",col[i]," \n"[i==n]);
	return 0;
}
/*
dp[i]=a[i]+min{-a[j+1]+dp[j]}, j<=i-3
维护前缀min，顺便维护位置即可。
*/
