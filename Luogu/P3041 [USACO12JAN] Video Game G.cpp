#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=300+10;
struct AC_Automaton
{
	static const int K=3;
	int nex[MAX][K],fail[MAX],cnt[MAX],lst[MAX];
	int root,tot,pos[MAX];
	int getid(char c){return c-'A';}//may need change
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
	int dp[1005][MAX];
	void ask(int n)
	{
		int len,now,i,j,k,tmp,res;
		now=root;
		memset(dp[0],-0x3f,sizeof dp[0]);
		dp[0][root]=0;
		for(i=1;i<=n;i++)
		{
			memset(dp[i],-0x3f,sizeof dp[i]);
			for(j=root;j<tot;j++)
			{
				for(k=0;k<3;k++)
				{
					tmp=nex[j][k];
					res=0;
					while(tmp!=root)
					{
						res+=cnt[tmp];
						tmp=lst[tmp];
					}
					dp[i][nex[j][k]]=max(dp[i][nex[j][k]],dp[i-1][j]+res);
				}
			}
		}
		res=0;
		for(j=root;j<tot;j++) res=max(res,dp[n][j]);
		printf("%d\n",res);
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
int main()
{
	int n,k,i;
	char s[22];
	scanf("%d%d",&n,&k);
	ac.init();
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ac.insert(s,strlen(s),i);
	}
	ac.work();
	ac.ask(k);
	return 0;
}
