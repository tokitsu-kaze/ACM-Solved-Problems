////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-18 10:21:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6140
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
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
const int MAX=1e3+10;
const ll mod=1e9+7;
struct node
{
	int v;
	char c[3];
}a[MAX];
int main()
{
	int t,n,k,i,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].v);
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i].c);
		}
		l=r=0;
		for(i=0;i<n;i++)
		{
			if(a[i].c[0]=='L') r+=a[i].v;
			else if(a[i].c[0]=='D') l-=a[i].v;
			else
			{
				r+=a[i].v;
				l-=a[i].v;
			}
		}
		if(k>=l&&k<=r) puts("yes");
		else puts("no");
	}
	return 0;
}