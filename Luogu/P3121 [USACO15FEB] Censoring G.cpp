#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct AC_Automaton
{
	static const int K=26;
	int nex[MAX][K],fail[MAX],cnt[MAX],last[MAX];
	int root,tot,pos[MAX],len[MAX];
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
		len[now]=n;
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
	int st[MAX],now[MAX];
	void query(char *s,int n)
	{
		int t,x,i,top;
		x=root;
		top=0;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			x=nex[x][t];
			st[top++]=i;
			now[i]=x;
			if(len[x]>0)
			{
				top-=len[x];
				x=now[st[top-1]];
			}
		}
		string res;
		for(i=0;i<top;i++) res+=s[st[i]];
		cout<<res<<"\n";
	}
}ac;
/*
i is the suffix for each node in the subtree(i) of the fail tree

ac.init();
ac.insert(s,len,id); s[0..len-1], id:1..n
ac.work();
ac.query(s,len); s[0..len-1]
*/
char s[MAX],t[MAX];
int main()
{
	int n,m,k,i;
	scanf("%s",s);
	n=strlen(s);
	scanf("%d",&k);
	ac.init();
	for(i=1;i<=k;i++)
	{
		scanf("%s",t);
		m=strlen(t);
		ac.insert(t,m,i);
	}
	ac.work();
	ac.query(s,n);
	return 0;
}

