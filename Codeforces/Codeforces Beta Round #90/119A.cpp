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
#define MAX 1000000000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
	int a,b,c,cnt;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		while(1)
		{
			cnt=0;
			if(c==0||c-gcd(a,c)<0) break;
			c-=gcd(a,c);
			cnt=1;
			if(c==0||c-gcd(b,c)<0) break;
			c-=gcd(b,c);
		}
		if(cnt==0) puts("1");
		else puts("0");
	}
    return 0;
}