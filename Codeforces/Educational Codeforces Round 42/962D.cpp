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
const double eps=1e-8;
const int MAX=2e5+10;
const ll mod=1e9+7;
ll a[MAX];
int main()
{
	ll n,i,pos,tmp,pre;
	while(~scanf("%lld",&n))
	{
		map<ll,set<ll> > mp;
		multiset<ll> s;
		multiset<ll> ::iterator it,del;
		set<ll> ::iterator it1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			mp[a[i]].insert(i);
			s.insert(a[i]);
		}
		vector<ll> res;
		while(sz(s))
		{
			it=s.begin();
			tmp=*it;
			del=it;
			it++;
			s.erase(del);
			if(s.count(tmp)==0) mp[tmp].erase(mp[tmp].begin());
			else
			{
				s.erase(it);
				it1=mp[tmp].begin();
				pre=*it1;
				it1++;
				pos=*it1;
				a[pre]=-1;
				a[pos]*=2;
				
				s.insert(a[pos]);
				mp[tmp].erase(pre);
				mp[tmp].erase(pos);
				mp[tmp*2].insert(pos);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]==-1) continue;
			res.pb(a[i]);
		}
		printf("%d\n",sz(res));
		for(i=0;i<sz(res);i++) printf("%lld%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}