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
const int MAX=100000+10; //MAXΪ�����С
struct node
{
	//l,rΪ����ڵ��ŵ���������Ҷ˵�
	//midΪ�е�
	//sumΪ��������������ĺ�
	//tagΪ�ӳٱ��(���������) 
	ll l,r,mid,sum,tag;
	
	//���캯�� ����ʱ��ʼ���ṹ�� 
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

//�ݹ齨�� 
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
	build(l,mid,id<<1);//id<<1 �൱�� id*2 
	build(mid+1,r,id<<1|1);//id<<1|1 �൱�� id*2+1
	//��˷ʱ����
	tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
}
//�·Ų��� 
void pushdown(ll id)
{
	tree[id<<1].tag+=tree[id].tag;
	tree[id<<1|1].tag+=tree[id].tag;
	tree[id<<1].sum+=(tree[id<<1].r-tree[id<<1].l+1)*tree[id].tag;
	tree[id<<1|1].sum+=(tree[id<<1|1].r-tree[id<<1|1].l+1)*tree[id].tag;
	tree[id].tag=0;//�·���� ��ձ�� 
}

void update(ll l,ll r,ll id,ll v)
{
	ll mid;
	//����[l,r]��ȫ��������[tree[id].l,tree[id].r]
	//������¸�Ϊ if(l==tree[id].l&&r==tree[id].r)
	if(l<=tree[id].l&&r>=tree[id].r)
	{
		tree[id].sum+=(tree[id].r-tree[id].l+1)*v;
		tree[id].tag+=v;//�ӳٱ�� 
		return;
	}
	if(tree[id].tag) pushdown(id);//�·Ų��� 
	mid=tree[id].mid;
	if(r<=mid) update(l,r,id<<1,v);//������������ 
	else if(l>=mid+1) update(l,r,id<<1|1,v);//������������
	else//������������
	{
		update(l,mid,id<<1,v);
		update(mid+1,r,id<<1|1,v);
	}
	//��˷ʱ����sum 
	tree[id].sum=tree[id<<1].sum+tree[id<<1|1].sum;
}
ll query(ll l,ll r,ll id)
{
	ll mid;
	if(l==tree[id].l&&r==tree[id].r)
	{
		return tree[id].sum;
	}
	if(tree[id].tag) pushdown(id);//�·� 
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