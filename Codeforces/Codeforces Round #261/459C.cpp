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
const int MAX=3e5+10;
const ll mod=1e9+7;
ll n,k,d;
int ans[1011][1011],tot,res[1011];
void dfs(int x)
{
	int i;
	if(x==d+1)
	{
		tot++;
		for(i=1;i<=d;i++) ans[tot][i]=res[i];
		return;
	}
	for(i=1;i<=min(n,k);i++)
	{
		res[x]=i;
		if(tot>n) return;
		dfs(x+1);
	}
}
int main()
{
	ll i,j,tmp;
	while(~scanf("%lld%lld%lld",&n,&k,&d))
	{
		tmp=1;
		for(i=1;i<=d;i++)
		{
			tmp*=k;
			if(tmp>=n) break;
		}
		if(tmp<n)
		{
			puts("-1");
			continue;
		}
		dfs(1);
		for(i=1;i<=d;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d%c",ans[j][i]," \n"[j==n]);
			}
		}
	}
	return 0;
}