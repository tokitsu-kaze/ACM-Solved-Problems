////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-12 18:31:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6108
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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int t,n,ans,i;
	scanf("%d",&t);
	while(t--)
    {
		scanf("%d",&n);
		ans=0;
		n--;
		if(n==1) ans=1;
		else ans=2;
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				if(i==(int)sqrt(n)&&n/i==i) ans++;
				else ans+=2;
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}