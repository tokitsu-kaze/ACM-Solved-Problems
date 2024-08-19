#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e6+10;
struct Seg{int l,r,x;};
int n;
struct FHQ_Treap
{
	#define type int
	static const type inf=INF;
	struct node
	{
		int ls,rs,fix;
		int l,r,len,x,v,sum,cnt[2],mn[2];
		node(){l=r=len=x=v=sum=cnt[0]=cnt[1]=0;mn[0]=mn[1]=inf;}
		node(Seg t)
		{
			fix=rand();
			ls=rs=0;
			l=t.l;
			r=t.r;
			x=t.x;
			len=r-l+1;
			if(x) v=len;
			else v=0;
			sum=v;
			cnt[0]=cnt[1]=0;
			mn[0]=mn[1]=inf;
			cnt[x]=1;
			mn[x]=len;
		}
	}t[MAX];
	int st[MAX],top;
	int tagl[MAX][2],tagr[MAX][2];
	int rt,tot;
	void init()
	{
		rt=0;
		srand(time(0));
		tot=0;
		top=0;
		t[0]=node();
	}
	int newnode(Seg x)
	{
		int id=top?st[--top]:++tot;
		t[id]=node(x);
		tagl[id][0]=tagl[id][1]=0;
		tagr[id][0]=tagr[id][1]=0;
		return id;
	}
	void delnode(int x){st[top++]=x;}
	void pushup(int id)  
	{
		int ls=t[id].ls;
		int rs=t[id].rs;
		t[id].sum=t[ls].sum+t[rs].sum+t[id].v;
		t[id].cnt[0]=t[ls].cnt[0]+t[rs].cnt[0]+(t[id].x==0);
		t[id].cnt[1]=t[ls].cnt[1]+t[rs].cnt[1]+(t[id].x==1);
		t[id].mn[0]=min({t[ls].mn[0],t[rs].mn[0],t[id].x==0?t[id].len:inf});
		t[id].mn[1]=min({t[ls].mn[1],t[rs].mn[1],t[id].x==1?t[id].len:inf});
	}
	void maintain(int id,int lv0,int lv1,int rv0,int rv1)
	{
		if(!id) return;
		int ls=t[id].ls;
		int rs=t[id].rs;
		t[id].sum+=(lv1+rv1)*t[id].cnt[1];
		if(t[id].x==0)
		{
			t[id].l-=lv0;
			t[id].r+=rv0;
			t[id].len+=lv0+rv0;
		}
		else
		{
			t[id].v+=lv1+rv1;
			t[id].l-=lv1;
			t[id].r+=rv1;
			t[id].len+=lv1+rv1;
		}
		t[id].mn[0]+=lv0+rv0;
		t[id].mn[1]+=lv1+rv1;
		tagl[id][0]+=lv0;
		tagr[id][0]+=rv0;
		tagl[id][1]+=lv1;
		tagr[id][1]+=rv1;
	}
	void pushdown(int id)
	{
		if(!(tagl[id][0]||tagl[id][1]||tagr[id][0]||tagr[id][1])) return;
		if(t[id].ls) maintain(t[id].ls,tagl[id][0],tagl[id][1],tagr[id][0],tagr[id][1]);
		if(t[id].rs) maintain(t[id].rs,tagl[id][0],tagl[id][1],tagr[id][0],tagr[id][1]);
		tagl[id][0]=tagl[id][1]=tagr[id][0]=tagr[id][1]=0;
	}
	int build(vector<Seg> &a)
	{
		int id,k,top=0;
		for(auto &it:a)
		{
			id=newnode(it);
			k=top;
			while(k>0&&t[st[k-1]].fix>t[id].fix) pushup(st[--k]);
			if(k) t[st[k-1]].rs=id;
			if(k<top) t[id].ls=st[k];
			st[k++]=id;
			top=k;
		}
		while(top>0) pushup(st[--top]);
		return st[0];
	}
	void splitr(int id,int pos,int &x,int &y)
	{
		if(!id)
		{
			x=y=0;
			return;
		}
		pushdown(id);
		if(t[id].l<=pos)
		{
			x=id;
			splitr(t[id].rs,pos,t[id].rs,y);
		}
		else
		{
			y=id;
			splitr(t[id].ls,pos,x,t[id].ls);
		}
		pushup(id);
	}
	void splitl(int id,int pos,int &x,int &y)
	{
		if(!id)
		{
			x=y=0;
			return;
		}
		pushdown(id);
		if(t[id].r<pos)
		{
			x=id;
			splitl(t[id].rs,pos,t[id].rs,y);
		}
		else
		{
			y=id;
			splitl(t[id].ls,pos,x,t[id].ls);
		}
		pushup(id);
	}
	int merge(int x,int y)
	{
		if(!x||!y) return x|y;
		int id;
		if(t[x].fix<t[y].fix)
		{
			pushdown(x);
			id=x;
			t[x].rs=merge(t[x].rs,y);
		}
		else
		{
			pushdown(y);
			id=y;
			t[y].ls=merge(x,t[y].ls);
		}
		pushup(id);
		return id;
	}
	void del(int x)
	{
		if(!x) return;
		del(t[x].ls);
		del(t[x].rs);
		delnode(x);
	}
	int front(int x)
	{
		while(t[x].ls)
		{
			pushdown(x);
			x=t[x].ls;
		}
		return x;
	}
	int back(int x)
	{
		while(t[x].rs)
		{
			pushdown(x);
			x=t[x].rs;
		}
		return x;
	}
	void insert(int pos,vector<Seg> &a)
	{
		int ra,rb;
		splitl(rt,pos,ra,rb);
		rt=merge(merge(ra,build(a)),rb);
	}
	void cover(int l,int r,int x)
	{
		int ra,rb,rc,rd,re,lseg,rseg;
		splitr(rt,r+1,ra,rc);
		splitl(ra,l-1,ra,rb);
		lseg=front(rb);
		rseg=back(rb);
//		printf("%d %d\n",t[lseg].l,t[lseg].r);
//		printf("%d %d\n",t[rseg].l,t[rseg].r);
		rd=re=0;
		if(t[lseg].x==x) l=t[lseg].l;
		else if(t[lseg].l<l) rd=newnode({t[lseg].l,l-1,t[lseg].x});
		if(t[rseg].x==x) r=t[rseg].r;
		else if(t[rseg].r>r) re=newnode({r+1,t[rseg].r,t[rseg].x});
		rt=merge(ra,rd);
		rt=merge(rt,newnode({l,r,x}));
		rt=merge(rt,re);
		rt=merge(rt,rc);
		del(rb);
	}
	void upd_left(int l,int r,int v)
	{
		int ra,rb,rc,rd,re,lseg,rseg,rl,rr;
		splitr(rt,r,ra,rc);
		splitl(ra,l,ra,rb);
		lseg=front(rb);
		rseg=back(rb);
		if(t[lseg].x==v)
		{
			splitr(rb,t[lseg].r,rl,rb);
			ra=merge(ra,rl);
		}
		if(t[rseg].x!=v)
		{
			splitl(rb,t[rseg].l,rb,rr);
			rc=merge(rr,rc);
		}
		if(v) maintain(rb,0,1,-1,0);
		else maintain(rb,1,0,0,-1);
		rt=merge(merge(ra,rb),rc);
	}
	void upd_right(int l,int r,int v)
	{
		int ra,rb,rc,rd,re,lseg,rseg,rl,rr;
		splitr(rt,r,ra,rc);
		splitl(ra,l,ra,rb);
		lseg=front(rb);
		rseg=back(rb);
		if(t[lseg].x!=v)
		{
			splitr(rb,t[lseg].r,rl,rb);
			ra=merge(ra,rl);
		}
		if(t[rseg].x==v)
		{
			splitl(rb,t[rseg].l,rb,rr);
			rc=merge(rr,rc);
		}
		if(v) maintain(rb,-1,0,0,1);
		else maintain(rb,0,-1,1,0);
		rt=merge(merge(ra,rb),rc);
	}
	void del_invalid_node(int x)
	{
		if(!x) return;
		int ra,rb,rc,lseg,rseg;
		pushdown(x);
		if(t[x].l>t[x].r)
		{
			if(t[x].l==1)
			{
				splitl(rt,1,ra,rt);
				delnode(ra);
				return;
			}
			if(t[x].r==n)
			{
				splitr(rt,n,rt,ra);
				delnode(ra);
				return;
			}
			splitr(rt,t[x].l,ra,rc);
			splitl(ra,t[x].r,ra,rb);
			lseg=front(rb);
			rseg=back(rb);
			rt=merge(ra,newnode({t[lseg].l,t[rseg].r,t[lseg].x}));
			rt=merge(rt,rc);
			del(rb);
			return;
		}
		if(t[t[x].ls].mn[0]<=0 || t[t[x].ls].mn[1]<=0)
		{
			del_invalid_node(t[x].ls);
			return;
		}
		if(t[t[x].rs].mn[0]<=0 || t[t[x].rs].mn[1]<=0)
		{
			del_invalid_node(t[x].rs);
			return;
		}
	}
	void check()
	{
		while(t[rt].mn[0]<=0 || t[rt].mn[1]<=0) del_invalid_node(rt);
	}
	type ask_sum(int l,int r)
	{
		int ra,rb,rc,lseg,rseg;
		type res;
		splitr(rt,r,ra,rc);
		splitl(ra,l,ra,rb);
		lseg=front(rb);
		rseg=back(rb);
		res=t[rb].sum;
		if(t[lseg].x) res-=l-t[lseg].l;
		if(t[rseg].x) res-=t[rseg].r-r;
		rt=merge(merge(ra,rb),rc);
		return res;
	}
	void dfs(int id)
	{
		if(!id) return;
		pushdown(id);
		dfs(t[id].ls);
		printf("seg:[%d,%d] %d\n",t[id].l,t[id].r,t[id].x);
		dfs(t[id].rs);
	}
	void debug()
	{
		puts("*******begin*******");
		dfs(rt);
		puts("*******end*******");
	}
	#undef type
}tr;
int main()
{
	int m,i,lst,op,l,r,x,pre;
	scanf("%d%d",&n,&m);
	vector<Seg> res;
	scanf("%d",&x);
	pre=x;
	l=r=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		if(x!=pre)
		{
			res.push_back({l,r,pre});
			l=r=i;
		}
		else r++;
		pre=x;
	}
	res.push_back({l,r,pre});
	tr.init();
	tr.insert(1,res);
//	tr.debug();
	lst=0;
	while(m--)
	{
		scanf("%d%d%d",&op,&l,&r);
		l^=lst;
		r^=lst;
		if(op==7) printf("%d\n",lst=tr.ask_sum(l,r));
		else if(op==1) tr.cover(l,r,0);
		else if(op==2) tr.cover(l,r,1);
		else if(op==3) tr.upd_left(l,r,1);
		else if(op==4) tr.upd_right(l,r,1);
		else if(op==5) tr.upd_left(l,r,0);
		else if(op==6) tr.upd_right(l,r,0);
		if(op>=3 && op<=6) tr.check();
//		tr.debug();
	}
	return 0;
}
/*
7 3
0 1 0 0 0 1 1
7 2 6
2 4 4
1 1 5

5 5
0 1 0 0 1
3 2 5
5 2 5
2 2 2
1 2 2
6 1 5

5 5
0 1 0 0 1
3 1 5
3 1 5
3 1 5
3 1 5
5 1 5

*/
