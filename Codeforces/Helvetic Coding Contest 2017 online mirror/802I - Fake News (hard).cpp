#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
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
	int sum[N],tp[N];
	void topsort()
	{
		int i;
		for(i=1;i<=maxlen;i++) sum[i]=0;
		for(i=1;i<=tot;i++) sum[len[i]]++;
		for(i=1;i<=maxlen;i++) sum[i]+=sum[i-1];
		for(i=1;i<=tot;i++) tp[sum[len[i]]--]=i;
		for(i=tot;i;i--) cnt[fa[tp[i]]]+=cnt[tp[i]];
	}
	void work()
	{
		int i;
		ll ans=0;
		for(i=1;i<=tot;i++) ans+=1LL*cnt[i]*cnt[i]*(len[i]-len[fa[i]]);
		printf("%lld\n",ans);
	}
}sam;
/*
sam.init();
sam.add(int x);
*/
char s[MAX];
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		sam.init();
		for(i=1;i<=n;i++) sam.add(s[i]-'a');
		sam.topsort();
		sam.work();
	}
	return 0;
}