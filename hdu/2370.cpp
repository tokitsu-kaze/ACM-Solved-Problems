////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-10 14:57:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2370
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1780KB
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
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=1e6+10;
int f[24],a[24],ans[25010];
void dfs(int pos,int s)
{
	int i;
	if(pos==22)
	{
		if(s>=25000) return;
		int temp=0;
		for(i=2;i<=21;i++)
		{
			temp+=(a[i]*f[i-1]);
		}
		ans[s]=temp;
		return;
	}
	for(i=0;i<2;i++)
	{
		if(i*a[pos-1]) continue;
		a[pos]=i;
		dfs(pos+1,s+i*f[pos]);
	}
}
int main()
{
	int i,t,x;
	f[1]=1;
	f[2]=2;
	for(i=3;i<=21;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	mem(ans,0);
	dfs(1,0);
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}