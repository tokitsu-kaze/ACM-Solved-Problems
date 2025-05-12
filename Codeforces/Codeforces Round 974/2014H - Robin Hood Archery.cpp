#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int sum[MAX];
ll ha[MAX];
mt19937_64 rd(time(0));
int main()
{
	int T,n,q,i,l,r,x;
	memset(ha,0,sizeof ha);
	for(i=1;i<=MAX-10;i++) ha[i]=rd();
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		sum[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			sum[i]=ha[x]^sum[i-1];
		}
		while(q--)
		{
			scanf("%d%d",&l,&r);
			if(((r-l+1)&1) || (sum[r]^sum[l-1])) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}
