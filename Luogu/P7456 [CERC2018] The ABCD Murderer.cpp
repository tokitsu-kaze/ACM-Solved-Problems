#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
struct Segment_Tree
{
	#define type int
	static const type inf=INF;
	#define ls (id<<1)
	#define rs (id<<1|1)
	int n,ql,qr,qop;
	type a[MAX],tag[MAX<<2],qv;
	struct node
	{
		type mn;
		void init(){mn=inf;}
	}t[MAX<<2],null_node;
	node merge_node(node x,node y)
	{
		node res;
		res.mn=min(x.mn,y.mn);
		return res;
	}
	void pushup(int id){t[id]=merge_node(t[ls],t[rs]);}
	void pushdown(int l,int r,int id)
	{
		if(!tag[id]) return;
		int mid=(l+r)>>1;
		
	}
	void build(int l,int r,int id)
	{
		tag[id]=0;
		t[id].init();
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
			t[id].mn=min(t[id].mn,qv);
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
	void upd(int l,int r,type v)
	{
		if(l>r) return;
		ql=l;
		qr=r;
		qv=v;
		update(1,n,1);
	}
	type ask(int l,int r)
	{
		if(l>r) return null_node.mn;
		ql=l;
		qr=r;
		return query(1,n,1).mn;
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
struct AC_Automaton
{
	static const int K=26;
	int nex[MAX][K],fail[MAX],cnt[MAX],last[MAX];
	int root,tot,pos[MAX],mxlen[MAX];
	int getid(char c){return c-'a';}//may need change
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0;
		cnt[tot]=0;
		mxlen[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s,int n,int x) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
		}
		cnt[now]++;
		pos[x]=now;
		mxlen[now]=n;
	}
	void work()
	{
		int i,now;
		queue<int> q;
		for(i=0;i<K;i++)
		{
			if(nex[root][i]) q.push(nex[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			
			//suffix link
			if(cnt[fail[now]]) last[now]=fail[now];
			else last[now]=last[fail[now]];
			mxlen[now]=max(mxlen[now],mxlen[fail[now]]);
			
			for(i=0;i<K;i++)
			{
				if(nex[now][i])
				{
					fail[nex[now][i]]=nex[fail[now]][i];
					q.push(nex[now][i]);
				}
				else nex[now][i]=nex[fail[now]][i];
			}
		}
	}
	int dp[MAX];
	int query(char *s,int n)
	{
		int now,i,t;
		now=root;
		dp[0]=0;
		tr.build(n);
		for(i=1;i<=n;i++)
		{
			t=getid(s[i]);
			now=nex[now][t];
			if(i-mxlen[now]>0) dp[i]=tr.ask(i-mxlen[now],i-1)+1;
			else if(i-mxlen[now]==0) dp[i]=1;
			else dp[i]=INF;
			tr.upd(i,i,dp[i]);
		}
		return dp[n]>=INF?-1:dp[n];
	}
}ac;
/*
ac.init();
ac.insert(s,len,id); s[0..len-1], id:1..n
ac.work();
ac.query(s,len); s[1..len]
*/
char s[MAX],t[MAX];
int main()
{
	int n,m,i;
	scanf("%d",&m);
	scanf("%s",s+1);
	n=strlen(s+1);
	ac.init();
	for(i=1;i<=m;i++)
	{
		scanf("%s",t);
		ac.insert(t,strlen(t),i);
	}
	ac.work();
	printf("%d\n",ac.query(s,n));
	return 0;
}
