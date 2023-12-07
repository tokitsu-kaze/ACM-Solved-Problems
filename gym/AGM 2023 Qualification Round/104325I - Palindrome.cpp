#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Palindrome_Tree
{
	static const int N=MAX;
	static const int LOGN=log2(N)+2;
	static const int K=26;// char size: [0,25]
	int len[N],nex[N][K],fail[N],last,pos[N],s[N],tot,n;
	int cnt[N],deep[N];
	int newnode(int l)
	{
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0; 
		deep[tot]=cnt[tot]=0;
		len[tot]=l;
		return tot++;
	}
	void init()
	{
		tot=n=last=0;
		newnode(0);
		newnode(-1);
		s[0]=-1;
		fail[0]=1;
	}
	int get_fail(int x)
	{
		while(s[n-len[x]-1]!=s[n]) x=fail[x];
		return x;
	}
	void add(int t,int p)//attention the type of t is int
	{
		int id,now;
		s[++n]=t;
		now=get_fail(last);
		if(!nex[now][t])
		{
			id=newnode(len[now]+2);
			fail[id]=nex[get_fail(fail[now])][t];
			deep[id]=deep[fail[id]]+1;
			nex[now][t]=id;
		}
		last=nex[now][t];
		cnt[last]++;
		pos[p]=last;
	}
	void count()
	{
		for(int i=tot-1;i;i--) cnt[fail[i]]+=cnt[i];
	}
	int st[N][LOGN];
	void init_ST()
	{
		int i,j;
		for(i=2;i<tot;i++)
		{
			st[i][0]=fail[i];
			for(j=1;j<LOGN;j++)
			{
				st[i][j]=st[st[i][j-1]][j-1];
			}
		}
	}
	int get_substr(int l,int r)//init_ST
	{
		int now,tmp,i;
		now=pos[r];
		for(i=LOGN-1;~i;i--)
		{
			if(len[st[now][i]]>=r-l+1) now=st[now][i];
		}
		return now;
	}
	int f[MAX];
	int dfs(int l,int r)
	{
		int now=get_substr(l,r);
		if(r-len[now]+1!=l) return 0;
		if(len[now]==1) return f[now]=1;
		if(len[now]<=0) return 0;
		if(f[now]!=-1) return f[now];
		f[now]=dfs(l,r-len[now]/2)+1;
		return f[now];
	}
	ll ans[35];
	void work(int n,int k)
	{
		int i,l,r,now;
		count();
		init_ST();
		memset(f,-1,sizeof f);
		memset(ans,0,sizeof ans);
		for(i=1;i<=n;i++)
		{
			l=i-len[pos[i]]+1;
			r=i;
			dfs(l,r);
		}
		for(i=2;i<tot;i++) ans[f[i]]+=cnt[i];
		for(i=1;i<=k;i++) printf("%lld%c",ans[i]," \n"[i==k]);
	}
}pam; //pam.init(); 
char s[MAX];
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	pam.init();
	for(i=1;i<=n;i++) pam.add(s[i]-'a',i);
	pam.work(n,k);
	return 0;
}
