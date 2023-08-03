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
#define EDGE 20000+10//边的条数 
using namespace std;
typedef long long ll;
struct node
{
	double l,r,h;
	int tag;//1:上边界  -1:下边界 
}seg[2*MAX];//线段 
struct tree
{
	int l,r;
	int cover;
	double len;
	int calmid()
	{
		return (l+r)/2;
	}
}tree[4*MAX*2];
double x[2*MAX];//横坐标离散化 
int cmp(node a,node b)
{
	return a.h<b.h;
}
int search2(int l,int r,double key)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(x[mid]==key) return mid;
		if(key<x[mid]) r=mid-1;
		else l=mid+1;
	}
}
void callen(int id)
{
	if(tree[id].cover) tree[id].len=x[tree[id].r+1]-x[tree[id].l];
	//被整段覆盖
	else if(tree[id].l==tree[id].r) tree[id].len=0;
	//不是一条线段
	else tree[id].len=tree[id*2].len+tree[id*2+1].len;
	//是一条线段但又没有被整段覆盖 
}
void build(int l,int r,int id)
{
	int mid;
	tree[id].l=l;
	tree[id].r=r;
	tree[id].cover=0;
	tree[id].len=0;
	if(l==r) return;
	mid=tree[id].calmid();
	build(l,mid,id*2);
	build(mid+1,r,id*2+1);
}
void updata(int l,int r,int id,int v)
{
	int mid;
	if(tree[id].l==l&&tree[id].r==r)
	{
		tree[id].cover+=v;//覆盖情况
		callen(id);
		return;
	}
	mid=tree[id].calmid();
	if(r<=mid) updata(l,r,id*2,v);
	else if(l>=mid+1) updata(l,r,id*2+1,v);
	else
	{
		updata(l,mid,id*2,v);
		updata(mid+1,r,id*2+1,v);
	}
	callen(id);
}
int main()
{
//	freopen("in.txt","r",stdin);	
	int n,i,cas=1,k,l,r,cnt;
	double x1,y1,x2,y2,ans;
    while(~scanf("%d",&n)&&n)
    {
		k=0;
		mem(x,0);
		for(i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			x[k]=x1;
			seg[k].tag=1; 
			seg[k].l=x1;
			seg[k].r=x2;
			seg[k++].h=y1;
			//上边界 
			x[k]=x2;
			seg[k].tag=-1;
			seg[k].l=x1;
			seg[k].r=x2;
			seg[k++].h=y2;
			//下边界 
		}
		sort(seg,seg+k,cmp);//线段按纵坐标升序 
		sort(x,x+k);//横坐标升序
		cnt=1;
		for(i=1;i<k;i++)
		{
			if(x[i]!=x[i-1]) x[cnt++]=x[i];//去重 
		}
		build(0,cnt-1,1);
		ans=0;
		for(i=0;i<k;i++)
		{
			l=search2(0,cnt-1,seg[i].l);
			r=search2(0,cnt-1,seg[i].r)-1;
			updata(l,r,1,seg[i].tag);
			ans+=(seg[i+1].h-seg[i].h)*tree[1].len;
		}
		printf("Test case #%d\n",cas++);
		printf("Total explored area: %.2f\n",ans);
		puts("");
	}
    return 0;
}
