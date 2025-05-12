#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,x,cnt[4];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		if(cnt[3]>=3) printf("%d\n",n);
		else if(cnt[3]==2)
		{
			if(cnt[1]&1) printf("%d\n",n-cnt[3]);
			else printf("%d\n",n);
		}
		else
		{
			if(cnt[1]&1) printf("%d\n",cnt[1]+cnt[2]);
			else printf("%d\n",cnt[3]);
		}
	}
	return 0;
}
/*
sol:
https://discuss.codechef.com/t/asymeat-editorial/123435
*/
