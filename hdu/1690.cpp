////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-04 13:57:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1690
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1664KB
//////////////////System Comment End//////////////////
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef __int64 ll;
//typedef long long ll;
const ll INFF=1e18;
int main()
{
	ll t,cas,l1,l2,l3,l4,c1,c2,c3,c4,n,m,i,j,k,a[110],mp[110][110],dis,x,y;
	while(cin>>t)
	{
		for(cas=1;cas<=t;cas++)
		{
			cin>>l1>>l2>>l3>>l4>>c1>>c2>>c3>>c4;
			cin>>n>>m;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					mp[i][j]=INFF;
				}
			}
			for(i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					dis=abs(a[i]-a[j]);
					if(dis>0&&dis<=l1) mp[i][j]=c1;
					else if(dis>l1&&dis<=l2) mp[i][j]=c2;
					else if(dis>l2&&dis<=l3) mp[i][j]=c3;
					else if(dis>l3&&dis<=l4) mp[i][j]=c4;
				}
			}
			for(k=1;k<=n;k++)
			{
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
					{
						mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
					} 
				}
			}
			printf("Case %I64d:\n",cas);
			while(m--)
			{
				cin>>x>>y;
				if(mp[x][y]==INFF) printf("Station %I64d and station %I64d are not attainable.\n",x,y);
				else printf("The minimum cost between station %I64d and station %I64d is %I64d.\n",x,y,mp[x][y]);
			}
		}
	}
    return 0;
}