////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-05 16:59:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1600KB
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
double mp[1111][1111];
int main()
{
	int n,id,flag,i,ans;
	double s,sum;
	char a[22][22];
	scanf("%d%lf",&n,&s);
	while(~scanf("%d",&id))
	{
		mem(a,0);
		flag=0;
		for(i=0;i<n;i++)
		{
			scanf(" %s",a[i]);
			if(a[i][0]=='-') flag=1;
		}
		if(flag)
		{
			printf("%3d: -\n",id);
			continue;
		}
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=(a[i][0]-'0')*3600+((a[i][2]-'0')*10+a[i][3]-'0')*60+((a[i][5]-'0')*10+a[i][6]-'0');
		}
		ans=sum/s;
		if(sum/s-(int)(sum/s)>=0.5) ans++;
		printf("%3d:% d:%02d min/km\n",id,ans/60,ans%60);
	}
	return 0;
}