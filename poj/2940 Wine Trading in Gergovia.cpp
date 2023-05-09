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
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100000+10;
const int EDGE=20000+10;//±ßµÄÌõÊý
typedef long long ll;
ll a[MAX];
int main()
{
	ll n,i,j,sum;
	while(~scanf("%lld",&n)&&n)
	{
		mem(a,0);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(a[i]>0) sum+=a[i];
			else sum-=a[i];
			if(i+1!=n) a[i+1]+=a[i];
		}
		printf("%lld\n",sum);
	}
}