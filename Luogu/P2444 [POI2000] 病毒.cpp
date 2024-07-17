#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e4+10;
struct AC_Automaton
{
	static const int K=2;
	int nex[MAX][K],fail[MAX],cnt[MAX],last[MAX],tag[MAX];
	int root,tot,pos[MAX];
	int getid(char c){return c-'0';}//may need change
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0;
		cnt[tot]=tag[tot]=0;
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
		tag[now]=1;
		pos[x]=now;
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
			tag[now]|=tag[fail[now]];
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
	int ok,vis[MAX];
	void dfs(int x)
	{
		int i;
		if(ok) return;
		if(vis[x]==1) return;
		vis[x]=2;
		for(i=0;i<K;i++)
		{
			if(tag[nex[x][i]]) continue;
			if(vis[nex[x][i]]==2)
			{
				ok=1;
				return;
			}
			dfs(nex[x][i]);
		}
		vis[x]=1;
	}
	int query()
	{
		ok=0;
		memset(vis,0,sizeof vis);
		dfs(root);
		return ok;
	}
}ac;
/*
ac.init();
ac.insert(s,len,id); s[0..len-1], id:1..n
ac.work();
ac.query(s,len); s[0..len-1]
*/
char t[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	ac.init();
	for(i=1;i<=n;i++)
	{
		scanf("%s",t);
		ac.insert(t,strlen(t),i);
	}
	ac.work();
	puts(ac.query()?"TAK":"NIE");
	return 0;
}
