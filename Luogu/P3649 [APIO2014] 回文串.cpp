#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=3e5+10;
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
		for(int i=tot-1;i>1;i--) cnt[fail[i]]+=cnt[i];
	}
}pam; //pam.init();
char s[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	pam.init();
	for(i=1;i<=n;i++) pam.add(s[i]-'a',i);
	pam.count();
	ans=0;
	for(i=2;i<=pam.tot-1;i++) ans=max(ans,1ll*pam.cnt[i]*pam.len[i]);
	printf("%lld\n",ans);
}
