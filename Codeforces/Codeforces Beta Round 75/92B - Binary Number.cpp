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
char a[MAX];
int main()
{
	int len,i,cnt,flag;
	while(gets(a))
	{
		len=strlen(a)-1;
		cnt=0;
		while(len>0)
		{
			for(;len>0&&a[len]=='0';cnt++)
			{
				len--;
			}
			for(flag=0;len>0&&a[len]=='1';cnt++)
			{
				len--;
				if(!flag) cnt++;
				flag=1;
			}
			if(len>0&&flag) a[len]='1';
			else if(flag) cnt++;
		} 
		printf("%d\n",cnt);
		mem(a,0);
	}
    return 0;
}