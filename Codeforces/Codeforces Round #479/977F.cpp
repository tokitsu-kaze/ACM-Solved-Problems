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
vector<int> res[MAX];
int main()
{
	int n,i,j,x,tot,ans,pos,tmp;
	while(~scanf("%d",&n))
	{
		for(i=0;i<=MAX-10;i++) res[i].clear();
		tot=0;
		hash_map<int,int> mp;
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(!mp[x-1]&&!mp[x])
			{
				tot++;
				res[tot].pb(i);
				mp[x]=tot;
				if(sz(res[tot])>ans)
				{
					ans=sz(res[tot]);
					pos=tot;
				}
			}
			else
			{
				tmp=mp[x-1];
				if(sz(res[tmp])<sz(res[mp[x]])) continue;
				res[tmp].pb(i);
				mp[x]=tmp;
				if(sz(res[tmp])>ans)
				{
					ans=sz(res[tmp]);
					pos=tmp;
				}
				mp[x-1]=0;
			}
		}
		printf("%d\n",ans);
		for(i=0;i<ans;i++) printf("%d%c",res[pos][i]," \n"[i==ans-1]);
	}
	return 0;
}