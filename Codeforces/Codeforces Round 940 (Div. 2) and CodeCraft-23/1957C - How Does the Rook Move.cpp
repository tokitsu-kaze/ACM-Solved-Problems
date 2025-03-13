#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=1e9+7;
ll res[MAX];
int main()
{
	int T,n,k,i,cnt,x,y;
	ll ans;
	res[0]=1;
	res[1]=1;
	for(i=2;i<MAX;i++) res[i]=(res[i-1]+(2*i-2)*res[i-2])%mod;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		cnt=n;
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&x,&y);
			if(x==y) cnt--;
			else cnt-=2;
		}
		printf("%lld\n",res[cnt]);
	}
	return 0;
}
