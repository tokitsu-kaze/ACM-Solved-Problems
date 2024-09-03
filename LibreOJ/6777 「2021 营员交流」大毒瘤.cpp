#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Block
{
	#define type ll
	static const int N=MAX;
	static const int SZ=sqrt(N);
	static const int B=N/SZ+10;
	int n,bl[B],br[B],bid[N];
	int cnt[B],qop,vis[N];
	type a[N],sum[B],tag[B];
	void init(int _n)
	{
		int i,j,id;
		n=_n;
		id=0;
		for(i=1;i<=n;i+=SZ)
		{
			bl[++id]=i;
			br[id]=min(n,i+SZ-1);
			tag[id]=0;
			cnt[id]=br[id]-bl[id]+1;
			for(j=bl[id];j<=br[id];j++)
			{
				bid[j]=id;
				sum[id]+=a[j];
				vis[j]=1;
			}
		}
	}
	void pushdown(int id)
	{
		int i;
		if(tag[id])
		{
			for(i=bl[id];i<=br[id];i++)
			{
				if(vis[i]) a[i]+=tag[id];
			}
			tag[id]=0;
		}
	}
	void upd_point(int x,type v)
	{
		if(qop==1)
		{
			if(v==-1)
			{
				sum[bid[x]]-=a[x];
				a[x]=0;
				cnt[bid[x]]-=vis[x];
				vis[x]=0;
			}
			else
			{
				if(!vis[x])
				{
					cnt[bid[x]]++;
					vis[x]=1;
				}
			}
		}
		else
		{
			if(vis[x])
			{
				sum[bid[x]]+=v;
				a[x]+=v;
			}
		}
	}
	void upd_block(int id,type v)
	{
		sum[id]+=cnt[id]*v;
		tag[id]+=v;
	}
	void upd(int l,int r,type v,int op)
	{
		int i;
		qop=op;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) upd_point(i,v);
	    	return;
		}
		pushdown(bid[l]);
		pushdown(bid[r]);
		for(i=l;i<=br[bid[l]];i++) upd_point(i,v);
		for(i=bl[bid[r]];i<=r;i++) upd_point(i,v);
		for(i=bid[l]+1;i<=bid[r]-1;i++) upd_block(i,v);
	}
	type res;
	void ask_point(int x)
	{
		res+=a[x];
	}
	void ask_block(int id)
	{
		res+=sum[id];
	}
	type ask(int l,int r)
	{
	    int i;
	    res=0;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) ask_point(i);
	    	return res;
		}
		pushdown(bid[l]);
		pushdown(bid[r]);
		for(i=l;i<=br[bid[l]];i++) ask_point(i);
		for(i=bl[bid[r]];i<=r;i++) ask_point(i);
		for(i=bid[l]+1;i<=bid[r]-1;i++) ask_block(i);
		return res;
	}
	#undef type
}blk;
struct Fire
{
	struct seg{int l,r;}a[MAX],tmp[MAX];
	int tot,n;
	void init(int _n){n=_n;tot=0;}
	void insert(int x)
	{
		int i,cnt,ok;
		for(i=0;i<tot;i++)
		{
			if(x>=a[i].l && x<=a[i].r) return;
		}
		blk.upd(x,x,-1,1);
		cnt=ok=0;
		for(i=0;i<tot;i++)
		{
			tmp[cnt++]=a[i];
			if(ok) continue;
			if(x==tmp[cnt-1].l-1)
			{
				tmp[cnt-1].l--;
				ok=1;
			}
			else if(x==tmp[cnt-1].r+1)
			{
				tmp[cnt-1].r++;
				ok=1;
			}
			else if(x<a[i].l)
			{
				tmp[cnt-1]={x,x};
				tmp[cnt++]=a[i];
				ok=1;
			}
		}
		if(!ok) tmp[cnt++]={x,x};
		for(i=0;i<cnt;i++) a[i]=tmp[i];
		tot=cnt;
	}
	void erase(int l,int r)
	{
		int i,j,cnt,ll,rr;
		cnt=0;
		for(i=0;i<tot;i++)
		{
			ll=max(l,a[i].l);
			rr=min(r,a[i].r);
			if(ll>rr)
			{
				tmp[cnt++]=a[i];
				continue;
			}
//			blk.upd(ll,rr,1,1);
			for(j=ll;j<=rr;j++) blk.upd(j,j,1,1);
			if(ll==a[i].l && rr==a[i].r) continue;
			if(ll>a[i].l) tmp[cnt++]={a[i].l,ll-1};
			if(rr<a[i].r) tmp[cnt++]={rr+1,a[i].r};
		}
		for(i=0;i<cnt;i++) a[i]=tmp[i];
		tot=cnt;
	}
	void spread()
	{
		int i,cnt;
		cnt=0;
		for(i=0;i<tot;i++)
		{
			a[i].l=max(1,a[i].l-1);
			a[i].r=min(n,a[i].r+1);
			blk.upd(a[i].l,a[i].l,-1,1);
			blk.upd(a[i].r,a[i].r,-1,1);
			if(cnt && a[i].l<=tmp[cnt-1].r) tmp[cnt-1].r=a[i].r;
			else tmp[cnt++]=a[i];
		}
		for(i=0;i<cnt;i++) a[i]=tmp[i];
		tot=cnt;
	}
	void debug()
	{
		printf("%d\n",tot);
		for(int i=0;i<tot;i++) printf("%d %d\n",a[i].l,a[i].r);
	}
}fr;
int main()
{
	int n,q,op,l,r,k,x,i;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&blk.a[i]);
	blk.init(n);
	fr.init(n);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d",&l,&r,&k);
			blk.upd(l,r,k,2);
		}
		else if(op==2)
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",blk.ask(l,r));
		}
		else if(op==3)
		{
			scanf("%d",&x);
			fr.insert(x);
		}
		else
		{
			scanf("%d%d",&l,&r);
			fr.erase(l,r);
		}
		fr.spread();
//		fr.debug();
	}
	return 0;
}
