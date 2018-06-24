////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-16 17:41:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2206
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1544KB
//////////////////System Comment End//////////////////
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
#define MAX 10000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int i,temp,flag,cnt;
	char a[111];
	while(gets(a))
	{
		if(strlen(a)>15||!(a[0]>='0'&&a[0]<='9'))
		{
			puts("NO");
			continue;
		}
		flag=temp=cnt=0;
		for(i=0;i<strlen(a);i++)
		{
			if(cnt>3)
			{
				flag=1;
				break;
			}
			if(a[i]<'0'||a[i]>'9')
			{
				if(a[i]!='.')
				{
					flag=1;
					break;
				}
			}
			if(a[i]>='0'&&a[i]<='9')
			{
				if(!temp&&a[i]=='0'&&(i+1!=strlen(a)&&a[i+1]!='.'))
				{
					flag=1;
					break;
				}
				temp=temp*10+(a[i]-'0');
			}
			else if(a[i]=='.')
			{
				if(temp>255)
				{
					flag=1;
					break;
				}
				temp=0;
				cnt++;
			}
		}
		if(temp>255) flag=1;
		if(cnt!=3) flag=1;
		if(flag) puts("NO");
		else puts("YES");
	}
    return 0;
}