////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-04 14:19:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5688
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:9552KB
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
const ll mod=9973;
int main()
{
	int n;
	char a[55];
	while(~scanf("%d",&n))
	{
		map<string,int> mp;
		while(n--)
		{
			scanf("%s",a);
			sort(a,a+strlen(a));
			printf("%d\n",mp[a]);
			mp[a]++;
		}
	}
	return 0;
}