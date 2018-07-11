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
int a[MAX];
int main()
{
	int n,k,i,j,x,flag;
	ll s;
	while(~scanf("%d",&k))
	{
		map<ll,map<int,vector<int> > > mp;
		flag=0;
		PII ans[2];
		for(j=1;j<=k;j++)
		{
			scanf("%d",&n);
			s=0;
			for(i=1;i<=n;i++)
			{
				scanf("%d",&a[i]);
				s+=a[i];
			}
			map<ll,int> tag;
			for(i=1;i<=n;i++)
			{
				mp[s-a[i]][j].pb(i);
				if(flag) continue;
				if(tag.count(s-a[i])) continue;
				tag[s-a[i]]=1;
				for(auto it:mp[s-a[i]])
				{
					if(it.fi!=j)
					{
						flag=1;
						ans[0]=MP(j,i);
						ans[1]=MP(it.fi,it.se[0]);
						break;
					}
				}
			}
		}
		if(!flag)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(i=0;i<2;i++) printf("%d %d\n",ans[i].fi,ans[i].se);
	}
	return 0;
}