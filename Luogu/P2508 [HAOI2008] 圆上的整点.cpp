#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=200+10;
int main()
{
	int r,i,cnt;
	ll ans;
	scanf("%d",&r);
	ans=1;
	for(i=2;i*i<=r;i++)
	{
		if(r%i) continue;
		cnt=0;
		while(r%i==0)
		{
			r/=i;
			cnt++;
		}
		if(i%4==1) ans*=(cnt*2+1);
	}
	if(r>1 && r%4==1) ans*=3;
	ans*=4;
	printf("%lld\n",ans);
	return 0;
}
