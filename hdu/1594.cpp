////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-26 17:40:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1594
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:1668KB
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
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,x,pre,ans,p;
	while(~scanf("%d",&n))
	{
		scanf("%d",&x);
		pre=x;
		scanf("%d",&x);
		ans=abs(x-pre);
		pre=x;
		p=1;
		for(i=3;i<=n;i++)
		{
			scanf("%d",&x);
			if(abs(x-pre)>ans)
			{
				ans=abs(x-pre);
				p=i-1;
			}
			pre=x;
		}
		printf("%d %d\n",p,p+1);
	}
	return 0;
}