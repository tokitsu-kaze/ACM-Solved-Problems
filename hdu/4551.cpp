////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-08 22:51:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4551
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1676KB
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-9;
const int MAX=100000+10;
const ll mod=10000;
int day[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int a,b;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int check(int y,int m,int d)
{
	if(gcd(m,d)!=a) return 0;
	if(m==2&&((y%4==0&&y%100!=0)||y%400==0))
	{
		if(d<=day[2]+1) return 1;
	}
	if(d<=day[m]) return 1;
	return 0;
}
int main()
{
	int t,cas=1,i,y,m,d,s,cnt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&y);
		s=a*b;
		m=d=-1;
		cnt=0;
		for(i=1;i<=12;i++)
		{
			if(s%i==0)
			{
				if(check(y,i,s/i))
				{
					m=i;
					d=s/i;
					cnt++;
				}
			}
		}
		printf("Case #%d: ",cas++);
		if(cnt==0) puts("-1");
		else if(cnt>1) puts("1");
		else printf("%d/%02d/%02d\n",y,m,d);
	}
	return 0;
}