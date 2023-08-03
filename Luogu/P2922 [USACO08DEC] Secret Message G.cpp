#include <bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
struct Trie
{
	#define type int
	static const int K=2;
	int nex[MAX][K],cnt[MAX],lst[MAX];
	int root,tot;
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=lst[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(int *s,int n) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		for(i=0;i<n;i++)
		{
			t=s[i];
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
			cnt[now]++;
		}
		cnt[now]--;
		lst[now]++;
	}
	type ask(int *s,int n) // s[0..n-1]
	{
		int now,i,t,res;
		now=root;
		res=0;
		for(i=0;i<n;i++)
		{
			t=s[i];
			if(!nex[now][t]) return res;
			now=nex[now][t];
			res+=lst[now];
		}
		return res+cnt[now];
	}
	#undef type
}tr;
/*
tr.init();
tr.insert(s,len); s[0..len-1]
*/
int s[MAX];
int main()
{
	int n,m,k,i;
	scanf("%d%d",&n,&m);
	tr.init();
	while(n--)
	{
		scanf("%d",&k);
		for(i=0;i<k;i++) scanf("%d",&s[i]);
		tr.insert(s,k);
	}
	while(m--)
	{
		scanf("%d",&k);
		for(i=0;i<k;i++) scanf("%d",&s[i]);
		printf("%d\n",tr.ask(s,k));
	}
	return 0;
}
