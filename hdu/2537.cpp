////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-16 18:06:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2537
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
	int n,flag1,flag2,r,y,i;
	char a;
	while(~scanf("%d",&n)&&n)
	{
		r=y=flag1=flag2=0;
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%c",&a);
			if(a=='R') r++;
			else if(a=='Y') y++;
			else if(a=='B'&&r!=7) flag1=-1;
			else if(a=='B'&&r==7) flag1=1;
			else if(a=='L'&&y!=7) flag2=-1;
			else if(a=='L'&&y==7) flag2=1;
		}
		if(flag1==-1) puts("Yellow");
		else if(flag1==1) puts("Red");
		if(flag2==-1) puts("Red");
		else if(flag2==1) puts("Yellow");
	}
    return 0;
}