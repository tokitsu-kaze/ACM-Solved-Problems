////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-21 20:45:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5190
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,m,ans,i,a,b,temp;
	while(~scanf("%d%d",&n,&m))
	{
		ans=INF;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			temp=n/a*b;
			if(n%a) temp+=b;
			ans=min(ans,temp);
		}
		printf("%d\n",ans);
	}
	return 0;
}