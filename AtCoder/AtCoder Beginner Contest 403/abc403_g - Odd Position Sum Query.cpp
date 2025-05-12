#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct FHQ_Treap
{
	#define type ll
	static const type inf=INF;
	struct node
	{
		int ls,rs,fix,sz,cnt;
		type v,sum[2];
		node(){}
		node(type x,int _sz)
		{
			v=x;
			fix=rand();
			sz=cnt=_sz;
			ls=rs=0;
			sum[0]=sum[1]=0;
			sum[1]=x;
		}
	}t[MAX];
	int rt,tot;
	void init()
	{
		rt=0;
		srand(time(0));
		tot=0;
		t[0].sz=t[0].cnt=0;
		t[0].ls=t[0].rs=0;
	}
	int newnode(type v,int sz)
	{
		t[++tot]=node(v,sz);
		return tot;
	}
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ls].sz+t[t[id].rs].sz+t[id].cnt;
		t[id].sum[0]=t[t[id].ls].sum[0];
		t[id].sum[1]=t[t[id].ls].sum[1];
		if(t[t[id].ls].sz&1)
		{
			t[id].sum[0]+=(t[id].cnt+1)/2*t[id].v;
			t[id].sum[1]+=t[id].cnt/2*t[id].v;
		}
		else
		{
			t[id].sum[1]+=(t[id].cnt+1)/2*t[id].v;
			t[id].sum[0]+=t[id].cnt/2*t[id].v;
		}
		if((t[t[id].ls].sz+t[id].cnt)&1)
		{
			t[id].sum[0]+=t[t[id].rs].sum[1];
			t[id].sum[1]+=t[t[id].rs].sum[0];
		}
		else
		{
			t[id].sum[1]+=t[t[id].rs].sum[1];
			t[id].sum[0]+=t[t[id].rs].sum[0];
		}
	}
	void split(int id,type v,int &x,int &y)
	{
		if(!id)
		{
			x=y=0;
			return;
		}
		if(t[id].v<=v)
		{
			x=id;
			split(t[id].rs,v,t[id].rs,y);
		}
		else
		{
			y=id;
			split(t[id].ls,v,x,t[id].ls);
		}
		pushup(id);
	}
	int merge(int x,int y)
	{
		if(!x||!y) return x|y;
		if(t[x].fix<t[y].fix)
		{
			t[x].rs=merge(t[x].rs,y);
			pushup(x);
			return x;
		}
		else
		{
			t[y].ls=merge(x,t[y].ls);
			pushup(y);
			return y;
		}
	}
	void insert(type v,int sz=1)
	{
		int ra,rb,rc;
		split(rt,v,ra,rc);
		split(ra,v-1,ra,rb);
		if(!rb) rb=newnode(v,sz);
		else
		{
			t[rb].cnt+=sz;
			t[rb].sz+=sz;
			t[rb].sum[0]=t[rb].cnt/2*v;
			t[rb].sum[1]=(t[rb].cnt+1)/2*v;
		}
		rt=merge(merge(ra,rb),rc);
	}
	#undef type
}tr;
const int mod=1e9;
int main()
{
	int q,y;
	ll ans;
	scanf("%d",&q);
	tr.init();
	ans=0;
	while(q--)
	{
		scanf("%d",&y);
		tr.insert((ans+y)%mod+1);
		ans=tr.t[tr.rt].sum[1];
		printf("%lld\n",ans);
	}
	return 0;
}
