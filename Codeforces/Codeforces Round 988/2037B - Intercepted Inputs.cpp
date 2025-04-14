#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX];
int main()
{
	int T,n,i,x,ra,rb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]++;
		}
		ra=rb=-1;
		for(i=1;i*i<=n-2;i++)
		{
			if((n-2)%i) continue;
			ra=i;
			rb=(n-2)/i;
			cnt[ra]--;
			cnt[rb]--;
			if(cnt[ra]>=0 && cnt[rb]>=0) break;
			cnt[ra]++;
			cnt[rb]++;
		}
		printf("%d %d\n",ra,rb);
	}
	return 0;
}
