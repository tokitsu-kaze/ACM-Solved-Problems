////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 18:52:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5100
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const long double eps=1e-8;
const int MAX=447000+10;
const ll mod=1e9+7;
int main()
{
	int t,n,k,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		r=n%k;
		if(k>n) puts("0");
		else if(r<=k/2) printf("%d\n",n*n-r*r);
		else printf("%d\n",n*n-(k-r)*(k-r));
	}
	return 0;
}
//http://www.matrix67.com/blog/archives/5900