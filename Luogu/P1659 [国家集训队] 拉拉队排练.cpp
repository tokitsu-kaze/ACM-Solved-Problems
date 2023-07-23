#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=19930726;
const int MAX=1e6+10;
ll qpow(ll a,ll b)
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
	void add(int t,int p)
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
	void topsort()
	{
		for(int i=tot-1;i;i--) cnt[fail[i]]+=cnt[i];
	}
}pam;
/*
pam.init();
pam.add(t,id); t is int
*/
char s[MAX];
ll res[MAX];
int main()
{
	int n,i;
	ll k,ans;
	scanf("%d%lld",&n,&k);
	scanf("%s",s+1);
	pam.init();
	for(i=1;i<=n;i++) pam.add(s[i]-'a',i);
	for(i=1;i<=n;i++) res[i]=0;
	pam.topsort();
	for(i=1;i<pam.tot;i++) res[pam.len[i]]+=pam.cnt[i];
	ans=1;
	for(i=n;i;i--)
	{
		if(!(i&1)) continue;
		ans=ans*qpow(i,min(res[i],k))%mod;
		k-=min(k,res[i]);
	}
	if(k>0) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}
