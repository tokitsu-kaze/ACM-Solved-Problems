#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll n;
ll check(ll r,ll k)
{
	ll res=0,temp=k;
	while(r--)
	{
		if(temp>n) return LLINF;
		res+=temp;
		if(res>n) return LLINF;
		temp*=k;
	}
	return res;
}
int main()
{
	ll i,ans1,ans2,now;
	while(~scanf("%lld",&n))
	{
		ll l,r,mid;
		now=LLINF;
		for(i=1;i<=40;i++)
		{
			l=1;
			r=(ll)pow(n,1.0/i)+1;
			while(l<r)
			{
				mid=(l+r)>>1;
				ll temp=check(i,mid);
				if((temp==n||temp+1==n)&&mid*i<now) now=mid*i,ans1=i,ans2=mid;
				else if(temp<n-1) l=mid+1;
				else r=mid;
			}
		}
		printf("%lld %lld\n",ans1,ans2);
	}
	return 0;
}