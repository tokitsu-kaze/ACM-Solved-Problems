////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-12-09 22:43:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2888
////Problem Title: 
////Run result: Accept
////Run time:4118MS
////Run memory:30784KB
//////////////////System Comment End//////////////////
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
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=2e6+10;
const ll mod=1e9+7;
int v[302][302];
int maxx[302][302][9][9];
void RMQ(int n,int m)
{
	int i,j,ii,jj;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			maxx[i][j][0][0]=v[i][j];
		}
	}
	for(ii=0;(1<<ii)<=n;ii++)
	{
		for(jj=0;(1<<jj)<=m;jj++)
		{
			if(ii+jj)
			{
				for(i=1;i+(1<<ii)-1<=n;i++)
				{
					for(j=1;j+(1<<jj)-1<=m;j++)
					{
						if(ii) maxx[i][j][ii][jj]=max(maxx[i][j][ii-1][jj],maxx[i+(1<<(ii-1))][j][ii-1][jj]);
						else maxx[i][j][ii][jj]=max(maxx[i][j][ii][jj-1],maxx[i][j+(1<<(jj-1))][ii][jj-1]);
					}
				}
			}
		}
	}
}
int query(int x1,int y1,int x2,int y2)
{
	int k1=0;
	while((1<<(k1+1))<=x2-x1+1) k1++;
	int k2=0;
	while((1<<(k2+1))<=y2-y1+1) k2++;
	x2=x2-(1<<k1)+1;
	y2=y2-(1<<k2)+1;
	return max(max(maxx[x1][y1][k1][k2],maxx[x1][y2][k1][k2]),max(maxx[x2][y1][k1][k2],maxx[x2][y2][k1][k2]));
}
int main()
{
	int n,m,i,j,q,a,b,c,d;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&v[i][j]);
			}
		}
		RMQ(n,m);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			int ans=query(a,b,c,d);
			printf("%d ",ans);
			if(v[a][b]==ans||v[a][d]==ans||v[c][b]==ans||v[c][d]==ans) puts("yes");
			else puts("no");
		}
	}
	return 0;
}