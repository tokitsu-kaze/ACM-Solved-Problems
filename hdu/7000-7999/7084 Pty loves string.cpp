#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e5+10;
struct KMP
{
	#define type char
	int nex[MAX],len;
	type t[MAX];
	void get_next(type *s,int n)
	{
		int i,j;
		len=n;
		for(i=1;i<=len;i++) t[i]=s[i];
		t[len+1]=0;
		nex[0]=nex[1]=0;
		j=0;
		for(i=2;i<=len;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
	}
	#undef type
}kmp;
/*
kmp.get_next(t,len); // t[1..len]
kmp.match(s,n); // s[1..n] return all pos t in s 
*/
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	void init(int _n,type *a)
	{
		n=_n;
		tmp[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=a[i];
			tmp[i]+=tmp[i-1];
			bit[i]=tmp[i]-tmp[i-lowbit(i)];
		}
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		while(x)
		{
			res+=bit[x];
			x-=lowbit(x);
		}
		return res;
	}
	void upd(int x,type v)
	{
		while(x<=n)
		{
			bit[x]+=v;
			x+=lowbit(x);
		}
	}
	type ask(int l,int r)
	{
		if(l>r) return 0;
		if(l-1<=0) return get(r);
		return get(r)-get(l-1);
	}
	#undef type
}tr;
struct node{int x,id;};
vector<node> qst[MAX];
vector<int> mp[MAX];
char s[MAX];
int l[MAX],r[MAX],tot;
int ans[MAX];
void dfs(int x)
{
	l[x]=++tot;
	for(auto &to:mp[x]) dfs(to);
	r[x]=tot;
}
void dfs2(int x)
{
	for(auto &it:qst[x]) ans[it.id]-=tr.ask(l[it.x],r[it.x]);
	if(x>1) tr.upd(l[x-1],1);
	for(auto &to:mp[x]) dfs2(to);
	for(auto &it:qst[x]) ans[it.id]+=tr.ask(l[it.x],r[it.x]);
}
int main()
{
	int t,n,q,i,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for(i=0;i<=n+1;i++) qst[i].clear();
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			qst[n-y+1].push_back({x,i});
			ans[i]=0;
		}
		
		kmp.get_next(s,n);
		for(i=0;i<=n+1;i++) mp[i].clear();
		for(i=1;i<=n;i++) mp[kmp.nex[i]].push_back(i);
		tot=0;
		dfs(0);
		
		reverse(s+1,s+1+n);
		kmp.get_next(s,n);
		for(i=0;i<=n+1;i++) mp[i].clear();
		for(i=1;i<=n;i++) mp[n-kmp.nex[i]+1].push_back(n-i+1);
		tr.init(n+1);
		dfs2(n+1);
		for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
	return 0;
}
