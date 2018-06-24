////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-10 11:47:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1015
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1588KB
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
typedef long long ll;
int k,a[31],ans[6],flag2,len;
map<int,int>m;
bool cmp(char a,char b)
{
	return a>b;
}
void dfs(int row)
{
	int i;
	if(row==5)
	{
		if(ans[0]-pow(ans[1],2)+pow(ans[2],3)-pow(ans[3],4)+pow(ans[4],5)==k)
		{
			for(i=0;i<5;i++)
			{
				printf("%c",ans[i]-1+'A');
			}
			puts("");
			flag2=0;
		}
		return;
	}
	for(i=0;i<len;i++)
	{
		if(!m[a[i]])
		{
			m[a[i]]=1;
			ans[row]=a[i];
			dfs(row+1);
			m[a[i]]=0;
			ans[row]=0;
		}
		if(!flag2) return;
	}
	return;
}
int main()
{
	int i;
    char c[31];
	while(~scanf("%d %s",&k,c)&&k)
	{
		mem(a,0);
		mem(ans,0);
		m.clear();
		flag2=1;
		len=strlen(c);
		sort(c,c+len,cmp);
		for(i=0;i<len;i++)
		{
			a[i]=c[i]-'A'+1;
		}
		dfs(0);
		if(flag2) puts("no solution");
	}
    return 0;
}
