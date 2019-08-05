////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-16 15:15:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1576KB
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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int i,flag=0,cnt=0;
	char a[111];
//	freopen("in.txt","r",stdin);
	while(~scanf("%s",a))
	{
		if(a[0]!='<')
		{
			if(cnt+strlen(a)>=80)
			{
				flag=0;
				puts("");
				cnt=0;
			}
			if(flag)
			{
				printf(" ");
				cnt++;
			}
			printf("%s",a);
			cnt+=strlen(a);
			flag=1;
		}
		else
		{
			if(a[1]=='b') puts("");
			else
			{
				if(flag) puts("");
				puts("--------------------------------------------------------------------------------");
			}
			flag=0;
			cnt=0;
		}
	}
	puts("");
	return 0;
}
