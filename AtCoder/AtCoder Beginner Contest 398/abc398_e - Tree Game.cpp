#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
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
int mp[105][105];
int main()
{
	int n,i,j,k,a,b,f;
	scanf("%d",&n);
	memset(mp,0,sizeof mp);
	lca.init(n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		lca.add_edge(a,b,1);
		lca.add_edge(b,a,1);
		mp[a][b]=mp[b][a]=1;
	}
	lca.work(1);
	set<pair<int,int>> s;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(mp[i][j]) continue;
			if(lca.get_len(i,j)&1) s.insert({i,j});
		}
	}
	if(s.size()&1) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	f=(s.size()&1);
	while(s.size()>0)
	{
		if(f)
		{
			a=(*s.begin()).first;
			b=(*s.begin()).second;
			cout<<a<<" "<<b<<endl;
		}
		else cin>>a>>b;
		if(a==-1 && b==-1) break;
		if(a>b) swap(a,b);
		s.erase({a,b});
		f^=1;
	}
	return 0;
}

