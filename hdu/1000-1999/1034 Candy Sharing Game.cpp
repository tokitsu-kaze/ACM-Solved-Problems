////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-16 16:35:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1560KB
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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int n,i,j,k,a[1111],cnt,flag,temp;
	while(~scanf("%d",&n)&&n)
	{
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		cnt=0;
		while(1)
		{
			cnt++;
			temp=a[n-1]/2;
			for(i=n-1;i>0;i--)
			{
				a[i]=a[i]/2+a[i-1]/2;
				if(a[i]%2) a[i]++;
			}
			a[0]=a[0]/2+temp;
			if(a[0]%2) a[0]++;
			for(i=1,flag=0;i<n;i++)
			{
				if(a[i]!=a[i-1]) flag=1;
			}
			if(!flag) break;
		}
		printf("%d %d\n",cnt,a[0]);
	}
	return 0;
}
