#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct AC_Automaton
{
	static const int K=26;
	int nex[MAX][K],fail[MAX],cnt[MAX],lst[MAX];
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
	void ask(char *s,int n)
	{
		int i,j,k,t,ans;
		vector<vector<int>> dp(n+1,vector<int>(tot+1,-INF));
		dp[0][root]=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]!='?') t=getid(s[i]);
			for(j=root;j<tot;j++)
			{
				if(s[i]!='?') dp[i][nex[j][t]]=max(dp[i][nex[j][t]],dp[i-1][j]+cnt[nex[j][t]]);
				else
				{
					for(k=0;k<K;k++) dp[i][nex[j][k]]=max(dp[i][nex[j][k]],dp[i-1][j]+cnt[nex[j][k]]);
				}
			}
		}
		ans=0;
		for(i=root;i<tot;i++) ans=max(ans,dp[n][i]);
		printf("%d\n",ans);
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
char s[MAX],t[MAX];
int main()
{
	scanf("%s",s+1);
	scanf("%s",t);
	ac.init();
	ac.insert(t,strlen(t),1);
	ac.work();
	ac.ask(s,strlen(s+1));
	return 0;
}
