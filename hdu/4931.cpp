////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-15 15:54:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4931
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
int main()
{
	int t,i,a[11],s1,s2;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<6;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+6);
		s1=s2=0;
		for(i=5;i>=4;i--) s1+=a[i];
		for(i=3;i>=1;i--) s2+=a[i];
		if(s1>s2) puts("Grandpa Shawn is the Winner!");
		else puts("What a sad story!"); 
	}
	return 0;
}