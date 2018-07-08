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
const int MAX=2e3+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int link[MAX],used[MAX];
int res[MAX],now[MAX];
int dfs(int x)
{
	int i,to;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i];
		if(!used[to])
		{
			used[to]=1;
			if(link[to]==-1||dfs(link[to]))
			{
				link[to]=x;
				return 1;
			}
		}
	}
	return 0;
}
int hungary(int n)
{
	mem(link,-1);
	int i,res=0;
	for(i=1;i<=n;i++)
	{
		mem(used,0);
		if(dfs(i)) res++;
	}
	return res;
}
int main()
{
	int n,i,j,x;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			for(j=1;j<=n;j++)
			{
				scanf("%d",&x);
				if(x) mp[i].pb(j);
			}
		}
		if(hungary(n)==n)
		{
			for(i=1;i<=n;i++) res[i]=link[i],now[i]=i;
			for(i=1;i<=n;i++)
			{
				if(now[i]!=res[i])
				{
					for(j=1;j<=n;j++)
					{
						if(now[j]==res[i])
						{
							printf("R %d %d\n",i,j);
							swap(now[i],now[j]);
							break;
						}
					}
				}
			}
		}
		else puts("-1");
	}
	return 0;
}
/*
4123
4
0 0 0 1
1 0 0 0
0 1 0 0
0 0 1 0

*/