////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-28 12:26:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1597
////Problem Title: 
////Run result: Accept
////Run time:686MS
////Run memory:1668KB
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
	int n,now,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		now=1;
		while(n>now)
		{
			n-=now;
			now++;
		}
		printf("%d\n",n%9==0?9:n%9);
	}
	return 0;
}