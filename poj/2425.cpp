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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=1e9+7;
int sg[MAX];
vector<int> mp[MAX];
int dfs(int x)
{
	int i,j,flag[MAX];
	if(sg[x]!=-1) return sg[x];
	mem(flag,0);
	for(i=0;i<sz(mp[x]);i++)
	{
		dfs(mp[x][i]);
		flag[sg[mp[x][i]]]=1;
	}
	for(i=0;;i++)
	{
		if(!flag[i])
		{
			j=i;
			break;
		}
	}
	return sg[x]=j;
}
int a[MAX];
int main()
{
	int n,m,i,x,ans;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++) mp[i].clear();
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&x);
				mp[i].pb(x);
			}
		}
		mem(sg,-1);
		while(~scanf("%d",&m)&&m)
		{
			ans=0;
			while(m--)
			{
				scanf("%d",&x);
				dfs(x);
				ans^=sg[x];
			}
			ans?puts("WIN"):puts("LOSE");
		}
	}
	return 0;
}