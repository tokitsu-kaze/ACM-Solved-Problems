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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int n,i,a,b;
	while(~scanf("%d",&n))
	{
		a=b=0;
		printf("a");
		for(i=1;i<n;i++)
		{
			if(b!=2)
			{
				printf("b");
				b++;
			}
			else if(a!=2)
			{
				printf("a");
				a++;
			}
			if(a==2&&b==2)
			{
				a=b=0;
			}
		}
		puts("");
	}
	return 0;
}