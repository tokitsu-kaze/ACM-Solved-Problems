////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-21 18:42:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5162
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
struct node
{
	int id,v;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
}a[5];
int main()
{
	int t,n,i,j,x,ans[11];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			a[i].id=i;
			a[i].v=0;
			for(j=1;j<=3;j++)
			{
				scanf("%d",&x);
				a[i].v=max(a[i].v,x);
			}
		}
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++)
		{
			ans[a[i].id]=i;
		}
		for(i=1;i<=n;i++)
		{
			if(i==n) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}