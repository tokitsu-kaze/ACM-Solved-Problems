#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e4+10;
struct Block
{
	#define type ll
	static const int N=MAX;
	static const int SZ=sqrt(N);
	static const int B=N/SZ+10;
	int n,bl[B],br[B],bid[N];
	type a[N],sum[B],tag[B];
	void build(int _n)
	{
		int i,j,id;
		n=_n;
		id=0;
		for(i=1;i<=n;i+=SZ)
		{
			bl[++id]=i;
			br[id]=min(n,i+SZ-1);
			tag[id]=0;
			for(j=bl[id];j<=br[id];j++)
			{
				bid[j]=id;
				sum[id]+=a[j];
			}
		}
	}
	void pushdown(int id)
	{
		int i;
		if(tag[id])
		{
			for(i=bl[id];i<=br[id];i++) a[i]+=tag[id];
			tag[id]=0;
		}
	}
	void upd_point(int x,type v)
	{
		a[x]+=v;
		sum[bid[x]]+=v;
	}
	void upd_block(int id,type v)
	{
		sum[id]+=(br[id]-bl[id]+1)*v;
		tag[id]+=v;
	}
	void upd(int l,int r,type v)
	{
		int i;
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
int main()
{
	int n,i,op,l,r,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&blk.a[i]);
	blk.build(n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&op,&l,&r,&x);
		if(op==0) blk.upd(l,r,x);
		else printf("%lld\n",blk.ask(r,r));
	}
	return 0;
}
