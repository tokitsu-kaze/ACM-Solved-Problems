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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
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
	freopen("Billboard.in","r",stdin);
	freopen("Billboard.out","w",stdout);	
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