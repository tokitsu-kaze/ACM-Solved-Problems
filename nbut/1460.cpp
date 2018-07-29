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
	int a,b,cnt=0,c;
	char op,ans[5],s;
	while(~scanf("%d%c%d%c%s",&a,&op,&b,&s,ans))
	{
		if(ans[0]=='?') continue;
		c=atoi(ans);
		if(op=='-')
		{
			if(a-b==c) cnt++;
		}
		else if(op=='+')
		{
			if(a+b==c) cnt++;
		}
	}
	printf("%d\n",cnt);
}