////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-03 18:19:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6075
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:2064KB
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
const ll mod=1e9+7;
int a[MAX];
int main()
{
	
	int t,i,n,c0,c1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		c0=c1=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]%2) c1++;
			else c0++;
		}
		if(c1>=c0) printf("2 1\n");
		else printf("2 0\n");
	}
	return 0;
}