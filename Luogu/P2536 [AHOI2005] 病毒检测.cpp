#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=500*500+10;
struct Trie
{
	#define type int
	static const int K=4;
	int nex[MAX][K],cnt[MAX],id[256];
	int root,tot;
	int getid(char c){return id[c];}
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init()
	{
		memset(id,-1,sizeof id);
		id['A']=0;
		id['T']=1;
		id['C']=2;
		id['G']=3;
		tot=0;
		memset(nex[0],0,sizeof nex[0]);
		cnt[0]=0;
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
	bool vis[1002][MAX];
	int dfs(int x,int pos,int n,char *s)
	{
		if(!x) return 0;
		if(vis[pos][x]) return 0;
		vis[pos][x]=1;
		if(pos==n+1) return cnt[x];
		int i,res;
		res=0;
		if(s[pos]=='*') res+=dfs(x,pos+1,n,s);
		for(i=0;i<K;i++)
		{
			if(s[pos]=='*')
			{
				res+=dfs(nex[x][i],pos,n,s);
				res+=dfs(nex[x][i],pos+1,n,s);
			}
			else if(s[pos]=='?') res+=dfs(nex[x][i],pos+1,n,s);
		}
		if(getid(s[pos])>=0) res+=dfs(nex[x][getid(s[pos])],pos+1,n,s);
		return res;
	}
	int ask(char *s,int n)
	{
		return dfs(root,1,n,s);
	}
	#undef type
}tr;
/*
tr.init();
tr.insert(s,len); s[0..len-1]
*/
char s[1005],t[505];
int main()
{
	int n,m,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&m);
	tr.init();
	for(i=1;i<=m;i++)
	{
		scanf("%s",t);
		tr.insert(t,strlen(t));
	}
	printf("%d\n",m-tr.ask(s,n));
	return 0;
}
