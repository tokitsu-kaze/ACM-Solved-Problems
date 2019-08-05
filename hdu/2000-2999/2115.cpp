////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 21:45:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2115
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1620KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef long long ll;
struct time
{
	char name[101];
	int h,m;
}a[15];
int cmp(time a,time b)
{
	if(a.h==b.h)
	{
		if(a.m==b.m) return strcmp(a.name,b.name)<0;
		return a.m<b.m;
	}
	return a.h<b.h;
}
int main()
{
	int n,i,temp,cas=1,flag=0;
	while(cin>>n&&n)
	{
		if(flag) puts("");
		for(i=1;i<=n;i++)
		{
			getchar();
			scanf("%s %d:%d",a[i].name,&a[i].h,&a[i].m);
		}
		sort(a+1,a+n+1,cmp);
		printf("Case #%d\n",cas++);
		printf("%s %d\n",a[1].name,1);
		temp=1;
		for(i=2;i<=n;i++)
		{
			if(a[i].h==a[i-1].h&&a[i].m==a[i-1].m) printf("%s %d\n",a[i].name,temp);
			else
			{
				printf("%s %d\n",a[i].name,i);
				temp=i;
			}
		}
		flag=1;
	}
    return 0;
}