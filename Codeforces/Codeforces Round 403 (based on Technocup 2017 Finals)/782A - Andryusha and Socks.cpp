#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int cnt[MAX];
int main()
{
	int n,i,x,ans,now;
	scanf("%d",&n);
	for(i=1;i<=n;i++) cnt[i]=0;
	now=ans=0;
	for(i=1;i<=2*n;i++)
	{
		scanf("%d",&x);
		if(cnt[x])
		{
			cnt[x]--;
			now--;
		}
		else
		{
			cnt[x]++;
			now++;
		}
		ans=max(ans,now);
	}
	printf("%d\n",ans);
	return 0;
}
