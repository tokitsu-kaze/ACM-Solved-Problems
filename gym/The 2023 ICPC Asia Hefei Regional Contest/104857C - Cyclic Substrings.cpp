#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e6+10;
const int mod=998244353;
ll sqr(ll x){return x*x%mod;}
struct Palindrome_Tree
{
	static const int N=MAX<<1;
	static const int LOGN=log2(N)+3;
	static const int K=10;// char size: [0,25]
	int len[N],nex[N][K],fail[N],last,pos[N],s[N],tot,n;
	int cnt[N],dep[N];
	int newnode(int l)
	{
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0; 
		dep[tot]=cnt[tot]=0;
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
	void add(int t,int p)
	{
		int id,now;
		s[++n]=t;
		now=get_fail(last);
		if(!nex[now][t])
		{
			id=newnode(len[now]+2);
			fail[id]=nex[get_fail(fail[now])][t];
			dep[id]=dep[fail[id]]+1;
			nex[now][t]=id;
		}
		last=nex[now][t];
		cnt[last]++;
		pos[p]=last;
	}
	void work(ll *tmp,int &n)
	{
		int i;
		ll res=0;
		for(i=2;i<tot;i++) tmp[i]=cnt[i];
		for(i=tot-1;i;i--) (tmp[fail[i]]+=tmp[i])%=mod;
		n=tot;
	}
}pam;
/*
pam.init();
pam.add(t,id); t is int
*/
char s[MAX];
int subtot,sumtot;
ll sub[MAX],sum[MAX<<1];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	pam.init();
	for(i=1;i<=n;i++) pam.add(s[i]-'0',i);
	pam.work(sub,subtot);
	for(i=1;i<=n;i++) pam.add(s[i]-'0',i+n);
	pam.work(sum,sumtot);
	ans=0;
	for(i=2;i<sumtot;i++)
	{
		if(pam.len[i]>n) continue;
		if(i>=subtot) sub[i]=0;
		ans=(ans+sqr(sum[i]-sub[i])*pam.len[i])%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
