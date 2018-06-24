////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-05 15:54:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2059
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1580KB
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
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int l,n,c,t,vr,vt1,vt2,i,j,p[110];
    double dp[110],aim,t1;
    while(cin>>l)
    {
		cin>>n>>c>>t;
		cin>>vr>>vt1>>vt2;
		mem(p,0);
		mem(dp,0);
		for(i=1;i<=n;i++)
		{
			cin>>p[i];
		}
		p[n+1]=l;
		aim=1.0*l/vr;
		for(i=1;i<=n+1;i++)
		{
			dp[i]=INF;
			for(j=0;j<i;j++)
			{
				if(p[i]-p[j]>c) t1=c*1.0/vt1+(p[i]-p[j]-c)*1.0/vt2;
				else t1=(p[i]-p[j])*1.0/vt1;
				t1+=dp[j];
				if(j>0) t1+=t;
				dp[i]=min(dp[i],t1);
			}
		}
		if(dp[n+1]<aim) puts("What a pity rabbit!");
		else puts("Good job,rabbit!");
	}
    return 0;
}
