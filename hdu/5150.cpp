////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-20 21:39:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5150
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1672KB
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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
bool check(int x)
{
	int i,flag;
	flag=0;
	for(i=2;i<=sqrt(x);i++)
	{
		if(x%i==0) flag=1;
	}
	return !flag;
}
int main()
{
	int n,x,ans,i;
	while(~scanf("%d",&n))
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(check(x)) ans+=x;
		}
		printf("%d\n",ans);
	}
	return 0;
}