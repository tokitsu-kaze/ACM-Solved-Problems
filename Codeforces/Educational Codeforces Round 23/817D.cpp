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
const int MAX=1e6+10;
const ll mod=1e6;
int v[MAX],maxx[MAX][24],minn[MAX][24];
ll ans;
int pmax(int a,int b){return v[a]>v[b]?a:b;}
int pmin(int a,int b){return v[a]<v[b]?a:b;}
void RMQ(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		maxx[i][0]=minn[i][0]=i;
	}
	for(j=1;1<<(j-1)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			int t=1<<(j-1);
			maxx[i][j]=pmax(maxx[i][j-1],maxx[i+t][j-1]);
			minn[i][j]=pmin(minn[i][j-1],minn[i+t][j-1]);
		}
	}
}
int query(int l,int r,int flag)
{
	int j=(int)(log10(r-l+1)/log10(2))+1;
	int i=r-(1<<(j-1))+1;
	if(flag==1) return pmax(maxx[l][j-1],maxx[i][j-1]);
	else if(flag==-1) return pmin(minn[l][j-1],minn[i][j-1]);
} 
void dfs(int l,int r,int flag)
{
	if(l>r) return;
	int mid=query(l,r,flag);
	ans+=(ll)flag*v[mid]*(mid-l+1)*(r-mid+1);
	dfs(l,mid-1,flag);
	dfs(mid+1,r,flag);
}
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		RMQ(n);
		ans=0;
		dfs(1,n,1);
		dfs(1,n,-1);
		printf("%lld\n",ans);
	}
	return 0;
}