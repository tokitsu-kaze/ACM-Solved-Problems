#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
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
struct AC_Automaton
{
	static const int K=26;
	int nex[MAX][K],orgnex[MAX][K],fail[MAX],cnt[MAX],lst[MAX];
	int root,tot,pos[MAX],tots;
	int getid(char c){return c-'a';}//may need change
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0;
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	int pre[MAX];
	void insert(char *s,int n) // s[0..n-1]
	{
		int now,i,t,tmp;
		now=root;
		tots=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='P')
			{
				cnt[now]++;
				pos[++tots]=now;
			}
			else if(s[i]=='B')
			{
				now=pre[now];
			}
			else
			{
				t=getid(s[i]);
				tmp=now;
				if(!nex[now][t]) nex[now][t]=newnode();
				now=nex[now][t];
				pre[now]=tmp;
			}
		}
	}
	void work()
	{
		int i,j,now;
		for(i=root;i<tot;i++)
		{
			for(j=0;j<K;j++)
			{
				orgnex[i][j]=nex[i][j];
			}
		}
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
			if(cnt[fail[now]]) lst[now]=fail[now];
			else lst[now]=lst[fail[now]];
			
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
	vector<int> mp[MAX];
	int l[MAX],r[MAX],dfntot;
	void build_fail_tree()
	{
		for(int i=0;i<=tot;i++) mp[i].clear();
		for(int i=1;i<tot;i++) mp[fail[i]].push_back(i);
	}
	void dfs(int x)
	{
		l[x]=++dfntot;
		for(auto &to:mp[x]) dfs(to);
		r[x]=dfntot;
	}
	struct qnode{int x,id;};
	vector<qnode> qst[MAX];
	int ans[MAX];
	void dfs2(int x)
	{
		if(x!=root) tr.upd(l[x],1);
		for(auto &it:qst[x]) ans[it.id]=tr.ask(l[it.x],r[it.x]);
		for(int i=0;i<K;i++)
		{
			if(orgnex[x][i]) dfs2(orgnex[x][i]);
		}
		tr.upd(l[x],-1);
	}
	void ask()
	{
		int q,i,x,y;
		build_fail_tree();
		dfntot=0;
		dfs(root);
		scanf("%d",&q);
		for(i=1;i<=tots;i++) qst[i].clear();
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			qst[pos[y]].push_back({pos[x],i});
		}
		tr.init(tot);
		dfs2(root);
		for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	}
}ac;
/*
i is the suffix for each node in the subtree(i) of the fail tree

ac.init();
ac.insert(s,len,id); s[0..len-1], id:1..n
ac.work();
ac.query(s,len); s[0..len-1]
ac.build_fail_tree(mp);
*/
char s[MAX];
int main()
{
	ac.init();
	scanf("%s",s);
	ac.insert(s,strlen(s));
	ac.work();
	ac.ask();
	return 0;
}
