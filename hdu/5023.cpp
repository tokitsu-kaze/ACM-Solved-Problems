////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-28 19:22:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5023
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:34424KB
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
#define MAX 1000000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
struct node
{
	int l,r,v,laze;
	int calmid()
	{
		return (l+r)/2;
	}
}tree[4*MAX];
void pushdown(int id)
{
	tree[id].laze=0;
	tree[id*2].laze=1;
	tree[id*2+1].laze=1;
	tree[id*2].v=tree[id].v;
	tree[id*2+1].v=tree[id].v;
}
void build(int l,int r,int id,int v)
{
	int mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].laze=0;
	if(l==r)
	{
		tree[id].v=(1<<v);
		return;
	}
	mid=tree[id].calmid();
	build(l,mid,id*2,v);
	build(mid+1,r,id*2+1,v);
	tree[id].v=(tree[id*2].v|tree[id*2+1].v);
}
void updata(int l,int r,int id,int v)
{
	int mid;
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].v=(1<<v);
		tree[id].laze=1;
		return;
	}
	if(tree[id].laze) pushdown(id);
	mid=tree[id].calmid();
	if(r<=mid) updata(l,r,id*2,v);
	else if(l>=mid+1) updata(l,r,id*2+1,v);
	else
	{
		updata(l,mid,id*2,v);
		updata(mid+1,r,id*2+1,v);
	}
	tree[id].v=(tree[id*2].v|tree[id*2+1].v);
}
int query(int l,int r,int id)
{
	int mid;
	if(tree[id].l==l&&tree[id].r==r)
	{
		return tree[id].v;
	}
	if(tree[id].laze) pushdown(id);
	mid=tree[id].calmid();
	if(r<=mid) return query(l,r,id*2);
	else if(l>=mid+1) return query(l,r,id*2+1);
	else return (query(l,mid,id*2)|query(mid+1,r,id*2+1));
}
int main()
{
//	freopen("in.txt","r",stdin);	
	int n,m,a,b,c,t,i,ans[33],k;
	char op,temp[33];
    while(~scanf("%d%d",&n,&m)&&(n+m))
    {
		build(1,n,1,2);
		while(m--)
		{
			getchar();
			scanf("%c",&op);
			if(op=='P')
			{
				scanf("%d%d%d",&a,&b,&c);
				updata(a,b,1,c);
			}
			else if(op=='Q')
			{
				scanf("%d%d",&a,&b);
				t=query(a,b,1);
				mem(temp,0);
				mem(ans,0);
				k=0;
				itoa(t,temp,2);
				reverse(temp,temp+strlen(temp));
				for(i=0;i<strlen(temp);i++)
				{
					if(temp[i]=='1') ans[k++]=i;
				}
				for(i=0;i<k;i++)
				{
					if(!i) printf("%d",ans[i]);
					else printf(" %d",ans[i]);
				}
				puts("");
			}
		}
	}
    return 0;
}