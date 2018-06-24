////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-15 16:39:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4981
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
int main()
{
	int n,i,a[1010],s;
	while(~scanf("%d",&n))
	{
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		sort(a+1,a+1+n);
		if(s/n>=a[(n+1)/2]) puts("NO");
		else puts("YES");
	}
	return 0;
}