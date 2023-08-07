////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-11 18:12:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3817
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1564KB
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
int main()
{
	int t;
	scanf("%d",&t);
	int count=0;
	while(t--)
	{
		count++;
		int a[3];
		for(int i=0;i<3;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+3);
		int cnt=a[2]*a[2]-a[1]*a[1]-a[0]*a[0];
		printf("Case %d: ",count);
		if(cnt==0)
		{
			printf("Right triangle\n");
		}
		if(cnt<0)
		{
			printf("Acute triangle\n");
		}
		if(cnt>0)
		{
			printf("Obtuse triangle\n");
		}
	}
}