#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
struct Suffix_Automaton
{
	static const int N=MAX<<1;
	static const int K=26;// char size: [0,25]
	int tot,lst,nex[N][K],fa[N],len[N],cnt[N],maxlen,root;
	int newnode()
	{
		tot++;
		fa[tot]=len[tot]=cnt[tot]=0;
		memset(nex[tot],0,sizeof nex[tot]);
		return tot;
	}
	void init()
	{
		fa[0]=len[0]=cnt[0]=0;
		memset(nex[0],0,sizeof nex[0]);
		tot=0;
		maxlen=0;
		root=lst=newnode();
	}
	void add(int x)
	{
		int p,q,np,nq;
		p=lst;
		np=lst=newnode();
		len[np]=len[p]+1;
		maxlen=max(maxlen,len[np]);
		cnt[lst]=1;
		while(p&&!nex[p][x])
		{
			nex[p][x]=np;
			p=fa[p];
		}
		if(p==0) fa[np]=root;
		else
		{
			q=nex[p][x];
			if(len[q]==len[p]+1) fa[np]=q;
			else
			{
				nq=newnode();
				memcpy(nex[nq],nex[q],sizeof(nex[q]));
				len[nq]=len[p]+1;
				maxlen=max(maxlen,len[nq]);
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				while(p&&nex[p][x]==q)
				{
					nex[p][x]=nq;
					p=fa[p];
				}
			}
		}
	}
		int sg[MAX];
	int dfs(int x)
	{
		if(sg[x]!=-1) return sg[x];
		int i,j;
		set<int> flag;
		for(i=0;i<K;i++)
		{
			if(nex[x][i])
			{
				dfs(nex[x][i]);
				flag.insert(sg[nex[x][i]]);
			}
		}
		for(i=0;;i++)
		{
			if(!flag.count(i))
			{
				j=i;
				break;
			}
		}
		return sg[x]=j;
	}
}sam;
/*
sam.init();
sam.add(int x);
*/
char s[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s);
		sam.init();
		n=strlen(s);
		for(i=0;i<n;i++) sam.add(s[i]-'a');
		for(i=0;i<=sam.tot;i++) sam.sg[i]=-1;
		sam.sg[0]=0;
		if(sam.dfs(sam.root)) puts("Alice");
		else puts("Bob");
	}
	return 0;
}
