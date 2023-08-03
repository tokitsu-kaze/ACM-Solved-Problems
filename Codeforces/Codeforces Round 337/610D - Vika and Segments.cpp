#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	ll l,r,h;
	int tag;
	friend bool operator <(node a,node b)
	{
		return a.h<b.h;
	}
}seg[MAX<<1];//线段 
ll x[MAX<<1];//横坐标离散化 
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	ll n,ql,qr,qv;
	ll cover[MAX<<3],len[MAX<<3];//注意这里要开8倍 
	void build(ll _n)
	{
		mem(cover,0);
		mem(len,0);
		n=_n;
	}
	void callen(int id,int l,int r)
	{
		if(cover[id]) len[id]=x[r+1]-x[l];//被整段覆盖
		else if(l==r) len[id]=0;//不是一条线段
		else len[id]=len[ls]+len[rs];//是一条线段但又没有被整段覆盖 
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			cover[id]+=qv;//覆盖情况
			callen(id,l,r);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		callen(id,l,r);
	}
}tree;
int main()
{
	int n,i,k,l,r,cnt;
	ll x1,y1,x2,y2,ans;
    while(~scanf("%d",&n)&&n)
    {
		k=0;
		mem(x,0);
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
			if(x1==x2)
			{
				x2++;
				if(y1>y2) swap(y1,y2);
				y2++;
			}
			else
			{
				y2++;
				if(x1>x2) swap(x1,x2);
				x2++;
			}
			x[k]=x1;
			seg[k].tag=-1; 
			seg[k].l=x1;
			seg[k].r=x2;
			seg[k++].h=y1;
			//上边界 
			x[k]=x2;
			seg[k].tag=1;
			seg[k].l=x1;
			seg[k].r=x2;
			seg[k++].h=y2;
			//下边界 
		}
		sort(seg,seg+k);//线段按纵坐标升序 
		sort(x,x+k);//横坐标升序
		cnt=unique(x,x+k)-x;
		tree.build(cnt-1);
		ans=0;
		for(i=0;i<k;i++)
		{
			if(i) ans+=(seg[i].h-seg[i-1].h)*tree.len[1];
			tree.ql=lower_bound(x,x+cnt-1,seg[i].l)-x;
			tree.qr=lower_bound(x,x+cnt-1,seg[i].r)-x-1;
			tree.qv=seg[i].tag;
			tree.update(0,cnt-1,1);
		}
		printf("%lld\n",ans);
	}
    return 0;
}