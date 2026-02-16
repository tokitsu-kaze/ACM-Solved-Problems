#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
struct Trie
{
	#define type int
	static const int K=26;
	int nex[MAX][K],cnt[MAX];
	int root,tot;
	int getid(char c){return c-'A';}
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init()
	{
		tot=0;
		memset(nex[0],0,sizeof nex[0]);
		cnt[0]=0;
		root=newnode();
	}
	void insert(char *s,int n) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		for(i=0;i<n;i++)
		{
			cnt[now]++;
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
		}
		cnt[now]++;
	}
	int v[MAX];
	void dfs(int x)
	{
		v[x]=0;
		if(!x) return;
		for(int i=0;i<K;i++)
		{
			dfs(nex[x][i]);
			v[x]+=v[nex[x][i]];
		}
		if(x!=root && v[x]+2<=cnt[x]) v[x]+=2;
	}
	int work()
	{
		dfs(root);
		return v[root];
	}
	#undef type
}tr;
/*
tr.init();
tr.insert(s,len); s[0..len-1]
*/
char s[MAX];
int main()
{
	int T,n,i,len,cas;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		tr.init();
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			reverse(s,s+len);
			tr.insert(s,len);
		}
		printf("Case #%d: %d\n",cas,tr.work());
	}
	return 0;
}
