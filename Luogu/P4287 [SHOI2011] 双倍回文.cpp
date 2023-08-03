#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
struct hash_table
{
	ll seed,p;
	ll Hash[MAX],tmp[MAX];
	void set(ll _p)
	{
		seed=131;
		p=_p;
	}
	void work(char *s,int n)
	{
		tmp[0]=1;
		Hash[0]=0;
		for(int i=1;i<=n;i++)
		{
			tmp[i]=tmp[i-1]*seed%p;
			Hash[i]=(Hash[i-1]*seed+s[i])%p;//may need change
		}
	}
	ll get(int l,int r)
	{
		return ((Hash[r]-Hash[l-1]*tmp[r-l+1])%p+p)%p;
	}
}ha[2];
struct Palindrome_Tree
{
	static const int N=MAX;
	static const int LOGN=log2(N)+3;
	static const int K=26;// char size: [0,25]
	int len[N],nex[N][K],fail[N],last,pos[N],s[N],tot,n;
	int cnt[N],deep[N];
	map<pair<ll,ll>,int> mp;
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
		mp.clear();
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
	int ck(int l,int r)
	{
		if(mp.count({ha[0].get(l,r),ha[1].get(l,r)})) return 1;
		return 0;
	}
	int ans;
	int add(int t,int p)
	{
		int id,now;
		s[++n]=t;
		now=get_fail(last);
		if(!nex[now][t])
		{
			id=newnode(len[now]+2);
			fail[id]=nex[get_fail(fail[now])][t];
			deep[id]=deep[fail[id]]+1;
			if(len[id]%4==0 && ck(p-len[id]+1,p-len[id]/2))
			{
				ans=max(ans,len[id]);
			}
			if(len[id]%2==0)
			{
				mp[{ha[0].get(p-len[id]+1,p),ha[1].get(p-len[id]+1,p)}]=id;
			}
			nex[now][t]=id;
		}
		last=nex[now][t];
		cnt[last]++;
		pos[p]=last;
		return deep[last];
	}
}pam;
/*
pam.init();
pam.add(t,id); t is int
*/
char s[MAX];
int main()
{
	int t,n,i;
	scanf("%d",&n);
	scanf("%s",s+1);
	ha[0].set(402653189);
	ha[1].set(1610612741);
	ha[0].work(s,n);
	ha[1].work(s,n);
	pam.init();
	pam.ans=0;
	for(i=1;i<=n;i++) pam.add(s[i]-'a',i);
	printf("%d\n",pam.ans);
	return 0;
}
