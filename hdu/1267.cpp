////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-05 19:48:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1267
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
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
int main()
{
	ll f[22][22],i,j,m,n;
	mem(f,0);
	for(i=0;i<=20;i++)
	{
		f[i][0]=1;
	}
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=i;j++)
		{
			f[i][j]=f[i-1][j]+f[i][j-1];
		}
	}
	while(~scanf("%lld%lld",&m,&n))
	{
		printf("%lld\n",f[m][n]);
	}
	return 0;
}