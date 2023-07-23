#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
struct AC_Automaton
{
	static const int K=26;
	int nex[MAX][K],fail[MAX],cnt[MAX],last[MAX];
	int root,tot,pos[MAX],id[MAX];
	int getid(char c){return c-'a';}//may need change
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0;
		cnt[tot]=0;
		id[tot]=-1;
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
		id[now]=x;
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
	int res[MAX];
	int out[MAX];
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
	vector<pair<int,int>> query(char *s,int n)
	{
		int len,now,i,t,tmp;
		now=root;
		for(i=0;i<=tot;i++) res[i]=0;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			now=nex[now][t];
			res[now]++;
	//		printf("%d %d %d\n",i,now,id[now]);
		}
		topsort();
		vector<pair<int,int>> ans;
		for(i=0;i<=tot;i++)
		{
			if(id[i]!=-1)
			{
	//			printf("%d %d\n",id[i],res[i]);
				ans.push_back({res[i],id[i]});
			}
		}
		return ans;
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
char t[155][77];
char s[MAX];
int main()
{
	int n,i;
	while(~scanf("%d",&n)&&n>0)
	{
		ac.init();
		for(i=1;i<=n;i++)
		{
			scanf("%s",t[i]);
			ac.insert(t[i],strlen(t[i]),i);
		}
		ac.work();
		scanf("%s",s);
		vector<pair<int,int>> res=ac.query(s,strlen(s));
		for(auto &it:res) it.first=-it.first;
		sort(res.begin(),res.end());
		vector<int> ans;
		for(auto &it:res)
		{
			if(it.first==res[0].first) ans.push_back(it.second);
			else break;
		}
		printf("%d\n",-res[0].first);
		for(auto &it:ans) puts(t[it]);
	}
	return 0;
}
/*
3
a
aba
bab
ababababac
*/
