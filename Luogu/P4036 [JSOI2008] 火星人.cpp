#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
const int mod=805306457;
const int bs=233333;
int qpow[MAX];
struct FHQ_Treap
{
	#define type int
	static const type inf=INF;
	struct node
	{
		int ls,rs,fix,sz;
		type ha,hap;
		node(){}
		node(type x,int _sz)
		{
			hap=ha=x;
			fix=rand();
			sz=_sz;
			ls=rs=0;
		}
	}t[MAX];
	int st[MAX];
	int rt,tot;
	void init()
	{
		rt=0;
		srand(time(0));
		tot=0;
		t[0].sz=0;
		t[0].ls=t[0].rs=0;
		t[0].hap=t[0].ha=0;
	}
	int newnode(type v)
	{
		t[++tot]=node(v,1);
		return tot;
	}
	void pushup(int id)  
	{
		int ls=t[id].ls;
		int rs=t[id].rs;
		t[id].sz=t[ls].sz+t[rs].sz+1;
		t[id].ha=(1ll*t[ls].ha*qpow[1]+t[id].hap)%mod;
		t[id].ha=(1ll*t[id].ha*qpow[t[rs].sz]+t[rs].ha)%mod;
	}
	void pushdown(int id)
	{
		
	}
	int build(vector<type> &a)
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
	void split(int id,int pos,int &x,int &y)
	{
		if(!id)
		{
			x=y=0;
			return;
		}
		pushdown(id);
		int tmp=t[t[id].ls].sz+1;
		if(tmp<=pos)
		{
			x=id;
			split(t[id].rs,pos-tmp,t[id].rs,y);
		}
		else
		{
			y=id;
			split(t[id].ls,pos,x,t[id].ls);
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
	void insert(int pos,type v)
	{
		int ra,rb;
		split(rt,pos-1,ra,rb);
		rt=merge(merge(ra,newnode(v)),rb);
	}
	void insert(int pos,vector<type> a)
	{
		int ra,rb;
		split(rt,pos-1,ra,rb);
		rt=merge(merge(ra,build(a)),rb);
	}
	void erase(int pos,type v)
	{
		int ra,rb,rc;
		split(rt,pos,ra,rc);
		split(ra,pos-1,ra,rb);
		rt=merge(ra,rc);
	}
	type ask(int l,int r)
	{
		int ra,rb,rc,res;
		split(rt,r,ra,rc);
		split(ra,l-1,ra,rb);
		res=t[rb].ha;
		rt=merge(merge(ra,rb),rc);
		return res;
	}
	void upd(int pos,type v)
	{
		int ra,rb,rc;
		split(rt,pos,ra,rc);
		split(ra,pos-1,ra,rb);
		t[rb].hap=t[rb].ha=v;
		rt=merge(merge(ra,rb),rc);
	}
	int size(){return t[rt].sz;}
	#undef type
}tr;
/*
tr.init();
*/
char s[MAX];
int main()
{
	int n,q,i,x,y,l,r,mid;
	char op[3],d[3];
	scanf("%s",s+1);
	n=strlen(s+1);
	qpow[0]=1;
	for(i=1;i<=MAX-10;i++) qpow[i]=1ll*qpow[i-1]*bs%mod;
	tr.init();
	vector<int> tmp(n);
	for(i=1;i<=n;i++) tmp[i-1]=s[i]-'a';
	tr.insert(1,tmp);
/*	for(i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			printf("%d %d %d\n",i,j,tr.ask(i,j));
		}
	}*/
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s%d",op,&x);
		if(op[0]=='Q')
		{
			scanf("%d",&y);
			l=0;
			r=n-max(x,y)+1;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(tr.ask(x,x+mid)==tr.ask(y,y+mid)) l=mid+1;
				else r=mid;
			}
			printf("%d\n",l);
		}
		else if(op[0]=='R')
		{
			scanf("%s",d);
			tr.upd(x,d[0]-'a');
		}
		else
		{
			scanf("%s",d);
			tr.insert(x+1,d[0]-'a');
			n++;
		}
	}
	return 0;
}
