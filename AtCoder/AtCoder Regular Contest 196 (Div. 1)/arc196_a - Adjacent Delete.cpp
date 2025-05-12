#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct Treap
{
	#define type ll
	static const type inf=LLINF;
	struct node
	{
		int ch[2],fix,sz,cnt;
		type v,sum;
		node(){}
		node(type x,int _sz)
		{
			sum=v=x;
			fix=rand();
			sz=cnt=_sz;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];
	int tot,root[MAX],rt;
	void init(int n=1)
	{
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
		srand(time(0));
		tot=0;
		t[0].sz=t[0].cnt=0;
		memset(t[0].ch,0,sizeof t[0].ch);
	}
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ch[0]].sz+t[t[id].ch[1]].sz+t[id].cnt;
		t[id].sum=t[t[id].ch[0]].sum+t[t[id].ch[1]].sum+t[id].v*t[id].cnt;
	}
	void rotate(int &id,int k)
	{
		int y=t[id].ch[k^1];
		t[id].ch[k^1]=t[y].ch[k];
		t[y].ch[k]=id;
		pushup(id);
		pushup(y);
		id=y;
	}
	void _insert(int &id,type v,int cnt)
	{
		if(!id)
		{
			id=++tot;
			t[id]=node(v,cnt);
			return;
		}
		if(t[id].v==v)
		{
			t[id].cnt+=cnt;
			t[id].sum+=t[id].v*cnt;
		}
		else
		{
			int tmp=(v>t[id].v);
			_insert(t[id].ch[tmp],v,cnt);
			if(t[t[id].ch[tmp]].fix>t[id].fix) rotate(id,tmp^1);
		}
		pushup(id);
	}
	void _erase(int &id,type v,int cnt)
	{
		if(!id) return;
		if(t[id].v==v)
		{
			cnt=min(t[id].cnt,cnt);
			if(t[id].cnt>cnt)
			{
				t[id].cnt-=cnt;
				t[id].sum-=t[id].v*cnt;
				pushup(id);
				return;
			}
			if(!(t[id].ch[0]&&t[id].ch[1]))
			{
				id=t[id].ch[0]+t[id].ch[1];
				return;
			}
			else
			{
				int tmp=(t[t[id].ch[0]].fix>t[t[id].ch[1]].fix);
				rotate(id,tmp);
				_erase(t[id].ch[tmp],v,cnt);
				pushup(id);
			}
		}
		else
		{
			_erase(t[id].ch[v>t[id].v],v,cnt);
			pushup(id);
		}
	}
	type kth_sum(int k)//k small
	{
		type res=0;
		int id=root[rt];
		if(id==0) return 0;
		while(id)
		{
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k)
			{
				res+=t[t[id].ch[0]].sum;
				k-=t[t[id].ch[0]].sz;
				res+=t[id].v*k;
				return res;
			}
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
				res+=t[t[id].ch[0]].sum+t[id].v*t[id].cnt;
				id=t[id].ch[1];
			}
		}
		return 0;
	}
	void insert(type v,int sz=1){_insert(root[rt],v,sz);}
	void erase(type v,int sz=1){_erase(root[rt],v,sz);}
	int size(){return t[root[rt]].sz;}
	#undef type
}tr;
int a[MAX];
ll pre[MAX],suf[MAX];
int main()
{
	int n,i;
	ll sum,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	tr.init();
	sum=0;
	pre[0]=0;
	for(i=1;i<=n;i++)
	{
		tr.insert(a[i]);
		sum+=a[i];
		if(!(i&1)) pre[i]=sum-2*tr.kth_sum(i/2);
	}
	if(!(n&1)) return 0*printf("%lld\n",pre[n]);
	tr.init();
	sum=0;
	suf[n+1]=0;
	for(i=n;i;i--)
	{
		tr.insert(a[i]);
		sum+=a[i];
		if((n-i)&1) suf[i]=sum-2*tr.kth_sum((n-i+1)/2);
	}
	ans=0;
	for(i=1;i<=n;i+=2) ans=max(ans,pre[i-1]+suf[i+1]);
	printf("%lld\n",ans);
	return 0;
}
