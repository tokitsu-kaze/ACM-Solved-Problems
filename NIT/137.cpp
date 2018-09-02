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
#define max 1e18+10
using namespace std;
long long a[100100];
int main()
{
	long long i,j,m,n,count=0,l,r,mid;
	for(i=1;i<max;i*=2)
	{
		for(j=1;i*j<max;j*=5)
		{
			a[count++]=i*j;
		}
	}
	sort(a,a+count);
	while(cin>>n)
	{
		while(n--)
		{
			scanf("%lld",&m);
			l=1;
			r=count;
			while(l<r)
			{
				mid=(l+r)/2;
				if(a[mid]>=m) r=mid;
				else l=mid+1;
			}
			printf("%lld\n",a[l]);
		}
	}
	return 0;
}