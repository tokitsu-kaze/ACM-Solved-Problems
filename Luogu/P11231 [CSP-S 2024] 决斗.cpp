#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int cnt[MAX];
int main()
{
	int n,i,x,ans;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	ans=0;
	for(i=1;i<MAX;i++) ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}
