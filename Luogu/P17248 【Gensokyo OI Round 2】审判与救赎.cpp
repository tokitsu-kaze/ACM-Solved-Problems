#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
const int mod=998244353;
struct Discretization
{
	#define type int
	#define all(x) x.begin(),x.end()
	vector<type> a;
	void init(){a.clear();}
	void add(type x){a.push_back(x);}
	void work(){sort(all(a));a.resize(unique(all(a))-a.begin());}
	int get_pos(type x){return upper_bound(all(a),x)-a.begin();} // <= x
	type get_val(int pos){return a[pos-1];}
	int size(){return a.size();}
	#undef type
	#undef all
}d;
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
struct Persistent_Segment_Tree
{
	int root[MAX],ls[MAX<<5],rs[MAX<<5],tot,n;
	int cnt[MAX<<5],mul[MAX<<5],muladd[MAX<<5],cnt0[MAX<<5];
	void init(int _n)
	{
		n=_n;
		root[0]=0;
		ls[0]=rs[0]=cnt[0]=tot=cnt0[0]=0;
		mul[0]=muladd[0]=1;
	}
	int copy_node(int x)
	{
		++tot;
		ls[tot]=ls[x];
		rs[tot]=rs[x];
		cnt[tot]=cnt[x];
		mul[tot]=mul[x];
		muladd[tot]=muladd[x];
		cnt0[tot]=cnt0[x];
		return tot;
	}
	void update(int l,int r,int &id,int pre,int pos,int val,int val_add)
	{
		id=copy_node(pre);
		cnt[id]++;
		mul[id]=1LL*mul[id]*val%mod;
		if(val_add%mod==0) cnt0[id]++;
		else muladd[id]=1LL*muladd[id]*(val_add%mod)%mod;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) update(l,mid,ls[id],ls[pre],pos,val,val_add);
		else update(mid+1,r,rs[id],rs[pre],pos,val,val_add);
	}
	void create_ver(int now_ver,int pre_ver,int pos,int val)
	{
		root[now_ver]=0;
		update(1,n,root[now_ver],root[pre_ver],pos,val,val+1);
	}
	void copy_ver(int now_ver,int pre_ver)
	{
		root[now_ver]=root[pre_ver];
	}
	void query(int l,int r,int id,int pre,int k,int &resmul,int &res_muladd,int &res_cnt0)
	{
		if(k==0) return;
		if(cnt[id]-cnt[pre]==k)
		{
			resmul=1LL*resmul*mul[id]%mod*comb.inv(mul[pre])%mod;
			res_muladd=1LL*res_muladd*muladd[id]%mod*comb.inv(muladd[pre])%mod;
			res_cnt0+=cnt0[id]-cnt0[pre];
			return;
		}
		if(l==r)
		{
			int val=d.get_val(l)%mod;
			int val_add=(d.get_val(l)+1)%mod;
			resmul=1LL*resmul*comb.qpow(val,k)%mod;
			if(val_add==0) res_cnt0+=k;
			else res_muladd=1LL*res_muladd*comb.qpow(val_add,k)%mod;
			return;
		}
		int mid=(l+r)>>1;
		int lcnt=cnt[ls[id]]-cnt[ls[pre]];
		if(k<=lcnt) query(l,mid,ls[id],ls[pre],k,resmul,res_muladd,res_cnt0);
		else
		{
			resmul=1LL*resmul*mul[ls[id]]%mod*comb.inv(mul[ls[pre]])%mod;
			res_muladd=1LL*res_muladd*muladd[ls[id]]%mod*comb.inv(muladd[ls[pre]])%mod;
			res_cnt0+=cnt0[ls[id]]-cnt0[ls[pre]];
			query(mid+1,r,rs[id],rs[pre],k-lcnt,resmul,res_muladd,res_cnt0);
		}
	}
	vector<int> ask(int pre_ver,int now_ver,int k)
	{
		int resmul,res_muladd,res_cnt0;
		resmul=res_muladd=1;
		res_cnt0=0;
		query(1,n,root[now_ver],root[pre_ver],k,resmul,res_muladd,res_cnt0);
		return {resmul,res_muladd,res_cnt0};
	}
}tr;
/*
tr.init(n);
tr.create_ver(now_ver,pre_ver,pos,v);
tr.copy_ver(now_ver,pre_ver);
*/
int a[MAX];
int cnt0[MAX],cnt1[MAX],cnte[MAX],oddmod_cnt0[MAX];
ll mulodd[MAX],muleven[MAX];
int main()
{
	int n,q,i,l,r,k;
	ll ans;
	scanf("%d%d",&n,&q);
	d.init();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>0 && a[i]%2==0) d.add(a[i]);
	}
	d.work();
	tr.init(d.size());
	mulodd[0]=muleven[0]=1;
	for(i=1;i<=n;i++)
	{
		cnt1[i]=cnt1[i-1];
		cnte[i]=cnte[i-1];
		mulodd[i]=mulodd[i-1];
		muleven[i]=muleven[i-1];
		oddmod_cnt0[i]=oddmod_cnt0[i-1];
		cnt0[i]=cnt0[i-1];
		if(a[i]==0) cnt0[i]++;
		if(a[i]==1) cnt1[i]++;
		if(a[i]>0 && a[i]%2==0)
		{
			cnte[i]++;
			muleven[i]=muleven[i]*a[i]%mod;
			tr.create_ver(i,i-1,d.get_pos(a[i]),a[i]);
		}
		else tr.copy_ver(i,i-1);
		if(a[i]>1 && a[i]%2==1)
		{
			if(a[i]%mod==0) oddmod_cnt0[i]++;
			else mulodd[i]=mulodd[i]*(a[i]%mod)%mod;
		}
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		if(cnt0[r]-cnt0[l-1]==r-l+1 || oddmod_cnt0[r]-oddmod_cnt0[l-1]>0)
		{
			puts("0");
			continue;
		}
		ans=mulodd[r]%mod*comb.inv(mulodd[l-1])%mod;
		ans=ans*muleven[r]%mod*comb.inv(muleven[l-1])%mod;
		k=min(cnt1[r]-cnt1[l-1],cnte[r]-cnte[l-1]);
		if(k>0)
		{
			auto res=tr.ask(l-1,r,k);
			if(res[2]>0)
			{
				puts("0");
				continue;
			}
			ans=ans*res[1]%mod*comb.inv(res[0])%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
发现每个数分一组几乎比异或后再乘更好，除了 0 和 1。
无视 0。1 尽量分配给偶数，优先分配给小的，多余的 1 不用管。
因为如果奇数个 1，可以单独分一组；如果偶数个 1，可以分给某一组。
问题转化成，维护区间奇偶数之积，区间前 k 小的偶数之积，和偶数+1后奇数之积。
主席树随便维护一下，有一些细节。
感觉确实不太是题，思路简单，代码一坨。
*/

