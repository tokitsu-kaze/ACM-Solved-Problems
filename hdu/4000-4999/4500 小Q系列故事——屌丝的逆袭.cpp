////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-15 09:11:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4500
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
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int m,n;
int check(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return 0;
	return 1;
}
int main()
{
	int i,j,k,a[33][33],b[33][33],x,y,ans[3],temp;
	while(~scanf("%d%d",&n,&m)&&m+n)
	{
		mem(a,0);
		mem(b,0);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		mem(ans,0);
		temp=-INF;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				for(k=0;k<4;k++)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					if(check(x,y))
					{
						if((a[i][j]>0&&a[x][y]<0)||(a[i][j]>0&&a[x][y]>0))
						{
							b[i][j]-=a[x][y];
						}
						else if((a[i][j]<0&&a[x][y]>0)||(a[i][j]<0&&a[x][y]<0))
						{
							b[i][j]+=a[x][y];
						}
					}
				}
				if(b[i][j]>temp)
				{
					ans[0]=i;
					ans[1]=j;
					ans[2]=b[i][j];
					temp=b[i][j];
				}
			}
		}
		printf("%d %d %d\n",ans[0],ans[1],ans[2]);
	}
	return 0;
}