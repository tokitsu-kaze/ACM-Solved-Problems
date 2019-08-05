////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-18 19:18:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5108
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:5928KB
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
const long double eps=1e-8;
const int MAX=1e6+10;
const ll mod=1e9+7;
int prime[MAX],res[MAX],cnt;
void init()
{
	int i,j;
	mem(prime,0);
	prime[0]=prime[1]=1;
	cnt=0;
	for(i=2;i<MAX;i++)
	{
		if(!prime[i])
		{
			res[cnt++]=i;
			for(j=i+i;j<MAX;j+=i)
			{
				prime[j]=1;
			}
		}
	}
}
int a[MAX],c;
int main()
{
	init();
	int n,i,ans;
	while(~scanf("%d",&n))
	{
		if(n==1)
		{
			puts("0");
			continue;
		}
		c=0;
		for(i=0;i<cnt;i++)
		{
			if(n==1) break;
			while(n%res[i]==0)
			{
				n/=res[i];
				a[c++]=res[i];
			}
		}
		if(n!=1) a[c++]=n;
		sort(a,a+c);
		ans=1;
		for(i=0;i<c-1;i++)
		{
			ans*=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}