#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Block
{
	#define type ll
	static const int N=MAX;
	static const int SZ=sqrt(N);
	static const int B=N/SZ+5;
	int n,bl[B],br[B],bid[N];
	type a[N],tag[B],res[B][SZ+5];
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
				res[id][j-bl[id]]=a[j];
			}
			sort(res[id],res[id]+br[id]-bl[id]+1);
		}
	}
	void pushdown(int id)
	{
		int i;
		if(tag[id])
		{
			for(i=bl[id];i<=br[id];i++)
			{
				a[i]+=tag[id];
				res[id][i-bl[id]]+=tag[id];
			}
			tag[id]=0;
		}
	}
	void upd_point(int x,type v)
	{
		a[x]+=v;
	}
	void upd_block(int id,type v)
	{
		tag[id]+=v;
	}
	void upd(int l,int r,type v)
	{
		int i;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) upd_point(i,v);
	    	for(i=bl[bid[l]];i<=br[bid[l]];i++)
	    	{
	    		res[bid[l]][i-bl[bid[l]]]=a[i];
			}
			sort(res[bid[l]],res[bid[l]]+br[bid[l]]-bl[bid[l]]+1);
	    	return;
		}
		pushdown(bid[l]);
		for(i=l;i<=br[bid[l]];i++) upd_point(i,v);
		for(i=bl[bid[l]];i<=br[bid[l]];i++)
    	{
    		res[bid[l]][i-bl[bid[l]]]=a[i];
		}
		sort(res[bid[l]],res[bid[l]]+br[bid[l]]-bl[bid[l]]+1);
    	
		pushdown(bid[r]);
		for(i=bl[bid[r]];i<=r;i++) upd_point(i,v);
		for(i=bl[bid[r]];i<=br[bid[r]];i++)
    	{
    		res[bid[r]][i-bl[bid[r]]]=a[i];
		}
		sort(res[bid[r]],res[bid[r]]+br[bid[r]]-bl[bid[r]]+1);
    	
		for(i=bid[l]+1;i<=bid[r]-1;i++) upd_block(i,v);
	}
	type ans,qv;
	void ask_point(int x)
	{
		if(a[x]>=qv) ans++;
	}
	void ask_block(int id)
	{
		int len=br[id]-bl[id]+1;
		ans+=len;
		ans-=lower_bound(res[id],res[id]+len,qv-tag[id])-res[id];
	}
	type ask(int l,int r,type v)
	{
	    int i;
	    qv=v;
	    ans=0;
	    if(bid[l]==bid[r])
	    {
	    	pushdown(bid[l]);
	    	for(i=l;i<=r;i++) ask_point(i);
	    	return ans;
		}
		pushdown(bid[l]);
		pushdown(bid[r]);
		for(i=l;i<=br[bid[l]];i++) ask_point(i);
		for(i=bl[bid[r]];i<=r;i++) ask_point(i);
		for(i=bid[l]+1;i<=bid[r]-1;i++) ask_block(i);
		return ans;
	}
	#undef type
}blk;
int main()
{
	int n,q,i,l,r,x;
	char op[2];
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%lld",&blk.a[i]);
	blk.build(n);
	while(q--)
	{
		scanf("%s%d%d%d",op,&l,&r,&x);
		if(op[0]=='M') blk.upd(l,r,x);
		else printf("%d\n",blk.ask(l,r,x));
	}
	return 0;
}
