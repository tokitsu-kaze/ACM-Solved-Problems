#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct ODT
{
	#define type int
	#define init_val -1
	struct ODT_node
	{
		int l,r;
		mutable type v;
		inline bool operator<(const ODT_node &o)const {return l<o.l;}
	};
	int n;
	set<ODT_node> odt;
	typedef set<ODT_node>::iterator odt_iter;
	void init(int _n)
	{
		n=_n;
		odt.clear();
		odt.insert({1,n,init_val});
	}
	odt_iter find(int x){return --odt.upper_bound({x,0,init_val});}
	odt_iter split(int x)
	{
		if(x>n) return odt.end();
		odt_iter it=find(x);
		if(it->l==x) return it;
		int l=it->l,r=it->r;
		type v=it->v;
		odt.erase(it);
		odt.insert({l,x-1,v});
		return odt.insert({x,r,v}).first;
	}
	void assign(int l,int r,type v)
	{
		odt_iter itr=split(r+1),itl=split(l);
		odt.erase(itl,itr);
		odt.insert({l,r,v});
	}
	bool ask(int l,int r)
	{
		int x,y,v;
		odt_iter itr=split(r+1),itl=split(l);
		v=(*itl).v;
		for(auto it=itl;it!=itr;it++)
		{
			if((*it).v!=v)
			{
				odt.erase(itl,it);
				odt.insert({l,r,v});
				return 0;
			}
			r=(*it).r;
		}
		odt.erase(itl,itr);
		odt.insert({l,r,v});
		if(l==1) x=-1;
		else x=(*find(l-1)).v;
		if(r==n) y=-2;
		else y=(*find(r+1)).v;
		return x!=y;
	}
	#undef init_val
	#undef type
}odt;
char s[MAX];
int main()
{
	int n,i,q,x,y;
	char op[2],t[2];
	scanf("%d",&n);
	scanf("%s",s+1);
	odt.init(n);
	x=y=1;
	for(i=2;i<=n;i++)
	{
		if(s[i]==s[i-1]) y++;
		else
		{
			odt.assign(x,y,s[i-1]-'A');
			x=y=i;
		}
	}
	odt.assign(x,y,s[n]-'A');
//	for(auto it:odt.odt) printf("%d %d\n",it.l,it.r);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s%d%d",op,&x,&y);
		if(op[0]=='A')
		{
			scanf("%s",t);
			odt.assign(x,y,t[0]-'A');
		}
		else puts(odt.ask(x,y)?"Yes":"No");
	}
	return 0;
}
