#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
struct Combinatorics
{
	vector<int> inv_e,fac,invfac;
	int last_n;
	Combinatorics(){last_n=0;}
	void init(int n)
	{
		if(n<=last_n) return;
		inv_e.resize(n+1);
		fac.resize(n+1);
		invfac.resize(n+1);
		if(last_n==0)
		{
			inv_e[1]=1;
			fac[0]=fac[1]=1;
			invfac[0]=invfac[1]=1;
			last_n=1;
		}
		for(int i=last_n+1;i<=n;i++)
		{
			inv_e[i]=1LL*(mod-mod/i)*inv_e[mod%i]%mod;
			fac[i]=1LL*fac[i-1]*i%mod;
			invfac[i]=1LL*invfac[i-1]*inv_e[i]%mod;
		}
		last_n=n;
	}
	ll qpow(ll a,ll b)
	{
		ll res=1;
		while(b>0)
		{
			if(b&1) res=res*a%mod;
			a=a*a%mod;
			b>>=1;
		}
		return res;
	}
	ll inv(int x)
	{
		if(x<=last_n) return inv_e[x];
		else return qpow(x,mod-2);
	}
	ll C(int n,int m)
	{
		if(m>n||m<0||n<0) return 0;
		return 1LL*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
	}
	ll A(int n,int m)
	{
		if(m>n||m<0||n<0) return 0;
		return 1LL*fac[n]*invfac[n-m]%mod;
	}
}comb;
struct Segment_Tree
{
	#define type ll
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tagadd[MAX<<2],tagmul[MAX<<2],qv;
	struct node
	{
		type v;
		void init(){v=0;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.v=(x.v+y.v)%mod;
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void maintain_mul(int l,int r,int id,type qv)
	{
		t[id].v=t[id].v*qv%mod;
		tagadd[id]=tagadd[id]*qv%mod;
		tagmul[id]=tagmul[id]*qv%mod;
	}
	void maintain_add(int l,int r,int id,type qv)
	{
		t[id].v=(t[id].v+(r-l+1)*qv)%mod;
		tagadd[id]=(tagadd[id]+qv)%mod;
	}
	void pushdown(int l,int r,int id)
	{
		int mid=(l+r)>>1;
		if(tagmul[id]!=1)
		{
			maintain_mul(l,mid,ls,tagmul[id]);
			maintain_mul(mid+1,r,rs,tagmul[id]);
			tagmul[id]=1;
		}
		if(tagadd[id]!=0)
		{
			maintain_add(l,mid,ls,tagadd[id]);
			maintain_add(mid+1,r,rs,tagadd[id]);
			tagadd[id]=0;
		}
	}
	void build(int l,int r,int id)
	{
		tagmul[id]=1;
		tagadd[id]=0;
		t[id].init();
		if(l==r)
		{
			//init
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
			if(qop==1) maintain_mul(l,r,id,qv);
			else maintain_add(l,r,id,qv);
			return;
		}
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(ql<=mid) update(l,mid,ls);
		if(qr>mid) update(mid+1,r,rs);
		pushup(id);
	}
	node query(int l,int r,int id)
	{
		if(l>=ql&&r<=qr) return t[id];
		pushdown(l,r,id);
		int mid=(l+r)>>1;
		if(qr<=mid) return query(l,mid,ls);
		if(ql>mid) return query(mid+1,r,rs);
		return merge_node(query(l,mid,ls),query(mid+1,r,rs));
	}
	void build(int _n)
	{
		n=_n;
		build(1,n,1);
		null_node.init();
	}
	void upd(int l,int r,type v,int op)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		qop=op;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.v;
		ql=l;
		qr=r;
		return query(1,n,1).v;
	}
	#undef type
	#undef ls
	#undef rs
}tr;
/*
tr.build(n);
tr.upd(l,r,v);
tr.ask(l,r);
Segment_Tree::node res=tr.merge_node(nodex,nodey);
*/
int a[MAX],b[MAX];
int main()
{
	int n,k,i,j;
	ll ans,sc,fail,nowfail;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	tr.build(n);
	nowfail=1;
	ans=0;
	for(i=1;i<=n;i++)
	{
		sc=a[i]*comb.inv(b[i])%mod;
		fail=(1-sc+mod)%mod;
		tr.upd(i,i,nowfail,2);
		nowfail=tr.ask(max(1,i-k+1),i)*fail%mod;
		tr.upd(1,i,sc,1);
		if(1<=i-k+1) ans=(ans+tr.ask(i-k+1,i-k+1))%mod;
//		printf("%d\n",i);
//		for(j=1;j<=i;j++) printf("%lld%c",tr.ask(j,j)," \n"[j==i]);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
dp[i][j] 表示到 i 连续 j 个成功的概率。
dp[i][j]=dp[i-1][j-1]*sc
dp[i][0]=sum{dp[i-1][0..k-1]}*fail
ans+=dp[i][k]
*/
