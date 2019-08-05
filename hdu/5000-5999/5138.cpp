////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 19:28:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5138
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:8732KB
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
const int MAX=1e5+50;
const ll mod=1e9+7;
vector<int> ans[MAX];
void init()
{
	int i;
	for(i=1;i<MAX;i++)
	{
		ans[i].clear();
	}
	for(i=1;i<=1e5;i++)
	{
		ans[i+1].pb(i);
		ans[i+2].pb(i);
		ans[i+4].pb(i);
		ans[i+7].pb(i);
		ans[i+15].pb(i);
	}
}
int main()
{
	init();
	int n,i;
	while(~scanf("%d",&n))
	{
		for(i=0;i<sz(ans[n]);i++)
		{
			if(i==sz(ans[n])-1) printf("%d\n",ans[n][i]);
			else printf("%d ",ans[n][i]);
		}
	}
	return 0;
}