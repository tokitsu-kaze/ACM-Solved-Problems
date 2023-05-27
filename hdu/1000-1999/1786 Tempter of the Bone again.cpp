////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-17 20:39:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1786
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1664KB
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
const int MAX=3e4+10;
const ll mod=1e9+7;
int main()
{
	int n,v,w,res;
	while(~scanf("%d%d",&n,&v)&&n+v)
	{
		res=0;
		while(n--)
		{
			scanf("%d",&w);
			res=max(res,w);
		}
		printf("%d\n",(v/res+(v%res!=0))*3);
	}
	return 0;
}