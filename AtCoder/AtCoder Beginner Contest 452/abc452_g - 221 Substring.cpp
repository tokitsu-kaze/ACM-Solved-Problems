#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct Suffix_Automaton
{
	static const int N=MAX<<1;
	static const int K=10;// char size
	int tot,lst,nex[N][K],fa[N],len[N],cnt[N],mxlen,root;
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
		mxlen=0;
		root=lst=newnode();
	}
	void add(int x)
	{
		int p,q,np,nq;
		if(nex[lst][x])
		{
			p=lst;
			q=nex[lst][x];
			if(len[q]==len[p]+1) lst=q;
			else
			{
				nq=lst=newnode();
				memcpy(nex[nq],nex[q],sizeof(nex[q]));
				len[nq]=len[p]+1;
				mxlen=max(mxlen,len[nq]);
				fa[nq]=fa[q];
				fa[q]=nq;
				while(p&&nex[p][x]==q)
				{
					nex[p][x]=nq;
					p=fa[p];
				}
			}
		}
		else
		{
			p=lst;
			np=lst=newnode();
			len[np]=len[p]+1;
			mxlen=max(mxlen,len[np]);
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
					mxlen=max(mxlen,len[nq]);
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
	}
	void insert(int *s,int n)
	{
		int i;
		lst=root;
		for(i=1;i<=n;i++)
		{
			add(s[i]);
//			printf("%d%c",s[i]," \n"[i==n]);
		}
	}
	ll dp[N];
	ll dfs(int x)
	{
		if(dp[x]!=-1) return dp[x];
		dp[x]=0;
		for(int i=0;i<K;i++)
		{
			if(nex[x][i]) dp[x]+=dfs(nex[x][i])+1;
		}
		return dp[x];
	}
	void ask()
	{
		memset(dp,-1,sizeof dp);
		printf("%lld\n",dfs(root));
	}
}sam;
int a[MAX],res[MAX];
int main()
{
	int n,i,cnt,tot;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=a[n+1]=INF;
	cnt=0;
	tot=0;
	sam.init();
	for(i=1;i<=n+1;i++)
	{
		if(a[i]==a[i-1])
		{
			cnt++;
			if(cnt>a[i])
			{
				res[++tot]=a[i];
				sam.insert(res,tot);
				tot=0;
			}
		}
		else
		{
			if(cnt>=a[i-1]) res[++tot]=a[i-1];
			else
			{
				sam.insert(res,tot);
				tot=0;
			}
			cnt=1;
		}
	}
	sam.insert(res,tot);
	sam.ask();
	return 0;
}
