#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=6000+10;
const int mod=1e4+7;
struct AC_Automaton
{
	static const int K=26;
	int nex[MAX][K],fail[MAX],cnt[MAX],lst[MAX],tag[MAX];
	int root,tot,pos[MAX];
	int getid(char c){return c-'A';}//may need change
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
			if(cnt[fail[now]]) lst[now]=fail[now];
			else lst[now]=lst[fail[now]];
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
	int dp[2][MAX];
	int ask(int m)
	{
		int i,j,k,f,res;
		f=0;
		memset(dp[f],0,sizeof dp[f]);
		dp[f][root]=1;
		for(i=1;i<=m;i++)
		{
			f^=1;
			memset(dp[f],0,sizeof dp[f]);
			for(j=root;j<tot;j++)
			{
				for(k=0;k<K;k++)
				{
					if(tag[nex[j][k]]) continue;
					dp[f][nex[j][k]]=(dp[f][nex[j][k]]+dp[f^1][j])%mod;
				}
			}
		}
		res=0;
		for(i=root;i<tot;i++) res=(res+dp[f][i])%mod;
		return res;
	}
}ac;
/*
ac.init();
ac.insert(s,len,id); s[0..len-1], id:1..n
ac.work();
ac.query(s,len); s[0..len-1]
*/
ll qpow(ll a,int b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
char s[MAX];
int main()
{
	int n,m,i;
	scanf("%d%d",&n,&m);
	ac.init();
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		ac.insert(s,strlen(s),i);
	}
	ac.work();
	printf("%d\n",(qpow(26,m)-ac.ask(m)+mod)%mod);
	return 0;
}
