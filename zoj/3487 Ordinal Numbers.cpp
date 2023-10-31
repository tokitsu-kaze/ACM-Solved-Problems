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
	int t,n;
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			printf("%d",n);
			if(n%10==1&&n%100!=11) puts("st");
			else if(n%10==2&&n%100!=12) puts("nd");
			else if(n%10==3&&n%100!=13) puts("rd");
			else puts("th");
		}
	}
	return 0;
}