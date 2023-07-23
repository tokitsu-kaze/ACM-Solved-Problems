#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
struct AC_Automaton
{
	static const int K=26;
	int nex[MAX][K],fail[MAX],cnt[MAX],last[MAX];
	int root,tot,pos[MAX];
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
	int out[MAX];
	int res[MAX];
	void topsort()
	{
		int i,t;
		queue<int> q;
		for(i=1;i<tot;i++) out[fail[i]]++;
		for(i=1;i<tot;i++)
		{
			if(!out[i]) q.push(i);
		}
		while(!q.empty())
		{
			t=q.front();
			q.pop();
			
			res[fail[t]]+=res[t];
			
			out[fail[t]]--;
			if(out[fail[t]]==0) q.push(fail[t]);
		}
	}
	void query(char *s,int n)
	{
		int len,now,i,t;
		now=root;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			now=nex[now][t];
			res[now]++;
		}
	}
	void build_fail_tree(vector<int> mp[])
	{
		for(int i=0;i<=tot;i++) mp[i].clear();
		for(int i=1;i<tot;i++) mp[fail[i]].push_back(i);
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
	int n,i;
	scanf("%d",&n);
	ac.init();
	vector<string> res;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		res.push_back(s);
		ac.insert(s,strlen(s),i);
	}
	ac.work();
	for(i=1;i<ac.tot;i++) ac.res[i]=0;
	for(i=0;i<n;i++) ac.query((char *)res[i].c_str(),res[i].size());
	ac.topsort();
	for(i=1;i<=n;i++) printf("%d\n",ac.res[ac.pos[i]]);
	return 0;
}

