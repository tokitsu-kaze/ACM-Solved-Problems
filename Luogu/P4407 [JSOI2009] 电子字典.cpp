#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+10;
struct Trie
{
	#define type int
	static const int K=26;
	int nex[MAX][K],cnt[MAX];
	int root,tot;
	int getid(char c){return c-'a';}
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s,int n) // s[0..n-1]
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
	}
	int ask(char *s,int n) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) return 0;
			now=nex[now][t];
		}
		return cnt[now];
	}
	bool vis[MAX];
	vector<int> del;
	int dfs(char *s,int p,int n,int id,int f)
	{
		if(f>1) return 0;
		if((p==n||p==n+1)&&f==1)
		{
			if(vis[id]) return 0;
			vis[id]=1;
			del.push_back(id);
			return cnt[id];
		}
		int i,t,res;
		if(p==n) t=-1;
		else t=getid(s[p]);
		res=0;
		if(t!=-1 && nex[id][t]) res+=dfs(s,p+1,n,nex[id][t],f);
		if(t!=-1) res+=dfs(s,p+1,n,id,f+1);
		for(i=0;i<K;i++)
		{
			if(nex[id][i])
			{
				res+=dfs(s,p,n,nex[id][i],f+1);
				if(t!=-1 && i!=t) res+=dfs(s,p+1,n,nex[id][i],f+1);
			}
		}
		return res;
	}
	int work(char *s,int len)
	{
		int res;
		del.clear();
		res=dfs(s,0,len,root,0);
		for(auto &it:del) vis[it]=0;
		return res;
	}
	#undef type
}tr;
/*
tr.init();
tr.insert(s,len); s[0..len-1]
*/
int main()
{
	int n,m,i,len;
	char s[22];
	scanf("%d%d",&n,&m);
	tr.init();
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		len=strlen(s);
		tr.insert(s,len);
	}
	memset(tr.vis,0,sizeof tr.vis);
	while(m--)
	{
		scanf("%s",s);
		len=strlen(s);
		if(tr.ask(s,len)) puts("-1");
		else printf("%d\n",tr.work(s,len));
	}
	return 0;
}
