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
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int to,w;
	node(){}
	node(int a,int b)
	{
		to=a;
		w=b;
	}
};
int path[2*MAX],deep[2*MAX],first[MAX],dis[MAX],flag[MAX],tot;
int dp[2*MAX][28];
vector<node> mp[MAX];
int deepmark[MAX];
void dfs(int x,int h)
{
	int i;
	flag[x]=1;
	path[++tot]=x;
	first[x]=tot;
	deep[tot]=h;
	deepmark[x]=h;
	for(i=0;i<mp[x].size();i++)
	{
		int to=mp[x][i].to;
		if(!flag[to])
		{
			dis[to]=dis[x]+mp[x][i].w;
			dfs(to,h+1);
			path[++tot]=x;
			deep[tot]=h;
		}
	}
}
void ST(int n)
{
	int i,j,x,y;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=i;
	}
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			x=dp[i][j-1];
			y=dp[i+(1<<(j-1))][j-1];
			dp[i][j]=deep[x]<deep[y]?x:y;
		}
	}
}
int query(int l,int r)
{
	int len,x,y;
	len=(int)log2(r-l+1); 
	x=dp[l][len];
	y=dp[r-(1<<len)+1][len];
	return deep[x]<deep[y]?x:y;
}
int LCA(int x,int y)
{
	int l,r,pos;
	l=first[x];
	r=first[y];
	if(l>r) swap(l,r);
	pos=query(l,r);
	return path[pos];
}
int getdist(int a,int b)
{
	return dis[a]+dis[b]-2*dis[LCA(a,b)];
}
int solve(int a,int b,int c)
{
	return (a+b-c)/2;
}
int main()
{
	int t,i,n,a,b,c,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			dis[i]=0;
			flag[i]=0;
			deepmark[i]=0;
		}
		tot=0;
		for(i=2;i<=n;i++)
		{
			scanf("%d",&a);
			mp[a].pb(node(i,1));
			mp[i].pb(node(a,1));
		}
		dfs(1,1);
		ST(2*n-1);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			int lab,lbc,lac;
			lab=getdist(a,b);
			lbc=getdist(b,c);
			lac=getdist(a,c);
			printf("%d\n",1+max(solve(lab,lbc,lac),max(solve(lab,lac,lbc),solve(lac,lbc,lab))));
		}
	}
	return 0;
}