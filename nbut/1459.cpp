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
int main()
{
	int ans,n,temp;
	while(~scanf("%d",&n)&&n)
	{
		ans=0;
		while(n>=3)
		{
			temp=n/3;
			n%=3;
			ans+=temp;
			n+=temp;
		}
		if(n==2) ans++;
		printf("%d\n",ans);
	}
	return 0;
}