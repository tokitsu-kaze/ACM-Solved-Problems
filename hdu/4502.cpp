////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-05-18 22:13:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4502
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:1764KB
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
vector<int> mp[111];
int val[111][111];
int main()
{
	int t,m,n,i,j,a,b,c,dp[111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		mem(val,0);
		for(i=0;i<n;i++)
		{
			mp[i].clear();
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a>n||b>n) continue;
			mp[a].push_back(b);
			val[a][b]=max(val[a][b],c);
		}
		mem(dp,0);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<mp[i].size();j++)
			{
				dp[mp[i][j]]=max(dp[mp[i][j]],*max_element(dp,dp+i)+val[i][mp[i][j]]);
			}
		}
		printf("%d\n",*max_element(dp+1,dp+1+n));
	}
	return 0;
}
