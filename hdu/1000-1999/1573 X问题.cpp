////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-05 00:49:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1573
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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int g,t;
	g=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
int k;
int CRT(int *m,int *r,int n)
{
	int p=m[0],res=r[0],x,y,g;
	for(int i=1;i<n;i++)
	{
		g=exgcd(p,m[i],x,y);
		if((r[i]-res)%g) return 0;
		x=(r[i]-res)/g*x%(m[i]/g);
		res+=x*p;
		p=p/g*m[i];
		res%=p;
    }
    if(res<=0) res+=p;
    return res>k?0:(k-res)/p+1-(res==0);
}
int main()
{
	int t,i,m[11],r[11],n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&k,&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&r[i]);
		}
		printf("%d\n",CRT(m,r,n));
	}
	return 0;
}