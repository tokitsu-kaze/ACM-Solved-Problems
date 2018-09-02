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
#include <ctime>
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
const int MAX=1e6+10;
const ll mod=1e9+7;
ll temp[37];
void init()
{
	ll i,j;
	for(i=1,j=33;i<=4294967296ULL;i*=2,j--)
	{
		temp[j]=i;
	//	cout<<j<<" "<<temp[j]<<endl;
	}
}
void change(ll x,ll *res)
{
	ll i;
	for(i=1;i<=33;i++)
	{
		if(temp[i]<=x)
		{
			res[i]=1;
			x-=temp[i];
		}
		else res[i]=0;
//		cout<<res[i];
	}
//	puts("");
}
ll debug(ll l,ll r)
{
	ll i,res[37],ans=l;
	change(l,res);
	for(i=l+1;i<=r;i++)
	{
//		change(i,res);
		ans&=i;
	}
	printf("%lld*\n",ans);
//	return ans;
}
int main()
{
	ll i,res[37],t,l,r,ans,now;
	init();
//	srand(time(0));
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
//		l=abs(rand())%2147483648ULL;
//		r=(l+abs(rand())%(2147483648ULL-l));
		change(l,res);
		ans=0;
		now=1;
		for(i=33;i>=1;i--)
		{
			if(res[i]==1)
			{
				if(l+now<=r);
				else ans+=temp[i];
			}
			else now+=temp[i];
	//		cout<<now<<endl;
		}
//		ll p=debug(l,r);
		printf("%lld\n",ans);
//		if(p!=ans) cout<<l<<" "<<r<<endl; 
	}
//	puts("YES");
	return 0;
}
/*
12000
23 39
2 3
2147483648 2147483648
4294967296 4294967296
*/