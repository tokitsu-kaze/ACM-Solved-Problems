////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-29 20:35:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1543
////Problem Title: 
////Run result: Accept
////Run time:655MS
////Run memory:17412KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 1000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
struct node
{
	int x1,y1,x2,y2,c;
}seg[MAX*2];
int x[MAX*2],y[MAX*2];
int color[2*MAX][2*MAX];
int search2x(int l,int r,int key)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(x[mid]==key) return mid;
		else if(x[mid]>key) r=mid-1;
		else l=mid+1;
	}
}
int search2y(int l,int r,int key)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(y[mid]==key) return mid;
		else if(y[mid]>key) r=mid-1;
		else l=mid+1;
	}
}
int main()
{
	int h,w,cas=0,kx,ky,cnt,n,i,j,k,lx,rx,ly,ry,area[111],ans;
	while(~scanf("%d%d",&h,&w)&&(h+w))
	{
		if(cas) puts("");
		scanf("%d",&n);
		cnt=0;
		mem(x,0);
		mem(y,0);
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d%d%d",&seg[i].x1,&seg[i].y1,&seg[i].x2,&seg[i].y2,&seg[i].c);
			x[cnt]=seg[i].x1;
			y[cnt++]=seg[i].y1;
			x[cnt]=seg[i].x2;
			y[cnt++]=seg[i].y2;
		}
		sort(x,x+cnt);
		sort(y,y+cnt);
		kx=ky=1;
		for(i=1;i<cnt;i++)
		{
			if(x[i]!=x[i-1]) x[kx++]=x[i];
		}
		for(i=1;i<cnt;i++)
		{
			if(y[i]!=y[i-1]) y[ky++]=y[i];
		}
		mem(color,0);
		for(i=0;i<n;i++)
		{
			lx=search2x(0,kx-1,seg[i].x1);
			rx=search2x(0,kx-1,seg[i].x2);
			ly=search2y(0,ky-1,seg[i].y1);
			ry=search2y(0,ky-1,seg[i].y2);
			for(j=lx;j<rx;j++)
			{
				for(k=ly;k<ry;k++)
				{
					color[j][k]=seg[i].c;
				}
			}
		}
		mem(area,0);
		for(i=0;i<kx;i++)
		{
			for(j=0;j<ky;j++)
			{
				if(color[i][j])
				{
					area[color[i][j]]+=(x[i+1]-x[i])*(y[j+1]-y[j]);
				}
			}
		}
		ans=0;
		printf("Case %d:\n",++cas);
		for(i=1;i<=100;i++)
		{
			if(area[i])
			{
				printf("%d %d\n",i,area[i]);
				ans++;
			}
		}
		if(ans<=1) printf("There is %d color left on the wall.\n",ans);
		else printf("There are %d colors left on the wall.\n",ans);
	}
	return 0;
}