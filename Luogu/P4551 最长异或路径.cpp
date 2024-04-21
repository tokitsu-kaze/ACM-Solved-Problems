#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=6e5+10;
struct Trie
{
	#define type int
	static const int LOG=30;
	static const int K=LOG+2;
	int root,tot,nex[MAX*K][2],cnt[MAX*K];
	int newnode()
	{
		tot++;
		memset(nex[tot],0,sizeof nex[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init()
	{
		nex[0][0]=nex[0][1]=cnt[0]=tot=0;
		root=newnode();
	}
	void insert(type x)
	{
		int id,t,i;
		id=root;
		for(i=LOG;~i;i--)
		{
			cnt[id]++;
			t=(x>>i)&1;
			if(!nex[id][t]) nex[id][t]=newnode();
			id=nex[id][t];
		}
		cnt[id]++;
	}
	type ask_max(type x)
	{
		int id,t,i;
		type res;
		id=root;
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(nex[id][t^1]&&cnt[nex[id][t^1]]) t^=1;
			res|=(t<<i);
			id=nex[id][t];
		}
		return res^x;
	}
	#undef type
}tr;
struct node{int to,w;};
vector<node> mp[MAX];
int res[MAX];
void dfs(int x,int fa,int now)
{
	res[x]=now;
	tr.insert(now);
	for(auto &it:mp[x])
	{
		if(it.to==fa) continue;
		dfs(it.to,x,now^it.w);
	}
}
int main()
{
	int n,i,a,b,w,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) mp[i].clear();
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		mp[a].push_back({b,w});
		mp[b].push_back({a,w});
	}
	tr.init();
	res[0]=0;
	dfs(1,0,0);
	ans=0;
	for(i=1;i<=n;i++) ans=max(ans,tr.ask_max(res[i]));
	printf("%d\n",ans);
	return 0;
}
