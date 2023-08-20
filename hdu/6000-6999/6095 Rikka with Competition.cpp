////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-08 17:20:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6095
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:2052KB
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
	int t,n,k,i,now,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		now=a[n-1];
		ans=1;
		for(i=n-2;i>=0;i--)
		{
			if(abs(a[i]-now)<=k)
			{
				now=a[i];
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
