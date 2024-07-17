#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
struct Suffix_Automaton
{
	static const int N=MAX<<1;
	map<int,int> nex[N];
	int tot,lst,fa[N],len[N],cnt[N],maxlen,root;
	int newnode()
	{
		tot++;
		fa[tot]=len[tot]=cnt[tot]=0;
		nex[tot].clear();
		return tot;
	}
	void init()
	{
		fa[0]=len[0]=cnt[0]=0;
		nex[0].clear();
		tot=0;
		maxlen=0;
		root=lst=newnode();
	}
	int add(int x)
	{
		int p,q,np,nq;
		p=lst;
		np=lst=newnode();
		len[np]=len[p]+1;
		maxlen=max(maxlen,len[np]);
		cnt[lst]=1;
		while(p&&!nex[p].count(x))
		{
			nex[p][x]=np;
			p=fa[p];
		}
		if(p==0) fa[np]=1;
		else
		{
			q=nex[p][x];
			if(len[q]==len[p]+1) fa[np]=q;
			else
			{
				nq=newnode();
				nex[nq]=nex[q];
				len[nq]=len[p]+1;
				maxlen=max(maxlen,len[nq]);
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				while(p && nex[p].count(x) && nex[p][x]==q)
				{
					nex[p][x]=nq;
					p=fa[p];
				}
			}
		}
		return len[lst]-len[fa[lst]];
	}
}sam;
/*
sam.init();
sam.add(int x);
*/
int main()
{
	int n,i,x;
	ll ans;
	scanf("%d",&n);
	sam.init();
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans+=sam.add(x);
		printf("%lld\n",ans);
	}
	return 0;
}
