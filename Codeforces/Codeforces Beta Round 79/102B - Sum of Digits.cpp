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
#define eps 1e-9
#define MAX 1000000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
char a[MAX],b[MAX];
int main()
{
	int len,i,sum,cnt;
	while(~scanf("%s",a))
	{
		len=strlen(a);
		if(len==1)
		{
			puts("0");
			continue;
		}
		sum=0;
		for(i=0;i<len;i++)
		{
			sum+=(a[i]-'0');
		}
		cnt=1;
		while(sum>=10)
		{
			mem(b,0);
			itoa(sum,b,10);
			sum=0;
			for(i=0;i<strlen(b);i++)
			{
				sum+=(b[i]-'0');
			}
			cnt++;
		}
		printf("%d\n",cnt);
	}
    return 0;
}