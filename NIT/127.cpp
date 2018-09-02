#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#define MAX 100000+1
using namespace std;
int prime[MAX];
int a[MAX],c[MAX];
int main()  
{
	int n,i,j,count=0,k=1,f;
	c[0]=1;
	memset(prime,0,sizeof(prime));
	memset(a,0,sizeof(a));
	for(i=3;i<MAX;i+=2)
	{
		prime[i]=1;
	}
	prime[2]=1;
	for(i=2;i<sqrt(MAX);i++)
	{
		if(prime[i])
		{
		//	count++;
			for(j=i+i;j<MAX;j+=i)
			{
				prime[j]=0;
			}
		}
	//	a[i]=count;
	}
	for(i=2;i<MAX;i++)
	{
		if(prime[i]) count++;
		a[i]=count;
	}
	while(~scanf("%d",&n))
	{	
		printf("%d\n",a[n]);
    }
    return 0;  
}  
  