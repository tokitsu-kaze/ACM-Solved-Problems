////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-21 20:16:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5182
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1688KB
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
	int id,v,b;
	friend bool operator <(node a,node b)
	{
		if(a.v==b.v)
		{
			if(a.b==b.b) return a.id<b.id;
			return a.b<b.b;
		}
		return a.v>b.v;
	}
}a[111];
int main()
{
	int n,i;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			a[i].id=i;
			scanf("%d%d",&a[i].v,&a[i].b);
			a[i].v-=a[i].b;
		}
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			if(i==n-1) printf("%d\n",a[i].id);
			else printf("%d ",a[i].id);
		}
	}
	return 0;
}