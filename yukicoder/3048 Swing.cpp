#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	ll x,n,now,i,target;
	scanf("%lld%lld",&x,&n);
	if(x==0)
	{
		x-=n/2;
		now=n/2*2;
	}
	else
	{
		if(x<0) target=-x;
		else target=x;
		now=sqrt(2*target);
		while((1+now)*now/2>=target) now--;
		while((1+now)*now/2<=target) now++;
		now=min(n,now-1);
		if(x>=0) x-=(1+now)*now/2;
		else x+=(1+now)*now/2;
		if(x<=0 && now<n)
		{
			now++;
			x+=now;
		}
		x+=(n-now)/2;
	}
	for(i=now+(n-now)/2*2+1;i<=n;i++)
	{
		if(x<=0) x+=i;
		else x-=i;
	}
	printf("%lld\n",x);
	return 0;
}

