#include <bits/stdc++.h>
using namespace std;
const int MAX=3e6+10;
struct Trie
{
	#define type int
	static const int K=26+26+10;
	int nex[MAX][K],cnt[MAX];
	int root,tot;
	int getid(char c)
	{
		if(c>='a'&&c<='z') return c-'a';
		else if(c>='A'&&c<='Z') return 26+c-'A';
		else return 26+26+c-'0';
	}
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s,int n) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
			cnt[now]++;
		}
	}
	int query(char *s,int n) // s[0..n-1]
	{
		int now,i,t,res;
		now=root;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
		}
		return cnt[now];
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
	int t,n,q,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		tr.init();
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			tr.insert(s,strlen(s));
		}
		while(q--)
		{
			scanf("%s",s);
			printf("%d\n",tr.query(s,strlen(s)));
		}
	}
	return 0;
}
