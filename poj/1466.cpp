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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e3+10;
const ll mod=1e9+7;
vector<int> mp[MAX];
int link[MAX],used[MAX];
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
	int n,m,a,b,i,t;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++) mp[i].clear();
		for(i=1;i<=n;i++)
		{
			scanf("%d: (%d)",&a,&m);
			a++;
	//		cout<<m<<endl;
			while(m--)
			{
				scanf("%d",&b);
				b++;
				mp[a].pb(b);
			}
		}
		printf("%d\n",n-hungary(n)/2);
	}
	return 0;
}