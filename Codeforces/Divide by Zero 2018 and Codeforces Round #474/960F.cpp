#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
struct Segment_Tree
{
	int root[MAX],tot,ls[MAX*20],rs[MAX*20],v[MAX*20],ql,qr,qv;
	void init()
	{
		mem(root,0);
		ls[0]=rs[0]=0;
		v[0]=0; 
		tot=1;
	}
	int newnode()
	{
		ls[tot]=rs[tot]=0;
		v[tot]=0;
		return tot++;
	}
	void pushup(int id)
	{
		v[id]=max(v[ls[id]],v[rs[id]]);
	}
	void insert(int l,int r,int &id,int pos)
	{
		int mid;
		if(!id) id=newnode();
		if(l==r)
		{
			v[id]=max(v[id],qv);
			return;
		}
		mid=(l+r)>>1;
		if(pos<=mid) insert(l,mid,ls[id],pos);
		else if(pos>=mid+1) insert(mid+1,r,rs[id],pos);
		pushup(id);
	}
	int query(int l,int r,int id)
	{
		int mid,res=0;
		if(!id) return 0;
		if(l>=ql&&r<=qr) return v[id];
		mid=(l+r)>>1;
		if(ql<=mid) res=max(res,query(l,mid,ls[id]));
		if(qr>mid) res=max(res,query(mid+1,r,rs[id]));
		pushup(id);
		return res;
	}
}tr; 
int main()
{
	int n,m,i,a,b,c,ans;
	while(~scanf("%d%d",&n,&m))
	{
		tr.init();
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			tr.ql=1;
			tr.qr=c;
			tr.qv=tr.query(1,100001,tr.root[a])+1;
			tr.insert(1,100001,tr.root[b],c+1);
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			ans=max(ans,tr.v[tr.root[i]]); 
		}
		printf("%d\n",ans);
	}
	return 0;
}