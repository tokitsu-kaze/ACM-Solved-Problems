#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct Trie
{
	#define type int
	static const int LOG=30;
	static const int K=LOG+2;
	static const type inf=INF;
	int rt,root[MAX],tot,ch[MAX*K][2];
	pair<int,int> val[MAX*K];
	Trie &operator[](const int _rt){this->rt=_rt;return *this;}
	int newnode()
	{
		tot++;
		memset(ch[tot],0,sizeof ch[tot]);
		val[tot]={0,0};
		return tot;
	}
	void init(int n=1)
	{
		ch[0][0]=ch[0][1]=0;
		val[0]={0,0};
		tot=1;
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
	}
	void insert(type x,int dp,int pos)
	{
		int id,t,i;
		if(!root[rt]) root[rt]=newnode();
		id=root[rt];
		for(i=LOG;~i;i--)
		{
			val[id]=max(val[id],{dp,pos});
			t=(x>>i)&1;
			if(!ch[id][t]) ch[id][t]=newnode();
			id=ch[id][t];
		}
		val[id]=max(val[id],{dp,pos});
	}
	pair<int,int> ask(type x,type limt)
	{
		int id,i,t;
		if(!root[rt]) return {0,0};
		id=root[rt];
		pair<int,int> res={0,0};
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(!((limt>>i)&1))
			{
				res=max(res,val[ch[id][t^1]]);
				id=ch[id][t];
			}
			else id=ch[id][t^1];
		}
		res=max(res,val[id]);
		return res;
	}
	#undef type
}tr;
int a[MAX],dp[MAX],pre[MAX],id[MAX];
int main()
{
	int n,k,i,ans,pos;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+1+n,[&](int x,int y){
		return a[x]<a[y];
	});
	tr.init();
	for(i=1;i<=n;i++)
	{
		auto it=tr.ask(a[id[i]],k);
		if(it.first+1>dp[i])
		{
			pre[i]=it.second;
			dp[i]=it.first+1;
		}
		tr.insert(a[id[i]],dp[i],i);
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(dp[i]>ans)
		{
			ans=dp[i];
			pos=i;
		}
	}
	if(ans==1)
	{
		puts("-1");
		return 0;
	}
	vector<int> res;
	while(pos)
	{
		res.push_back(id[pos]);
		pos=pre[pos];
	}
	assert(ans==res.size());
	printf("%d\n",ans);
	for(i=0;i<ans;i++) printf("%d%c",res[i]," \n"[i+1==ans]);
	return 0;
}
