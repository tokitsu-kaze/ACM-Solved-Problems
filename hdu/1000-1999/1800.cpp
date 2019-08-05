////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-05 10:57:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1800
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:1736KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=8e3+10;
const ll mod=1e9+7;
int main()
{
	int n,i,ans,x;
	while(~scanf("%d",&n))
	{
		map<int,int> mp;
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			mp[x]++;
			ans=max(ans,mp[x]);
		}
		printf("%d\n",ans);
	}
	return 0;
}