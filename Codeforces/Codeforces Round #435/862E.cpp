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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
ll b[MAX],j[MAX];
set<ll> s;
set<ll> ::iterator it;
int main()
{
	ll n,m,q,i,a,x,temp,temp1,temp2,l,r,ans;
	while(~scanf("%lld%lld%lld",&n,&m,&q))
	{
		a=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			if(i%2) a+=x;
			else a-=x;
		}
		temp=0;
		b[0]=0;
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&b[i]);
			if(i<=n)
			{
				if(i%2) temp+=b[i];
				else temp-=b[i];
				if(i==n) j[0]=temp;
			}
			else
			{
				temp-=b[i-n];
				temp*=-1;
				if(n%2) temp+=b[i];
				else temp-=b[i];
				j[i-n]=temp;
			}
		}
		for(i=0;i<=m-n;i++)
		{
			s.insert(j[i]);
		}
		s.insert(LLINF);
		s.insert(-LLINF);
		it=s.upper_bound(a);
		it--;
		ans=min(abs(a-(*s.lower_bound(a))),abs(a-(*it)));
		printf("%lld\n",ans);
		while(q--)
		{
			scanf("%lld%lld%lld",&l,&r,&x);
			if((r-l+1)%2)
			{
				if(l%2) a+=x;
				else a-=x;
			}
			it=s.upper_bound(a);
			it--;
			ans=min(abs(a-(*s.lower_bound(a))),abs(a-(*it)));
			printf("%lld\n",abs(ans));
		}
	}
	return 0;
}