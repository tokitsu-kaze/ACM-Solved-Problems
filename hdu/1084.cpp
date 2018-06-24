////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-11 12:57:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1084
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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
struct node
{
	int id,time,p,v;
}a[111];
bool cmp1(node a,node b)
{
	if(a.p==b.p) return a.time<b.time;
	return a.p>b.p;
}
bool cmp2(node a,node b)
{
	return a.id<b.id;
}
int main()
{
	int n,tag[11],h,m,s,p,cnt[11],i;
	while(~scanf("%d",&n)&&n!=-1)
	{
		mem(tag,0);
		for(i=0;i<n;i++)
		{
			scanf("%d %d:%d:%d",&p,&h,&m,&s);
			a[i].id=i;
			a[i].p=p;
			a[i].time=h*3600+m*60+s;
			tag[p]++;
		}
		sort(a,a+n,cmp1);
		mem(cnt,0);
		for(i=0;i<n;i++)
		{
			if(a[i].p==5) a[i].v=100;
			else if(a[i].p==4)
			{
				if(cnt[a[i].p]<tag[a[i].p]/2) a[i].v=95;
				else a[i].v=90;
			}
			else if(a[i].p==3)
			{
				if(cnt[a[i].p]<tag[a[i].p]/2) a[i].v=85;
				else a[i].v=80;
			}
			else if(a[i].p==2)
			{
				if(cnt[a[i].p]<tag[a[i].p]/2) a[i].v=75;
				else a[i].v=70;
			}
			else if(a[i].p==1)
			{
				if(cnt[a[i].p]<tag[a[i].p]/2) a[i].v=65;
				else a[i].v=60;
			}
			else if(a[i].p==0) a[i].v=50;
			cnt[a[i].p]++;
		}
		sort(a,a+n,cmp2);
		for(i=0;i<n;i++)
		{
			printf("%d\n",a[i].v);
		}
		puts("");
	}
	return 0;
}