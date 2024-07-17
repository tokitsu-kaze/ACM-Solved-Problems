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
		if(p==0) fa[np]=1;
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
	int bit[MAX];
	void ask(int n,int k)
	{
		int i,mx,pos;
		memset(bit,0,sizeof bit);
		for(i=root;i<=tot;i++)
		{
			if(cnt[i]==k)
			{
				bit[len[fa[i]]+1]+=cnt[i];
				bit[len[i]+1]-=cnt[i];
			}
		}
		mx=0;
		pos=-1;
		for(i=1;i<=n;i++)
		{
			bit[i]+=bit[i-1];
			if(bit[i]>=mx)
			{
				mx=bit[i];
				pos=i;
			}
		}
		if(mx==0) pos=-1;
		printf("%d\n",pos);
	}
}sam;
/*
sam.init();
sam.add(int x);
sam.topsort();
*/
char s[MAX];
int main()
{
	int t,n,k,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",s+1,&k);
		n=strlen(s+1);
		sam.init();
		for(i=1;i<=n;i++) sam.add(s[i]-'a');
		sam.topsort();
		sam.ask(n,k);
	}
	return 0;
}
