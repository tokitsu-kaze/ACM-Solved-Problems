////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-28 15:48:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6053
////Problem Title: 
////Run result: Accept
////Run time:780MS
////Run memory:4884KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll a[MAX],prime[MAX],p[MAX],mobius[MAX],flag[MAX];
void init()
{
	ll i,j,cnt;
	mem(prime,0);
	mem(mobius,0);
	cnt=0;
	for(i=2;i<=MAX;i++)
	{
		if(!prime[i])
		{
			p[cnt++]=i;
			mobius[i]=-1;
			for(j=i+i;j<=MAX;j+=i)
			{
				prime[j]++;
			}
		}
	}
	mobius[1]=1;
	for(i=2;2*i<=MAX;i++)
	{
		for(j=0;j<cnt&&p[j]*i<MAX;j++)
		{
			if(i%p[j]==0)
			{
				mobius[p[j]*i]=0;
				break;
			}
			mobius[p[j]*i]=-mobius[i];
		}
	}
}
ll pow2(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	ll t,n,i,j,minn,maxx,cas=1;
	ll ans;
	init();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		mem(flag,0);
		minn=INF;
		maxx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			minn=min(minn,a[i]);
			maxx=max(maxx,a[i]);
			flag[a[i]]++;
		}
		for(i=maxx-1;i>=2;i--)
		{
			flag[i]+=flag[i+1];
		}
		ans=0;
		for(i=2;i<=minn;i++)
		{
			if(!mobius[i]) continue;
			ll now=flag[i];
			ll temp=1;
			for(j=2;j*i<=maxx;j++)
			{
				if(now!=flag[j*i])
				{
					temp*=pow2(j-1,now-flag[j*i]);
					temp%=mod;
					now=flag[j*i];
				}
				if((j+1)*i>maxx)
				{
					temp*=pow2(j,flag[j*i]);
					temp%=mod;
				}
			}	
			ans+=(-mobius[i])*temp;
			ans%=mod;
		}
		printf("Case #%lld: %lld\n",cas++,(ans+mod)%mod);
	}	
	return 0;	
}
/*
1000
4
4 4 4 4
4
2 3 3 16
4
3 3 3 16
4
2 2 2 2
2
6 6
1
6
1
100
4
100000 100000 100000 100000
*/