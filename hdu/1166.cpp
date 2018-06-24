////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 19:43:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:436MS
////Run memory:3120KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 50000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int ans;
struct tree
{
	int l,r,v;
}tree[4*MAX];
void build(int l,int r,int id)
{
	int mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].v=0;
	if(l==r) return;
	mid=(tree[id].l+tree[id].r)/2;
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
}
void update(int l,int r,int v,int id)
{
	int mid;
	tree[id].v+=v;
	if(tree[id].l==l&&tree[id].r==r) return;
	mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)
	{
		update(l,r,v,id*2);
	}
	else if(l>=mid+1)
	{
		update(l,r,v,id*2+1);
	}
	else
	{
		update(l,mid,v,id*2);
		update(mid+1,r,v,id*2+1);
	}
}
void query(int l,int r,int id)
{
	int mid;
	if(tree[id].l==l&&tree[id].r==r)
	{
		ans+=tree[id].v;
		return;
	}
	mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)
	{
		query(l,r,id*2);
	}
	else if(l>=mid+1)
	{
		query(l,r,id*2+1);
	}
	else
	{
		query(l,mid,id*2);
		query(mid+1,r,id*2+1);
	}
}
int main()
{
    int t,cas,n,i,a,b,v;
    char op[11];
    while(~scanf("%d",&t))
    {
		cas=1;
		while(t--)
		{
			scanf("%d",&n);
			build(1,n,1);
			for(i=1;i<=n;i++)
			{
				scanf("%d",&v);
				update(i,i,v,1);
			}
			printf("Case %d:\n",cas++);
			while(1)
			{
				getchar();
				scanf("%s",op);
				if(strcmp(op,"End")==0) break;
				scanf("%d%d",&a,&b);
				ans=0;
				if(strcmp(op,"Add")==0)
				{
					update(a,a,b,1);
				}
				else if(strcmp(op,"Sub")==0)
				{
					update(a,a,-b,1);
				}
				else if(strcmp(op,"Query")==0)
				{
					query(a,b,1);
					printf("%d\n",ans);
				}
			}
		}
	}
    return 0;
}