#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
	int n,i,j,k,prime[201],c1[201],c2[201],a[51],count=0,sum;
	memset(prime,0,sizeof(prime));
	for(i=3;i<200;i+=2)
	{
		prime[i]=1;
	}
	prime[2]=1;
	for(i=3;i<=sqrt(200.0);i++)
	{
		if(prime[i])
		{
			for(j=i+i;j<200;j+=i)
			{
				prime[j]=0;
			}
		}
	}
	for(i=2;i<200;i++)
	{
		if(prime[i]) a[count++]=i;
	}
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	for(i=0;i<=200;i+=2)
	{
		c1[i]=1;
	}
	for(i=1;i<count;i++)
	{
		for(j=0;j<=200;j++)
		{
			for(k=0;k+j<=200;k+=a[i])
			{
				c2[k+j]+=c1[j];
			}
		}
		for(j=0;j<=200;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	while(cin>>n)
	{
		cout<<c1[n]<<endl;
	}
    return 0;
}