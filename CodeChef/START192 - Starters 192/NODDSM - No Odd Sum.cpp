#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=(1<<22)+10;
int main()
{
	int T,n,i,x,cnt[3];
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
		if(cnt[1]&1) printf("%d\n",cnt[2]);
		else printf("%d\n",min(cnt[1]/2,cnt[2]));
	}
	return 0;
}
