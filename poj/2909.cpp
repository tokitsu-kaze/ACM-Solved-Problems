#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int prime[65536];
int main()
{
	int n,i,j,flag,count;
	mem(prime,0);
	prime[2]=1;
	for(i=0;i<=65535;i++)
	{
		if(i%2) prime[i]=1;
	}
	for(i=3;i<=sqrt(65535);i++)
	{
		if(prime[i])
		{
			for(j=i+i;j<65535;j+=i)
			{
				prime[j]=0;
			}
		}
	}
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		count=0;
		for(i=2;i<=n/2;i++)
		{
			if(prime[i]==1&&prime[n-i]==1) count++;
		}
		printf("%d\n",count);
	}
}