#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct Trie
{
	#define type int
	static const int K=26;
	int nex[MAX][K],cnt[MAX],tag[MAX];
	int root,tot;
	int getid(char c){return c-'a';}
	vector<int> pos[MAX];
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		pos[tot].clear();
		return tot;
	}
	int ans;
	void init()
	{
		tot=0;
		memset(nex[0],0,sizeof nex[0]);
		cnt[0]=0;
		pos[0].clear();
		root=newnode();
		ans=0;
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
		}
		cnt[now]++;
		for(auto &it:pos[now])
		{
			ans-=tag[it];
			tag[it]=0;
		}
		pos[now].clear();
	}
	void ask(char *s,int n,int id) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		ans++;
		tag[id]=1;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
			if(cnt[now])
			{
				tag[id]=0;
				ans--;
				return;
			}
			pos[now].push_back(id);
		}
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
	int q,op,i,len;
	scanf("%d",&q);
	tr.init();
	for(i=1;i<=q;i++)
	{
		scanf("%d%s",&op,s);
		tr.tag[i]=0;
		len=strlen(s);
		if(op==1) tr.insert(s,len);
		else tr.ask(s,len,i);
		printf("%d\n",tr.ans);
	}
	return 0;
}
