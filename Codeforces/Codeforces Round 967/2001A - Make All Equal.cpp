#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
int main()
{
	int t,n,i,x,cnt[105],mx;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		mx=0;
		for(i=1;i<=n;i++) mx=max(mx,cnt[i]);
		printf("%d\n",n-mx);
	}
	return 0;
}
