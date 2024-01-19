#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX][2];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			bit[i][0]=bit[i][1]=0;
		}
	}
	int lowbit(int x){return x&(-x);}
	void _insert(int x,type v)
	{
		for(int i=x;i<=n;i+=lowbit(i))
		{
			bit[i][0]+=v;
			bit[i][1]+=v*(x-1);
		}
	}
	type get(int x)
	{
		type res=0;
		for(int i=x;i;i-=lowbit(i))
		{
			res+=x*bit[i][0]-bit[i][1];
		}
		return res;
	}
	void upd(int l,int r,type v)
	{
		_insert(l,v);
		_insert(r+1,-v);
	}
	type ask(int l,int r)
	{
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
vector<int> mp[MAX];
const int LOG=log2(MAX);
int fa[MAX][LOG+1],l[MAX],r[MAX],tot;
void dfs(int x,int pre)
{
	l[x]=++tot;
	fa[x][0]=pre;
	for(int i=1;i<=LOG;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(auto &to:mp[x])
	{
		if(to==pre) continue;
		dfs(to,x);
	}
	r[x]=tot;
}
int jump(int x)
{
	if(tr.ask(l[x],l[x])==0) return -1;
	for(int i=LOG;~i;i--)
	{
		int to=fa[x][i];
		if(to&&tr.ask(l[to],l[to])>0) x=to;
	}
	return x;
}
int flag[MAX];
int main()
{
	int n,q,i,a,b,op,x;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		flag[i]=0;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	tot=0;
	memset(fa[0],0,sizeof fa[0]);
	dfs(1,0);
	tr.init(n);
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==0)
		{
			if(!flag[x]) tr.upd(l[x],r[x],1);
			else tr.upd(l[x],r[x],-1);
			flag[x]^=1;
		}
		else printf("%d\n",jump(x));
	}
	return 0;
}
