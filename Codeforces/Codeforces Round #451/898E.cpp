#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
hash_map<int,int> mp;
int sq[MAX],tot;
void init()
{
	mp.clear();
	tot=0;
	for(int i=0;i<=((int)sqrt(1e9))+1;i++)
	{
		sq[tot++]=i*i;
		mp[sq[tot-1]]=1;
	}
}
int main()
{
	init();
	int n,i,x;
	ll ans;
	while(~scanf("%d",&n))
	{
		vector<int> v1,v2;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(mp[x]) v1.pb(x);
			else v2.pb(x);
		}
		sort(all(v1));
		sort(all(v2));
		ans=0;
		if(sz(v1)==sz(v2));
		else if(sz(v1)>sz(v2))
		{
			vector<int> res;
			for(i=0;i<sz(v1);i++)
			{
				if(v1[i]==0) res.pb(2);
				else res.pb(1);
			}
			sort(all(res));
			for(i=0;i<sz(v1)-n/2;i++)
			{
				ans+=res[i];
			}
		}
		else
		{
			vector<int> res;
			for(i=0;i<sz(v2);i++)
			{
				int p1,p2;
				p1=p2=lower_bound(sq,sq+tot,v2[i])-sq;
				p1--;
				res.pb(min(v2[i]-sq[p1],sq[p2]-v2[i]));
			}
			sort(all(res));
			for(i=0;i<(int)sz(v2)-n/2;i++) ans+=res[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}