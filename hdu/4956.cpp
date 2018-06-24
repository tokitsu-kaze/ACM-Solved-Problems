////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-15 16:32:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4956
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1680KB
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
	ll t,l,r,i,j,s,ans,cnt,flag,c;
	char temp[22];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		cnt=flag=0;
		for(i=l;i<=r;i++)
		{
			s=0;
			sprintf(temp,"%lld",i);
			c=1;
			for(j=strlen(temp)-1;j>=0;j--)
			{
				s+=(temp[j]-'0')*c;
				c*=-1;
			}
			cnt+=(s==3);
			ans=(i+8)/11-(l-1+8)/11;
			if(cnt!=ans)
			{
				flag=1;
				break;
			}
		}
		if(flag) printf("%lld\n",i);
		else puts("-1");
	}
	return 0;
}