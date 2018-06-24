////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-08 16:08:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1081
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1756KB
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
const double eps=1e-9;
const int MAX=1000000+10;
const ll mod=10000;
int main()
{
	int n,a[111][111],mp[111][111],i,j,k,l,ans;
	while(~scanf("%d",&n))
	{
		mem(a,0);
		mem(mp,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&mp[i][j]);
				a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+mp[i][j];
			}
		}
/*		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
			}
		}*/
		ans=INT_MIN;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=i;k++)
				{
					for(l=1;l<=j;l++)
					{
						ans=max(ans,a[i][j]-a[k-1][j]-a[i][l-1]+a[k-1][l-1]);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}