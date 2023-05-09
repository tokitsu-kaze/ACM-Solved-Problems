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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=100000+10; //MAX为数组大小
struct node
{
	//l,r为这个节点存放的区域的左右端点
	//mid为中点
	//sum为这个区域所有数的和
	//tag为延迟标记(区间更新用) 
	ll l,r,mid,sum,tag;
	
	//构造函数 调用时初始化结构体 
	node(){}
	node(ll a,ll b)
	{
		l=a;
		r=b;
		sum=0;
		tag=0;
		mid=(l+r)>>1;
	}
}tree[4*MAX];

//递归建树 
ll a[MAX];
void build(ll l,ll r,ll id)
{
	ll mid;
	tree[id]=node(l,r);
	if(l==r)
	{ 
		tree[id].sum=a[l];
		return;
	}
	mid=tree[id].mid;
	build(l,mid,id<<1);//id<<1 相当于 id*2 
	build(mid+1,r,id<<1|1);//id<<1|1 相当于 id*2+1
	//回朔时更新
	tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
}
//下放操作 
void pushdown(ll id)
{
	tree[id<<1].tag+=tree[id].tag;
	tree[id<<1|1].tag+=tree[id].tag;
	tree[id<<1].sum+=(tree[id<<1].r-tree[id<<1].l+1)*tree[id].tag;
	tree[id<<1|1].sum+=(tree[id<<1|1].r-tree[id<<1|1].l+1)*tree[id].tag;
	tree[id].tag=0;//下放完成 清空标记 
}

void update(ll l,ll r,ll id,ll v)
{
	ll mid;
	//区间[l,r]完全覆盖区间[tree[id].l,tree[id].r]
	//单点更新改为 if(l==tree[id].l&&r==tree[id].r)
	if(l<=tree[id].l&&r>=tree[id].r)
	{
		tree[id].sum+=(tree[id].r-tree[id].l+1)*v;
		tree[id].tag+=v;//延迟标记 
		return;
	}
	if(tree[id].tag) pushdown(id);//下放操作 
	mid=tree[id].mid;
	if(r<=mid) update(l,r,id<<1,v);//往左子树更新 
	else if(l>=mid+1) update(l,r,id<<1|1,v);//往右子树更新
	else//左右子树更新
	{
		update(l,mid,id<<1,v);
		update(mid+1,r,id<<1|1,v);
	}
	//回朔时更新sum 
	tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
}
ll query(ll l,ll r,ll id)
{
	ll mid;
	if(l==tree[id].l&&r==tree[id].r)
	{
		return tree[id].sum;
	}
	if(tree[id].tag) pushdown(id);//下放 
	mid=tree[id].mid;
	if(r<=mid) return query(l,r,id<<1);
	else if(l>=mid+1) return query(l,r,id<<1|1);
	else return query(l,mid,id<<1)+query(mid+1,r,id<<1|1);
}
int main()
{
    ll n,q,i,l,r,v;
    char op[11];
    while(~scanf("%lld%lld",&n,&q))
    {
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		build(1,n,1);
		while(q--)
		{
			scanf("%s%lld%lld",op,&l,&r);
			if(op[0]=='Q') printf("%lld\n",query(l,r,1));
			else
			{
				scanf("%lld",&v);
				update(l,r,1,v);
			}
		}
	}
    return 0;
}
/*
5 100
1 2 3 4 5
C 1 5 1
C 1 4 1
C 2 5 1
Q 1 5
Q 1 1
Q 2 2
Q 3 3
Q 4 4
Q 5 5
Q 1 5
*/