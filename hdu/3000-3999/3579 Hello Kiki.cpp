////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-05 00:37:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3579
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
int CRT(int *m,int *r,int n)
{
	int p=m[0],res=r[0],x,y,g;
	for(int i=1;i<n;i++)
	{
		g=exgcd(p,m[i],x,y);
		if((r[i]-res)%g) return -1;
		x=(r[i]-res)/g*x%(m[i]/g);
		res+=x*p;
		p=p/g*m[i];
		res%=p;
    }
    return res>0?res:res+p;
}
int main()
{
	int t,i,m[11],r[11],n,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&m[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&r[i]);
		}
		printf("Case %d: %d\n",cas++,CRT(m,r,n));
	}
	return 0;
}