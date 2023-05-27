#include <bits/stdc++.h>
using namespace std;
struct Palindrome_Tree
{
	static const int N=5050;
	static const int LOGN=log2(N)+2;
	static const int K=256;// char size: [0,25]
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
	int add(int t,int p)//attention the type of t is int
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
		return deep[last];
	}
	
}pam; //pam.init();
char s[5050];
int main()
{
	int n,i,ans;
	while(~scanf("%s",s+1))
	{
		n=strlen(s+1);
		pam.init();
		ans=0;
		for(i=1;i<=n;i++) ans+=pam.add(s[i]-'a',i);
		printf("%d\n",ans);
	}
	return 0;
}
