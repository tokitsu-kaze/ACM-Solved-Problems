////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-31 17:19:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6186
////Problem Title: 
////Run result: Accept
////Run time:686MS
////Run memory:4412KB
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
int a[MAX],a1[MAX],b1[MAX],c1[MAX],a2[MAX],b2[MAX],c2[MAX];
int main()
{
	int n,m,i,x;
	while(~scanf("%d%d",&n,&m))
	{
		scanf("%d",&a[1]);
		a1[1]=b1[1]=c1[1]=a[1];
		for(i=2;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a1[i]=a1[i-1]&a[i];
			b1[i]=b1[i-1]|a[i];
			c1[i]=c1[i-1]^a[i];
		}
		a2[n]=b2[n]=c2[n]=a[n];
		for(i=n-1;i>=1;i--)
		{
			a2[i]=a2[i+1]&a[i];
			b2[i]=b2[i+1]|a[i];
			c2[i]=c2[i+1]^a[i];
		}
		while(m--)
		{
			scanf("%d",&x);
			if(x==1) printf("%d %d %d\n",a2[x+1],b2[x+1],c2[x+1]);
			else if(x==n) printf("%d %d %d\n",a1[x-1],b1[x-1],c1[x-1]);
			else printf("%d %d %d\n",a1[x-1]&a2[x+1],b1[x-1]|b2[x+1],c1[x-1]^c2[x+1]);
		}
	}
	return 0;
}