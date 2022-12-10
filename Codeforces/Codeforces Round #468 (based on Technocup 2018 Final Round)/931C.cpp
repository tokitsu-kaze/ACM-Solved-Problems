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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,x,ans;
	while(~scanf("%d",&n))
	{
		vector<int> res;
		map<int,int> mp;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(!mp[x]) res.pb(x);
			mp[x]++;
		}
		sort(all(res));
		ans=n;
		if(sz(res)==2)
		{
			if(res[1]-res[0]==2)
			{
				res.pb(res[0]+1);
				int t=min(mp[res[0]],mp[res[1]]);
				while(t--)
				{
					mp[res[0]]--;
					mp[res[1]]--;
					mp[res[0]+1]+=2;
					ans-=2;
				}
			}
		}
		else if(sz(res)==3)
		{
			if((n-min(mp[res[0]],mp[res[2]])*2<n-mp[res[1]]/2*2))
			{
				int t=min(mp[res[0]],mp[res[2]]);
				while(t--)
				{
					mp[res[0]]--;
					mp[res[2]]--;
					mp[res[1]]+=2;
					ans-=2;
				}
			}
			else
			{
				while(mp[res[1]]>1)
				{
					mp[res[1]]-=2;
					mp[res[0]]++;
					mp[res[2]]++;
					ans-=2;
				}
			}
		}
		printf("%d\n",ans);
		for(i=0;i<sz(res);i++)
		{
			while(mp[res[i]]--) printf("%d ",res[i]);
		}
		puts("");
	}
	return 0;
}