#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int dp[31][2];
int count(int n)
{
	int i,sum=0,cnt=0;
	for(i=30;i>=0;i--)
	{
		if(n&(1<<i))
		{
			sum+=dp[i+1][0];
			sum+=(1<<i)*cnt;
			cnt++;
		}
	}
	return sum+cnt;
}
int main()
{
	int t,i,a,b,fa,fb;
	double sum;
	mem(dp,0);
	for(i=1;i<31;i++)
	{
		dp[i][1]=dp[i-1][1]+dp[i-1][0]+(1<<(i-1));
		dp[i][0]=dp[i-1][1]+dp[i-1][0];
	}
	while(cin>>t)
	{
		while(t--)
		{
			scanf("%d%d",&a,&b);
			sum=0;
			for(i=30;i>=0;i--)
			{
				if(a&(1<<i))
				{
					fa=i;
					break;
				}
			}
			for(i=30;i>=0;i--)
			{
				if(b&(1<<i))
				{
					fb=i;
					break;
				}
			}
			if(fa==fb)
			{
				sum=(count(b)-count(a-1))*1.0/(fa+1);
			}
			else
			{
				sum+=(count(((1<<(fa+1))-1))-count(a-1))*1.0/(fa+1);
				sum+=(count(b)-count((1<<fb)-1))*1.0/(fb+1);
				for(i=fa+2;i<=fb;i++)
				{
					sum+=dp[i][1]*1.0/i;
				}
			}
			printf("%lf\n",sum/(b-a+1));
		}
	}
	return 0;
}