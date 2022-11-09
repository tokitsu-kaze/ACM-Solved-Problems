#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i;
	ll a[111],x;
	while(~scanf("%d",&n))
	{
		deque<ll> q;
		deque<ll> ::iterator it;
		map<ll,int> mp;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			mp[a[i]]++;
		}
		sort(a,a+n);
		q.pb(a[n-1]);
		while(sz(q)!=n)
		{
			x=*q.begin();
			if(x%2==0&&mp[x/2])
			{
				q.push_front(x/2);
				mp[x/2]--;
			}
			x=q.back();
			if(x%3==0&&mp[x/3])
			{
				q.pb(x/3);
				mp[x/3]--;
			}
			x=q.back();
			if(mp[x*2])
			{
				q.pb(x*2);
				mp[x*2]--;
			}
			x=*q.begin();
			if(mp[x*3])
			{
				q.push_front(x*3);
				mp[x*3]--;
			}
	/*		for(it=q.begin();it!=q.end();it++) cout<<*it<<" ";
			puts("");*/
		}
		for(i=0;i<n;i++)
		{
			printf("%lld%c",*q.begin()," \n"[i==n-1]);
			q.pop_front();
		}
	}
	return 0;
}