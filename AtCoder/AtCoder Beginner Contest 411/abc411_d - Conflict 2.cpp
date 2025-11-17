#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Trie
{
	#define type int
	static const int K=26;
	char v[MAX];
	int nex[MAX][K],fa[MAX];
	int root,tot;
	int getid(char c){return c-'a';}
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		fa[tot]=0;
		return tot;
	}
	void init()
	{
		tot=0;
		memset(nex[0],0,sizeof nex[0]);
		fa[0]=0;
		root=newnode();
	}
	void insert(char *s,int n,int &now) // s[0..n-1]
	{
		int i,t;
		for(i=0;i<n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			fa[nex[now][t]]=now;
			now=nex[now][t];
			v[now]=t+'a';
		}
	}
	#undef type
}tr;
/*
tr.init();
tr.insert(s,len); s[0..len-1]
*/
char s[MAX];
int pos[MAX];
int main()
{
	int n,i,q,op,p,now;
	tr.init();
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) pos[i]=tr.root;
	now=tr.root;
	while(q--)
	{
		scanf("%d%d",&op,&p);
		if(op==1) pos[p]=now;
		else if(op==2)
		{
			scanf("%s",s);
			tr.insert(s,strlen(s),pos[p]);
		}
		else if(op==3) now=pos[p];
	}
	string res;
	while(now!=tr.root)
	{
		res+=tr.v[now];
		now=tr.fa[now];
	}
	reverse(res.begin(),res.end());
	cout<<res<<"\n";
	return 0;
}
