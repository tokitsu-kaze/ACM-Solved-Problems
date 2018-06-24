////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-21 18:49:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5166
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int t,i,x,n,a[1010],cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		mem(a,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		cnt=0;
		for(i=1;i<=n+2;i++)
		{
			if(!a[i])
			{
				if(cnt==0) printf("%d ",i);
				else
				{
					printf("%d\n",i);
					break;
				}
				cnt++;
			}
		}
	}
	return 0;
}