////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-04 21:55:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2669
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1684KB
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
	int r,t;
	r=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
int main()
{
	int a,b,x,y;
	while(~scanf("%d%d",&a,&b))
	{
		if(exgcd(a,b,x,y)!=1)
		{
			puts("sorry");
			continue;
		}
		while(x<=0)
		{
			x+=b;
			y-=a;
		}
		printf("%d %d\n",x,y);
	}
	return 0;
}