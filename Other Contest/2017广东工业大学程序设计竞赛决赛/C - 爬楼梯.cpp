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
#include <set>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 200+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int main()
{
	ll n,i,a[51],t,sum,b;
	mem(a,0);
	a[1]=1;
	a[2]=2;
	a[3]=4;
	for(i=4;i<51;i++)
	{
		a[i]=a[i-1]+a[i-2]+a[i-3];
		a[i]%=10007;
	}
//	freopen("in.txt","r",stdin);
    while(~scanf("%lld",&t))
    {
		while(t--)
		{
			scanf("%lld",&n);
			sum=1;
			n--;
			while(n--)
			{
				scanf("%lld",&b);
				sum=sum*a[b]%10007;
			}
			printf("%lld\n",sum);
		} 
	}
    return 0;
}