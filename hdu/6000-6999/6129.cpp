////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-17 10:38:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6129
////Problem Title: 
////Run result: Accept
////Run time:702MS
////Run memory:2448KB
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
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int t,n,m,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(j=1;m;j<<=1,m>>=1)
		{
			if(m&1)
			{
				for(i=j+1;i<=n;i++)
				{
					a[i]^=a[i-j];
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(i==n) printf("%d\n",a[i]);
			else printf("%d ",a[i]);
		}
	}
	return 0;
}