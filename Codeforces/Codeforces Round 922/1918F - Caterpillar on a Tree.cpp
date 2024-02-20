#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct LCA
{
	static const int N=MAX;
	static const int LOG2N=log2(2*N)+3;
	#define type int
	struct node{int to;type w;};
	type dis[N];
	int path[2*N],deep[2*N],first[N],len[N],tot,n;
	int dp[2*N][LOG2N];
	vector<node> mp[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++)
		{
			dis[i]=len[i]=0;
			mp[i].clear();
		}
	}
	void add_edge(int a,int b,type w=1){mp[a].push_back({b,w});}
	void dfs(int x,int pre,int h)
	{
		int i;
		path[++tot]=x;
		first[x]=tot;
		deep[tot]=h;
		for(i=0;i<mp[x].size();i++)
		{
			int to=mp[x][i].to;
			if(to==pre) continue;
			dis[to]=dis[x]+mp[x][i].w;
			len[to]=len[x]+1;
			dfs(to,x,h+1);
			path[++tot]=x;
			deep[tot]=h;
		}
	}
	void ST(int n)
	{
		int i,j,x,y;
		for(i=1;i<=n;i++) dp[i][0]=i;
		for(j=1;(1<<j)<=n;j++)
		{
			for(i=1;i+(1<<j)-1<=n;i++)
			{
				x=dp[i][j-1];
				y=dp[i+(1<<(j-1))][j-1];
				dp[i][j]=deep[x]<deep[y]?x:y;
			}
		}
	}
	int query(int l,int r)
	{
		int len,x,y;
		len=__lg(r-l+1); 
		x=dp[l][len];
		y=dp[r-(1<<len)+1][len];
		return deep[x]<deep[y]?x:y;
	}
	int lca(int x,int y)
	{
		int l,r,pos;
		l=first[x];
		r=first[y];
		if(l>r) swap(l,r);
		pos=query(l,r);
		return path[pos];
	} 
	type get_dis(int a,int b){return dis[a]+dis[b]-2*dis[lca(a,b)];}
	int get_len(int a,int b){return len[a]+len[b]-2*len[lca(a,b)];}
	void work(int rt)
	{
		tot=0;
		dfs(rt,0,0);
		ST(2*n-1);
	}
	int lca_root(int rt,int x,int y)
	{
		int fx,fy;
		fx=lca(x,rt);
		fy=lca(y,rt);
		if(fx==fy) return lca(x,y);
		else
		{
			if(get_len(fx,rt)<get_len(fy,rt)) return fx;
			else return fy;
		}
	}
	#undef type
}lca;
/*
O(n*log(n))-O(1)

lca.init(n);
lca.add_edge(a,b,w);
lca.work(rt);
*/
vector<int> mp[MAX],leaf;
int dep[MAX],mxdep[MAX];
void dfs(int x,int h)
{
	dep[x]=mxdep[x]=h;
	for(auto &to:mp[x])
	{
		dfs(to,h+1);
		mxdep[x]=max(mxdep[x],mxdep[to]);
	}
}
void dfs2(int x)
{
	sort(mp[x].begin(),mp[x].end(),[&](int a,int b){
		return mxdep[a]<mxdep[b];
	});
	for(auto &to:mp[x]) dfs2(to);
	if(!mp[x].size()) leaf.push_back(x);
}
int main()
{
	int n,k,i,fa,ans,ca;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) mp[i].clear();
	lca.init(n);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&fa);
		mp[fa].push_back(i);
		lca.add_edge(fa,i,1);
	}
	lca.work(1);
	dfs(1,0);
	leaf.clear();
	dfs2(1);
//	for(i=0;i<leaf.size();i++) printf("%d%c",leaf[i]," \n"[i==leaf.size()-1]);
	ans=2*n-2-dep[leaf.back()];
	vector<int> res;
	for(i=1;i<leaf.size();i++)
	{
		ca=lca.lca(leaf[i-1],leaf[i]);
		res.push_back(max(0,lca.get_dis(leaf[i-1],leaf[i])
						   -lca.get_dis(1,leaf[i])));
	}
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	for(i=0;i<res.size()&&k>0;i++,k--) ans-=res[i];
	printf("%d\n",ans);
	return 0;
}
