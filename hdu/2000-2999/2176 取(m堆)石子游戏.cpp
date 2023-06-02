////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-09 18:59:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2176
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:2456KB
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
const int MAX=2e5+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,s,i;
	while(~scanf("%d",&n)&&n)
	{
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s^=a[i];
		}
		if(!s)
		{
			puts("No");
			continue;
		}
		puts("Yes");
		for(i=0;i<n;i++)
		{
			if((s^a[i])<a[i]) printf("%d %d\n",a[i],s^a[i]);
		}
	}
	return 0;
}