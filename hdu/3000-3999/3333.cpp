////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-09 16:20:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3333
////Problem Title: 
////Run result: Accept
////Run time:795MS
////Run memory:26372KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e4+10;
const ll mod=1e9+7;
struct node
{
	int l,r,sum;
	ll s;
}tree[40*MAX];
int root[MAX],tot;
void insert(int l,int r,int &id,int pre,int pos,int v,ll vs)
{
	int mid;
	tree[++tot]=tree[pre];
	tree[tot].sum+=v;
	tree[tot].s+=vs;
	id=tot;
	if(l==r) return;
	mid=(l+r)/2;
	if(mid>=pos) insert(l,mid,tree[id].l,tree[pre].l,pos,v,vs);
	else insert(mid+1,r,tree[id].r,tree[pre].r,pos,v,vs);
}
ll query(int l,int r,int id,int pos)  
{
	int mid;
	if(l>=pos) return tree[id].s;  
	mid=(l+r)>>1;  
	if(mid>=pos) return query(l,mid,tree[id].l,pos)+tree[tree[id].r].s;
	else return query(mid+1,r,tree[id].r,pos);
}
ll a[MAX];
map<ll,ll> last;
int main()
{
	int t,i,q,l,r,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		root[0]=0;
		tree[0].l=tree[0].r=tree[0].sum=0;
		tree[0].s=0;
		tot=0;
		last.clear();
		for(i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			if(!last[a[i]]) insert(1,n,root[i],root[i-1],i,1,a[i]);
			else
			{
				int temp;
				insert(1,n,temp,root[i-1],last[a[i]],-1,-a[i]);
				insert(1,n,root[i],temp,i,1,a[i]);
			}
			last[a[i]]=i;
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&l,&r);
			printf("%I64d\n",query(1,n,root[r],l));
		}
	}
	return 0;
}
/*
2
3
1 1 4
2
1 2
2 3
5
1 1 2 1 3
3
1 5
2 4
3 5
*/