////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-04 14:48:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1181
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1584KB
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
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef __int64 ll;
//typedef long long ll;
int n,flag;
struct word
{
	int flag,len;
	char b[111];
}a[11111];
void dfs(int t)
{
	int i;
	if(a[t].b[a[t].len-1]=='m')
	{
		flag=1;
		return;
	}
	for(i=0;i<n;i++)
	{
		if(!a[i].flag&&a[t].b[a[t].len-1]==a[i].b[0])
		{
			a[i].flag=1;
			dfs(i);
			a[i].flag=0;
		}
		if(flag) return;
	}
}
int main()
{
	int i;
	while(~scanf("%s",a[0].b))
	{
		if(a[0].b[0]=='0') break;
		a[0].flag=0;
		a[0].len=strlen(a[0].b);
		for(i=1;;i++)
		{
			scanf("%s",a[i].b);
			if(a[i].b[0]=='0') break;
			a[i].flag=0;
			a[i].len=strlen(a[i].b);
		}
		n=i;
	//	cout<<n<<endl;
		flag=0;
		for(i=0;i<n&&!flag;i++)
		{
			if(a[i].b[0]=='b')
			{
				a[i].flag=1;
				dfs(i);
				a[i].flag=0;
			}
		}
		if(flag) puts("Yes.");
		else puts("No.");
	}
    return 0;
}