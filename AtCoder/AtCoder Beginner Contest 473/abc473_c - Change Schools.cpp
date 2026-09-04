#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX];
int main()
{
	int n,k,i,x,mx,ans;
	scanf("%d%d",&n,&k);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	mx=0;
	for(i=1;i<=k;i++) mx=max(mx,cnt[i]);
	ans=0;
	for(i=1;i<=k;i++)
	{
		if(cnt[i]==mx || cnt[i]==mx-1) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
