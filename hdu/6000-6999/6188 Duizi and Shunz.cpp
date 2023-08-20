////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-31 17:21:33
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6188
////Problem Title: 
////Run result: Accept
////Run time:826MS
////Run memory:9496KB
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
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e6+10;
const ll mod=1e9+7;
int a[MAX],res[MAX];
int main()
{
	int n,i,x,ans;
	while(~scanf("%d",&n))
	{
		mem(a,0);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		mem(res,0);
		for(i=1;i<=n;i++)
		{
			res[i]=a[i]/2;
			a[i]%=2;
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(i>=3&&a[i-2]&&a[i-1])
			{
				if(a[i])
				{
					a[i-2]=a[i-1]=a[i]=0;
					ans++;
				}
				else if(res[i])
				{
					a[i-2]=a[i-1]=0;
					res[i]--;
					a[i]=1;
					ans++;
				}
			}
			ans+=res[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
9
1 2 3 3 4 5 5 6 7
*/