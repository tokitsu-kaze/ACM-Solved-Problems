#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
long long a[100005];
int main()
{
	long long n,m,k,sum,t,i;
	while(~scanf("%lld",&t))
	{
		while(t--)
		{
			memset(a,0,sizeof(a));
			sum=0;
			scanf("%lld",&n);
			for(i=0;i<n;i++)
			{
				scanf("%lld",&a[i]);
			}
			scanf("%lld",&m);
			for(i=0;i<m;i++)
			{
				scanf("%lld",&k);
				sum+=k; 
			}
			if(sum==0)
			{
				for(i=sum;i<n;i++)
				{
					printf("%lld",a[i]);
					if(i!=n-1) printf(" ");
				}
			}
			else if(sum<0)
			{
				sum=-sum;
				sum%=n;
				for(i=sum;i<n;i++)
				{
					printf("%lld ",a[i]);
				}
				for(i=0;i<sum;i++)
				{
					printf("%lld",a[i]);
					if(i!=sum-1) printf(" ");
				}
			}
			else if(sum>0)
			{
				sum%=n;
				for(i=n-sum;i<n;i++)
				{
					printf("%lld ",a[i]);
				}
				for(i=0;i<n-sum;i++)
				{
					printf("%lld",a[i]);
					if(i!=n-sum-1) printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}