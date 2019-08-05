////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-20 21:28:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5146
////Problem Title: 
////Run result: Accept
////Run time:46MS
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
	int t,i,j,a[1010],s,n,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i&1) s+=a[i];
			else s-=a[i];
		}
		if(s)
		{
			puts("No");
			continue;
		}
		flag=0;
		for(i=1,j=n;i<=(n+1)/2;i++,j--)
		{
			if(a[i]!=a[j])
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}