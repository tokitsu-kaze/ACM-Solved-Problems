////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-17 12:56:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1861
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
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
typedef long long ll;
typedef double LD;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e3+10;
const ll mod=10000;
int main()
{
	int n,h,m,flag[111],cnt,ans;
	char op[5];
	while(~scanf("%d",&n)&&n!=-1)
	{
		mem(flag,0);
		cnt=0;
		ans=0;
		scanf("%s %d:%d",op,&h,&m);
		if(n==0)
		{
			puts("0 0");
			continue;
		}
		else
		{
			if(op[0]=='S') flag[n]=h*60+m+1;
		}
		while(~scanf("%d %s %d:%d",&n,op,&h,&m)&&n)
		{
			if(op[0]=='S') flag[n]=h*60+m+1;
			else if(op[0]=='E')
			{
				if(flag[n])
				{
					ans+=h*60+m-flag[n]+1;
					cnt++;
					flag[n]=0; 
				}
			}
		}
		if(cnt==0)
		{
			puts("0 0");
			continue;
		}
		if(ans%cnt) ans=ans/cnt+1;
		else ans/=cnt;
		printf("%d %d\n",cnt,ans);
	}
	return 0;
}