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
const int MAX=100+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
char a[1111][1111];
int main()
{
	int cnt=0,len=0,i,j,temp,temp1,flag;
	mem(a,0);
	while(gets(a[cnt++]))
	{
//		puts(a[cnt-1]);
		if(a[cnt-1][0]==' ')
		{
			cnt--;
			continue;
		}
		if(strlen(a[cnt-1])>len) len=strlen(a[cnt-1]);
	}
	for(i=0;i<len+2;i++)
	{
		putchar('*');
	}
	puts("");
	flag=0;
	for(i=0;i<cnt-1;i++)
	{
		putchar('*');
		temp=len-strlen(a[i]);
		temp1=temp/2;
		if(temp%2)
		{
			if(flag)
			{
				temp1++;
				flag=0;
			}
			else if(!flag)
			{
				flag=1;
			}
		}
		for(j=0;j<temp1;j++)
		{
			putchar(' ');
		}
		printf("%s",a[i]);
		for(;j<temp;j++)
		{
			putchar(' ');
		}
		putchar('*');
		puts("");
	}
	for(i=0;i<len+2;i++)
	{
		putchar('*');
	}
	puts("");
	return 0;
}