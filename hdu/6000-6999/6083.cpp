////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-07 19:42:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6083
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1796KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
bool flag[111][1111],ans[111];
int main()
{
	int n,m,t,w[111],v[111],dp[1111],i,j,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&v[i],&w[i]);
		}
		mem(dp,0);
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			for(j=m;j>=0;j--)
			{
				if(j>=w[i])
				{
					if(dp[j]<dp[j-w[i]]+v[i])
					{
						dp[j]=dp[j-w[i]]+v[i];
						flag[i][j]=1;
					}
					else flag[i][j]=0;
				}
			}
		}
		mem(ans,0);
		for(i=n,j=m;i>=1;i--)
		{
			if(flag[i][j])
			{
				ans[i]=1;
				j-=w[i];
			}
		}
		printf("Case #%d:\n",cas++);
		printf("%d %d\n",dp[m],m-j);
		int tag=0;
		for(i=1;i<=n;i++)
		{
			if(ans[i])
			{
				if(tag) printf(" %d",i);
				else printf("%d",i);
				tag=1;
			}
		}
		if(tag) puts("");
	}
	return 0;
}
/*
100
29
6
9 10
3 4
6 5
7 20
10 9
15 11
0
2
2 23
10 12
20
6
20 12
10 8
10 11
20 9
100 0
0 0
20
6
20 12
20 12
10 8
10 11
10 8
20 9
0
2
0 0
0 0
666
0
20
2
20 18
20 17
*/