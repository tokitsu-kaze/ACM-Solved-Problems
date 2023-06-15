#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=2e6+10;
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
	
}pam; //pam.init();
char s[MAX];
int main()
{
	int m,i,n,x;
	ll ans;
	scanf("%d",&m);
	set<string> res;
	while(m--)
	{
		scanf("%d%s",&n,s);
		s[n]='\0';
		res.insert(s);
	}
	ans=0;
	for(auto &it:res)
	{
		ans++;
		n=it.size();
		pam.init();
		for(i=0;i<n-1;i++)
		{
			pam.add(it[i]-'a',0);
			if(pam.len[pam.last]!=i+1) continue;
			if(res.count(string(it.begin()+i+1,it.end()))) ans+=2;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
4
4 aaaa
3 aaa
2 aa
1 a
*/
