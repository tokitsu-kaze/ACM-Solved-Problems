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
const int MAX=1e4+10;
const ll mod=1e9+7;
bitset<MAX> bs[66],ans;
struct Segment_Tree
{
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qv;
	vector<int> res[MAX<<2];
	void build(int l,int r,int id)
	{
		res[id].clear();
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			res[id].pb(qv);
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void work(int l,int r,int id,int h)
	{
		bs[h]=bs[h-1];
		for(auto x:res[id]) bs[h]|=(bs[h]<<x);
		if(l==r)
		{
			ans|=bs[h];
			return ;
		}
		int mid=(l+r)>>1;
		work(l,mid,ls,h+1);
		work(mid+1,r,rs,h+1);
	}
}tr;
int main()
{
	int n,q,i;
	while(~scanf("%d%d",&n,&q))
	{
		tr.build(n);
		while(q--)
		{
			scanf("%d%d%d",&tr.ql,&tr.qr,&tr.qv);
			tr.update(1,n,1);
		}
		for(i=0;i<=64;i++) bs[i].reset();
		ans.reset();
		bs[0][0]=1;
		tr.work(1,n,1,1);
		vector<int> res;
		for(i=1;i<=n;i++)
		{
			if(ans[i]) res.pb(i);
		}
		printf("%d\n",sz(res));
		for(i=0;i<sz(res);i++) printf("%d%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}