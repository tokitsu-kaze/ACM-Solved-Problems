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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=4000000;
const ll mod=1e6;
int main()
{
	ll n,a,b,flag;
	while(~scanf("%lld",&n))
	{
		flag=0;
		if(n%1234567==0) flag=1;
		if(n%123456==0) flag=1;
		if(n%1234==0) flag=1;
		if(n==0)
		{
			puts("NO");
			continue;
		}
		for(a=0;a*1234567<=n;a++)
		{
			for(b=0;a*1234567+b*123456<=n;b++)
			{
				if((n-a*1234567-b*123456)%1234==0)
				{
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}