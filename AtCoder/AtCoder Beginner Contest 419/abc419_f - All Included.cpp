#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=80+10;
const int mod=998244353;
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
		cnt[now]|=(1<<x);
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
			if(cnt[fail[now]])
			{
				lst[now]=fail[now];
				cnt[now]|=cnt[fail[now]];
			}
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
	int dp[105][MAX][(1<<8)+5];
	void solve(int len,int m)
	{
		int i,j,k,f;
		for(i=0;i<=len;i++)
		{
			for(j=0;j<tot;j++)
			{
				for(k=0;k<(1<<m);k++)
				{
					dp[i][j][k]=0;
				}
			}
		}
		dp[0][0][0]=1;
		for(i=0;i<len;i++)
		{
			for(j=0;j<tot;j++)
			{
				for(k=0;k<(1<<m);k++)
				{
					if(dp[i][j][k]==0) continue;
					for(f=0;f<26;f++)
					{
						(dp[i+1][nex[j][f]][k|cnt[nex[j][f]]]+=dp[i][j][k])%=mod;
					}
				}
			}
		}
		int ans=0;
		for(k=0;k<tot;k++)
		{
			ans=(ans+dp[len][k][(1<<m)-1])%mod;
		}
		printf("%d\n",ans);
	}
}ac;
/*
ac.init();
ac.insert(s,len,id); s[0..len-1], id:1..n
ac.work();
*/
int main()
{
	int n,i,l;
	char s[12];
	ac.init();
	scanf("%d%d",&n,&l);
	for(i=0;i<n;i++)
	{
		scanf("%s",s);
		ac.insert(s,strlen(s),i);
	}
	ac.work();
	ac.solve(l,n);
	return 0;
}
