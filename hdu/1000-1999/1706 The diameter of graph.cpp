////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-19 12:39:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1706
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:1772KB
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
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=40000+10;
const ll mod=1e6;
int n;
int mp[111][111];
int cnt[111][111]; 
void flyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(mp[i][j]>mp[i][k]+mp[k][j])
				{
					mp[i][j]=mp[i][k]+mp[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}
				else if(mp[i][j]==mp[i][k]+mp[k][j])
				{
					cnt[i][j]+=cnt[i][k]*cnt[k][j];
				}
			}
		}
	}
}
int main()
{
	int m,a,b,c,i,j,ans,cnta;
	while(~scanf("%d%d",&n,&m))
	{
		mem(mp,0x3f);
		mem(cnt,0);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(mp[a][b]>c)
			{
				mp[a][b]=mp[b][a]=c;
				cnt[a][b]=cnt[b][a]=1;
			}
			else if(mp[a][b]==c)
			{
				cnt[a][b]++;
				cnt[b][a]++;
			}
		}
		flyd();
		cnta=0;
		ans=-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				if(mp[i][j]!=INF) ans=max(ans,mp[i][j]);
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<i;j++)
			{
				if(mp[i][j]==ans) cnta+=cnt[i][j];
			}
		}
		printf("%d %d\n",ans,cnta);
	}
	return 0;
}