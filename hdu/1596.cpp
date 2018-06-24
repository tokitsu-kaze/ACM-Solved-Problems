////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-28 15:22:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1596
////Problem Title: 
////Run result: Accept
////Run time:2558MS
////Run memory:8176KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e3+10;
const ll mod=1e9+7;
int n;
double mp[1010][1010];
void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				mp[i][j]=max(mp[i][j],mp[i][k]*mp[k][j]);
			}
		} 
	}
}
int main()
{
	int i,j,q,a,b;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%lf",&mp[i][j]);
			}
		}
		floyd();
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&a,&b);
			if(mp[a][b]==0) puts("What a pity!");
			else printf("%.3lf\n",mp[a][b]);
		}
	}
	return 0;
}