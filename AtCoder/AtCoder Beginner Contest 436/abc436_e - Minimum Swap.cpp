#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],flag[MAX];
int main()
{
	int n,i,cnt,x;
	ll ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=0;
	for(i=1;i<=n;i++) flag[i]=0;
	for(i=1;i<=n;i++)
	{
		if(flag[i]) continue;
		cnt=0;
		x=i;
		while(!flag[x])
		{
			cnt++;
			flag[x]=1;
			x=a[x];
		}
		ans+=1LL*cnt*(cnt-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}
