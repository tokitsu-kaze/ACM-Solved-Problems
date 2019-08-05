////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-28 11:58:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2795
////Problem Title: 
////Run result: Accept
////Run time:2464MS
////Run memory:7740KB
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
#define MAX 200000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
struct node
{
	int l,r,v;
	int calmid()
	{
		return (l+r)/2;
	}
}tree[4*MAX];
void build(int l,int r,int id,int v)
{
	int mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].v=v;
	if(l==r) return;
	mid=tree[id].calmid();
	build(l,mid,id*2,v);
	build(mid+1,r,id*2+1,v);
}
void updata(int l,int r,int id,int v)
{
	int mid;
	if(l==r)
	{
		tree[id].v-=v;
		printf("%d\n",l);
		return;
	}
	mid=tree[id].calmid();
	if(tree[id*2].v>=v) updata(l,mid,id*2,v);
	else updata(mid+1,r,id*2+1,v);
	tree[id].v=max(tree[id*2].v,tree[id*2+1].v);
}
int main()
{
//	freopen("in.txt","r",stdin);	
	int h,w,n;
    while(~scanf("%d%d%d",&h,&w,&n))
    {
		if(h>n) h=n;
		build(1,h,1,w);
		while(n--)
		{
			scanf("%d",&w);
			if(tree[1].v<w) puts("-1");
			else updata(1,h,1,w);
		}
	}
    return 0;
}