////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-01 14:03:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3791
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1684KB
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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
int tree1[(1<<10)+10],tree2[(1<<10)+10];
void insert1(int v)
{
	int now=1;
	while(tree1[now]!=INF)
	{
		if(v<tree1[now]) now<<=1;
		else if(v>tree1[now]) now=now<<1|1;
	}
	tree1[now]=v;
}
void insert2(int v)
{
	int now=1;
	while(tree2[now]!=INF)
	{
		if(v<tree2[now]) now<<=1;
		else if(v>tree2[now]) now=now<<1|1;
	}
	tree2[now]=v;
}
int main()
{
	int n,i,len;
	char a[111];
	while(~scanf("%d",&n)&&n)
	{
		scanf("%s",a+1);
		len=strlen(a+1);
		mem(tree1,0x3f);
		tree1[1]=a[1]-'0';
		for(i=2;i<=len;i++)
		{
			insert1(a[i]-'0');
		}
		while(n--)
		{
			scanf("%s",a+1);
			len=strlen(a+1);
			mem(tree2,0x3f);
			tree2[1]=a[1]-'0';
			for(i=2;i<=len;i++)
			{
				insert2(a[i]-'0');
			}
			int flag=0;
			for(i=1;i<=1<<10;i++)
			{
				if(tree1[i]!=tree2[i]) flag=1;
			}
			if(flag) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}