#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
struct Palindrome_Tree
{
	static const int N=MAX;
	static const int LOGN=log2(N)+3;
	static const int K=26;// char size: [0,25]
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
	void topsort()
	{
		for(int i=tot-1;i;i--) cnt[fail[i]]+=cnt[i];
	}
	
}pama,pamb;
/*
pam.init();
pam.add(t,id); t is int
*/
char a[MAX],b[MAX];
ll ans;
void dfs(int x,int y)
{
	int i,nexa,nexb;
	for(i=0;i<26;i++)
	{
		nexa=pama.nex[x][i];
		nexb=pamb.nex[y][i];
		if(!nexa) continue;
		if(!nexb) continue;
		ans+=1LL*pama.cnt[nexa]*pamb.cnt[nexb];
		dfs(nexa,nexb);
	}
}
int main()
{
	int n,m,i;
	scanf("%s%s",a,b);
	n=strlen(a);
	m=strlen(b);
	pama.init();
	for(i=0;i<n;i++) pama.add(a[i]-'A',i);
	pamb.init();
	for(i=0;i<m;i++) pamb.add(b[i]-'A',i);
	pama.topsort();
	pamb.topsort();
	ans=0;
	dfs(0,0);
	dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}
