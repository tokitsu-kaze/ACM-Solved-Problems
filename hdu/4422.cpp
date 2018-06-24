////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-02 15:50:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4422
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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,j,k,s,a[7],flag,tag;
	while(~scanf("%d",&n))
	{
		s=0;
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		if(n<=3)
		{
			puts("1024");
			continue;
		}
		flag=0;
		tag=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				for(k=j+1;k<n;k++)
				{
					int temp=a[i]+a[j]+a[k];
					if(temp%1024==0) tag=1,flag=max(flag,((s-temp)%1024==0&&s-temp)?1024:(s-temp)%1024);
				}
			}
		}
		if(tag)
		{
			if(n==4) puts("1024");
			else printf("%d\n",flag);
		}
		else
		{
			if(n==4)
			{
				int ans=0;
				for(i=0;i<n;i++)
				{
					for(j=i+1;j<n;j++)
					{
						ans=max(ans,((a[i]+a[j])%1024==0&&a[i]+a[j])?1024:(a[i]+a[j])%1024);
					}
				}
				printf("%d\n",ans);
			}
			else puts("0");
		}
	}
	return 0;
}
