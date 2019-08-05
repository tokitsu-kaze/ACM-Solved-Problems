////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-11 20:25:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5590
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1572KB
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
#define MAX 200+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int t,n,i,j,flag;
	char a[111],b[111];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d",&n);
			mem(a,0);
			mem(b,0);
			getchar();
			scanf("%s %s",a,b);
			flag=0;
			for(i=0;i<n;i++)
			{
				if((a[i]=='A'&&b[i]=='U')||(a[i]=='C'&&b[i]=='G')||(a[i]=='G'&&b[i]=='C')||(a[i]=='T'&&b[i]=='A'));
				else
				{
					flag=1;
					break;
				}
			}
			if(flag) puts("NO");
			else puts("YES");
		}
	}
    return 0;
}