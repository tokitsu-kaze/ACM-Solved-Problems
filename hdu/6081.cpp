////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-07 19:13:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6081
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1684KB
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
	int n,m,ans[3010],i,a,b,w;
	while(~scanf("%d%d",&n,&m))
	{
		mem(ans,0);
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&w);
			if(a!=b)
			{
				ans[a]+=w;
				ans[b]+=w;
			}
		}
		printf("%d\n",*min_element(ans+1,ans+1+n));
	}
	return 0;
}