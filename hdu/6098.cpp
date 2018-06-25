////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-12 09:18:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6098
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:2856KB
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
struct node
{
	int v,p;
}a[MAX];
bool cmp(node a,node b)
{
	return a.v>b.v;
}
int b[MAX];
int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			a[i].v=b[i];
			a[i].p=i;
		}
		sort(a+1,a+1+n,cmp);
		for(i=2;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[j].p%i)
				{
					if(i==2) printf("%d",a[j].v);
					else printf(" %d",a[j].v);
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}