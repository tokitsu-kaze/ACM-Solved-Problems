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
const int MAX=2e3+10;
const ll mod=1e6;
ll n,k,p,a[MAX],b[MAX];
bool flag[MAX];
bool cal(ll v)
{
	ll i,j,cnt=0;
	mem(flag,0);
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			if(flag[j]) continue;
			if(abs(a[j]-b[i])+abs(b[i]-p)<=v)
			{
				cnt++;
				flag[j]=1;
				break;
			}
		}
	}
	return cnt==n;
}
int main()
{
	ll i,ans;
	while(~scanf("%lld%lld%lld",&n,&k,&p))
	{
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<k;i++)
		{
			scanf("%lld",&b[i]);
		}
		sort(a,a+n);
		sort(b,b+k);
		ll l,r,mid,res;
		l=0;
		r=2e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(cal(mid)) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",r);
	}
	return 0;
}