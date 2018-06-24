////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-28 11:53:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1288
////Problem Title: 
////Run result: Accept
////Run time:46MS
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
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e4+10;
const ll mod=1e9+7;
int main()
{
	int n,a,b,c,a1,b1,c1,now;
	while(~scanf("%d%d%d%d",&n,&a,&b,&c)&&n+a+b+c)
	{
		now=a+b*5+c*10;
		if(now<n)
		{
			puts("Hat cannot buy tea.");
			continue;
		} 
		while(now>n)
		{
			if(c>0)
			{
				now-=10;
				c--;
			}
			else break;
			if(now<n)
			{
				c++;
				now+=10;
				break;
			}
		}
		while(now>n)
		{
			if(b>0)
			{
				now-=5;
				b--;
			}
			else break;
			if(now<n)
			{
				b++;
				now+=5;
				break;
			}
		}
		while(now>n)
		{
			if(a>0)
			{
				now--;
				a--;
			}
			else break;
		}
		if(now!=n) puts("Hat cannot buy tea.");
		else printf("%d YiJiao, %d WuJiao, and %d ShiJiao\n",a,b,c);
	}
	return 0;
}