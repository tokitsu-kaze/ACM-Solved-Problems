////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-09 15:27:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6092
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:1740KB
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
const int MAX=1e4+10;
const ll mod=1e9+7;
int main()
{
	int t,n,m,now,ans[MAX],a[MAX],i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=m;i++)
		{
			scanf("%d",&a[i]);
		}
		now=1;
		for(i=1;i<=m;i++)
		{
			if(!a[i]) continue;
			if(now>n) break;
			ans[now++]=i;
			a[i]--;
			for(j=i+1;j<=m;j++)
			{
				a[j]-=a[j-i];
			}
			i--;
		}
		for(i=1;i<=n;i++)
		{
			if(i==n) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}