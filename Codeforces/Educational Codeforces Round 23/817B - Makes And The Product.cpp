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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=3e5+10;
const ll mod=10000;
set<ll> s;
set<ll> ::iterator it;
map<ll,ll> m;
int main()
{
	ll n,a,i,x,y,z,ans;
	while(~scanf("%lld",&n))
	{
		s.clear();
		m.clear();
		while(n--)
		{
			scanf("%lld",&a);
			s.insert(a);
			m[a]++;
		}
		x=y=z=0;
		for(it=s.begin(),i=1;i<=3&&it!=s.end();i++,it++)
		{
			if(!x) x=m[*it];
			else if(!y) y=m[*it];
			else if(!z) z=m[*it];
			if(x+y+z>=3) break;
		}
		if(!y)
		{
			ans=x*(x-1)*(x-2)/3/2;
		}
		else if(!z)
		{
			if(x==1) ans=y*(y-1)/2;
			else ans=y;
		}
		else
		{
			ans=z;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 