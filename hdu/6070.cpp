////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-09 22:30:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6070
////Problem Title: 
////Run result: Accept
////Run time:2449MS
////Run memory:3720KB
//////////////////System Comment End//////////////////
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
const double eps=1e-4;
const int MAX=6e4+10;
const ll mod=1e9+7;
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qv,tag[MAX<<2];
	double v[MAX<<2],m;
	void pushup(int id)
	{
		v[id]=min(v[ls],v[rs]);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		v[ls]+=tag[id];
		v[rs]+=tag[id];
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		v[id]=1e15;
		if(l==r)
		{
			v[id]=l*m;
			return;
		}
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			v[id]+=qv;
			tag[id]+=qv;
			return ;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	double query(int l,int r,int id)
	{
		double res=1e15;
		if(l>=ql&&r<=qr) return v[id];
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) res=min(res,query(l,mid,ls));
		if(qr>mid) res=min(res,query(mid+1,r,rs));
		return res;
	}
	void build(int _n,double md){n=_n;m=md;build(1,n,1);}
	
}tree;
int sgn(double x)
{  
	if(fabs(x)<1e-6) return 0;
	else return x>0?1:-1;  
}
int a[MAX],pos[MAX];
int main()
{
	int t,n,i,flag;
	double l,r,mid,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		l=0;
		r=1;
		while(r-l>eps)
		{
			mid=(l+r)/2;
			tree.build(n,mid);
			mem(pos,0);
			flag=0;
			for(i=1;i<=n;i++)
			{
				tree.ql=pos[a[i]]+1;
				tree.qr=i;
				tree.qv=1;
				tree.update(1,n,1);
				tree.ql=1;
				res=tree.query(1,n,1);
				if(sgn(res-(i+1)*mid)<=0)
				{
					flag=1;
					break;
				}
				pos[a[i]]=i;
			}
			if(!flag) l=mid;
			else r=mid;
		}
		printf("%.6lf\n",l);
	}
	return 0;
}