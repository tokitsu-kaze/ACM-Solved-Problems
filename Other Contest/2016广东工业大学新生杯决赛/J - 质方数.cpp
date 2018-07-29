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
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
#define max 100010
int prime[max];
int main()
{
	int t,n,cnt,i,j;
	mem(prime,0);
	for(i=3;i<max;i+=2)
	{
		prime[i]=1;
	}
	prime[2]=1;
	for(i=3;i<=sqrt(max);i++)
	{
		if(prime[i])
		{
			for(j=i+i;j<max;j++)
			{
				prime[j]=0;
			}
		}
	}
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			for(i=(int)sqrt(n)+1;i>=2;i--)
			{
				if(prime[i])
				{
					cout<<i*i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
