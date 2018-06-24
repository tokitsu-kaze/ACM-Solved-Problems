////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 15:27:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1455
////Problem Title: 
////Run result: Accept
////Run time:78MS
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
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int a[66];
int flag[66];
int len,n,cnt;
int dfs(int id,int s,int l)
{
	int i;
	if(s==cnt) return 1;
	if(l==len) return dfs(0,s+1,0);
	for(i=id;i<n;i++)
	{
		if(!flag[i]&&l+a[i]<=len)
		{
			flag[i]=1;
			if(dfs(id+1,s,l+a[i])) return 1;
			flag[i]=0;
			if(l==0) return 0;
			while(i+1<n&&a[i+1]==a[i])
			{
				i++;
			}
		}
	}
	return 0;
}
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int i,sum,ans;
	while(~scanf("%d",&n)&&n)
	{
		mem(a,0);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sort(a,a+n,cmp);
		for(i=1;i<=sum;i++)
		{
			if(sum%i==0)
			{
				mem(flag,0);
				len=i;
				cnt=sum/i;
				if(dfs(0,0,0))
				{
					ans=i;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
