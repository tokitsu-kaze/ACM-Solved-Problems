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
const int MAX=1e5+10;
const ll mod=1e9+7;
int mp[512][512],ans[512][512];
int pre[500*500+10],cnt[500*500+10];
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		pre[i]=i;
		cnt[i]=1;
	}
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(int a,int b)
{
	int ra,rb;
	ra=find(a);
	rb=find(b);
	if(ra!=rb)
	{
		pre[rb]=ra;
		cnt[ra]+=cnt[rb];
		cnt[rb]=0;
	}
}
int n,m;
int dir[8][2]={0,1,1,0,0,-1,-1,0,1,1,1,-1,-1,1,-1,-1};
int check(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return 0;
	return 1;
}
int main()
{
	int i,j,k,x,y,now,t;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		init(n*m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				t=mp[i][j];
				for(k=0;k<8;k++)
				{
					x=i;
					y=j;
					x+=dir[k][0];
					y+=dir[k][1];
					if(check(x,y))
					{
						if(mp[x][y]<t)
						{
							t=mp[x][y];
							now=m*(x-1)+y;
						}
					}
				}
				if(t<mp[i][j]) merge(now,m*(i-1)+j);
	//			cout<<i<<" "<<j<<" "<<find(m*(i-1)+j)<<endl;
	//			cout<<t<<endl;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(find(m*(i-1)+j)==m*(i-1)+j) printf("%d ",cnt[find(m*(i-1)+j)]);
				else printf("0 ");
			}
			puts("");
		}
	}
	return 0;
}