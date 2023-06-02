////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 13:28:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2163
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1552KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
    int i,cas=1,flag;
    char a[111];
    while(gets(a))
    {
		if(strcmp(a,"STOP")==0) break;
		printf("#%d: ",cas++);
		flag=0;
		for(i=0;i<strlen(a)&&!flag;i++)
		{
			if(a[i]!=a[strlen(a)-1-i]) flag=1;
		}
		if(flag) puts("NO");
		else puts("YES");
	}
    return 0;
}