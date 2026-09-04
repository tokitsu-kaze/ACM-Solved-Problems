#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int n,i,x,cnt[105],ans;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	ans=0;
	for(i=1;i<=n;i++) ans=max(ans,cnt[i]);
	printf("%d\n",n-ans);
	return 0;
}
