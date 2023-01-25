#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<string> VS;
/************* define end  *************/
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr;
	type a[MAX],v[MAX<<2],tag[MAX<<2],qv;
	void pushup(int id)
	{
		v[id]=max(v[ls],v[rs]);
	}
	void pushdown(int id)
	{
		if(!tag[id]) return;
		tag[ls]+=tag[id];
		tag[rs]+=tag[id];
		v[ls]+=tag[id];
		v[rs]+=tag[id];
		tag[id]=0;
	}
	void build(int l,int r,int id)
	{
		tag[id]=v[id]=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(l,mid,ls);
		build(mid+1,r,rs);
		pushup(id);
	}
	void update(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			//do something
			v[id]+=qv;
			tag[id]+=qv;
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	type res;
	void query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr)
		{
			//do something
			res=max(res,v[id]);
			return;
		}
		pushdown(id);
		int mid=(l+r)>>1;
		if(ql<=mid) query(l,mid,ls);
		if(qr>mid) query(mid+1,r,rs);
	}
	void build(int _n){n=_n;build(1,n,1);}
	void upd(int l,int r,type v)
	{
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)//init res
	{
		ql=l;
		qr=r;
		res=0;
		query(1,n,1);
		return res;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
int l[MAX],r[MAX],tot,nn;
VI mp[MAX];
ll v[MAX],ans,dp[MAX];
void dfs1(int x,int fa,ll now)
{
	l[x]=++tot;
	now+=v[x];
	dp[x]=now;
	tr.upd(l[x],l[x],dp[x]);
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs1(to,x,now);
	}
	r[x]=tot;
}
void dfs(int x,int fa)
{
	ans=max(ans,tr.ask(1,nn)-v[x]);
/*	printf("%d\n",x);
	for(int i=1;i<=nn;i++) printf("%lld ",tr.ask(i,i));
	puts("");*/
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		tr.upd(1,nn,v[to]);
		tr.upd(l[to],r[to],-v[x]-v[to]);
		dfs(to,x);
		tr.upd(1,nn,-v[to]);
		tr.upd(l[to],r[to],v[x]+v[to]);
	}
}
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
    	int i;
    	nn=n;
        for(i=1;i<=n;i++)
        {
        	mp[i].clear();
        	v[i]=price[i-1];
		}
        for(auto &it:edges)
        {
        	mp[it[0]+1].pb(it[1]+1);
        	mp[it[1]+1].pb(it[0]+1);
		}
		tr.build(nn);
		tot=0;
		dfs1(1,0,0);
		ans=0;
		dfs(1,0);
		return ans;
    }
};
/*
7 15 24 21 31 26
dp[x]+v[to] -v[x] -v[x] -v[x] 
*/
