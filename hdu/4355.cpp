////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-20 13:38:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4355
////Problem Title: 
////Run result: Accept
////Run time:1575MS
////Run memory:2500KB
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
const int MAX=5e4+10;
const ll mod=1e9+7;
ll n;
struct node
{
	double w;
	double x;
}a[MAX];
double cal(double x)
{
	ll i;
	double res=0;
	for(i=0;i<n;i++)
	{
		res+=pow(fabs(a[i].x-x),3)*a[i].w;
	}
	return res;
}
int main()
{
	ll t,i,cas=1,cnt;
	scanf("%lld",&t);
	while(t--)
	{
		double l,r,mid,rm,lm,tl,tr;
		scanf("%lld",&n);
		l=1e6;
		r=-1e6;
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].w);
			l=min(l,a[i].x);
			r=max(r,a[i].x);
		}
		cnt=0;
		while(r-l>eps)
		{  
			rm=(l+r)/2;  
			lm=(rm+r)/2;
			tl=cal(lm);
			tr=cal(rm);
			if(tr<=tl) r=lm;
			else l=rm;
			cnt++;
		}
		printf("Case #%lld: %.0lf\n",cas++,cal((l+r)/2));
	}
	return 0;
}
/*
100
4
-999999 14
990000 14
999998 13
999999 14

*/