////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 19:22:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5123
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
const long double eps=1e-8;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int t,n,a[111],i,x,ans,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>ans)
			{
				ans=a[i];
				p=i;
			}
		}
		printf("%d\n",p);
	}
	return 0;
}