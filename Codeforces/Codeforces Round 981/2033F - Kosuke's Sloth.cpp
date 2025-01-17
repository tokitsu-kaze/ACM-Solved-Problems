#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=1e9+7;
int main()
{
	int T,k,f1,f2,f3,cnt;
	ll n,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%d",&n,&k);
		if(k==1)
		{
			printf("%lld\n",n%mod);
			continue;
		}
		f1=f2=1;
		cnt=2;
		while(1)
		{
			f3=(f1+f2)%k;
			cnt++;
			if(f3==0) break;
			f1=f2;
			f2=f3;
		}
		printf("%lld\n",n%mod*cnt%mod);
	}
	return 0;
}
