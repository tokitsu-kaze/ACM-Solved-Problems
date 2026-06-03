#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
const ll mod=1e9+7;
struct Matrix
{
	static const int N=102;
	int n;
	ll c[N][N];
	Matrix(){}
	Matrix(int _n,ll v=0)
	{
		int i,j;
		n=_n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=v;
			}
		}
	}
	void init_identity_matrix() {for(int i=0;i<n;i++) c[i][i]=1;}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(!c[i][k]) continue;
				for(j=0;j<n;j++)
				{
					res.c[i][j]+=c[i][k]*b.c[k][j];
					if(res.c[i][j]>=mod) res.c[i][j]%=mod;
				}
			}
		}
		return res;
	}
};
Matrix matqpow(Matrix a,ll b)
{
	Matrix res(a.n);
	res.init_identity_matrix();
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
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
		cnt[now]=1;
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
			
			cnt[now]|=cnt[fail[now]];
			
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
	Matrix get_mat()
	{
		int i,j;
		Matrix a(tot,0);
		for(i=0;i<tot;i++)
		{
			if(cnt[i]) continue;
			for(j=0;j<K;j++)
			{
				if(cnt[nex[i][j]]) continue;
				a.c[i][nex[i][j]]++;
			}
		}
		return a;
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
	int n,k,i,len;
	ll ans;
	char s[12];
	scanf("%d%d",&n,&k);
	ac.init();
	for(i=1;i<=k;i++)
	{
		scanf("%d%s",&len,s);
		ac.insert(s,len,i);
	}
	ac.work();
	auto res=matqpow(ac.get_mat(),n);
	ans=0;
	for(i=0;i<res.n;i++) ans=(ans+res.c[0][i])%mod;
	printf("%lld\n",ans);
	return 0;
}
