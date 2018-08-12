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
	int t,a,b,k1,k2,i;
	char c[1111],d[1111],t1[55],t2[55];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			mem(c,0);
			mem(d,0);
			scanf("%d ",&a);
			gets(c);
			scanf("%d ",&b);
			gets(d);
			if(a!=b)
			{
				puts("DIFFERENT");
				continue;
			}
			mem(t1,0);
			mem(t2,0);
			k1=k2=0;
			t1[k1++]=c[0];
			t2[k2++]=d[0];
			for(i=1;i<strlen(c);i++)
			{
				if(c[i]==' ') t1[k1++]=c[i+1];
			}
			for(i=1;i<strlen(d);i++)
			{
				if(d[i]==' ') t2[k2++]=d[i+1];
			}
			if(strcmp(t1,t2)==0) puts("SAME");
			else puts("DIFFERENT");
		}
	}
	return 0;
}