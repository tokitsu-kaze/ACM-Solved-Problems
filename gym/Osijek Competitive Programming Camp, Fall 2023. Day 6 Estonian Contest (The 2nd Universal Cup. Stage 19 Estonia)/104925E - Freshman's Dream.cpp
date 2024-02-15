#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e6+10;
const ll mod=1e9+7;
mt19937 rd(time(0));
ll n;
int ck(ll a,ll b)
{
	return (a+b)==(a^(n+b));
}
int main()
{
	int t;
	ll a,b,bt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if(n&1)
		{
			puts("-1");
			continue;
		}
		bt=0;
		while((1LL<<bt)<n) bt++;
		if(ck(n/2,n/2)) printf("%lld %lld\n",a=n/2,b=n/2);
		else if(ck(n/2,1)) printf("%lld %lld\n",a=n/2,b=1);
		else if(ck(n/2,n-1)) printf("%lld %lld\n",a=n/2,b=n-1);
		else if(ck(n/2,(n-1)^n)) printf("%lld %lld\n",a=n/2,b=(n-1)^n);
		else if(ck(n/2,((1LL<<bt)-1)^n)) printf("%lld %lld\n",a=n/2,b=((1LL<<bt)-1)^n);
		else
		{
			printf("%lld\n",n);
			assert(0);
		}
	//	printf("%lld %lld %d\n",a+b,a^(n+b),(a+b)==(a^(n+b)));
	/*	for(a=1;a<=40;a++)
		{
			for(b=1;b<=40;b++)
			{
				if((a+b)==(a^(n+b)))
				{
					printf("%lld %lld %lld\n",a,b,b^n);
				}
			}
		}*/
	}
	return 0;
}
/*
(a+b)=a^(n+b)

*/
