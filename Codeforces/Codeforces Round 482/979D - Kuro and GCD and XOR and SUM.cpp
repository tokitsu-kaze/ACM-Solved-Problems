#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Trie
{
	#define type int
	static const int LOG=20;
	static const int N=1166750*LOG+1;
	static const type inf=INF;
	int rt,root[MAX],tot,ch[N][2],mn[N];
	Trie &operator[](const int _rt){this->rt=_rt;return *this;}
	int newnode()
	{
		tot++;
		memset(ch[tot],0,sizeof ch[tot]);
		mn[tot]=inf;
		return tot;
	}
	void init(int n=1)
	{
		ch[0][0]=ch[0][1]=0;
		mn[0]=inf;
		tot=1;
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
	}
	void insert(type x)
	{
		int id,t,i;
		if(!root[rt]) root[rt]=newnode();
		id=root[rt];
		for(i=LOG;~i;i--)
		{
			mn[id]=min(mn[id],x);
			t=(x>>i)&1;
			if(!ch[id][t]) ch[id][t]=newnode();
			id=ch[id][t];
		}
		mn[id]=min(mn[id],x);
	}
	type ask_max(type x,type s)
	{
		int id,i,tmp;
		type res,t;
		if(!root[rt]) return -1;
		id=root[rt];
		res=0;
		for(i=LOG;~i;i--)
		{
			if(!id) return -1;
			t=(x>>i)&1;
			tmp=ch[id][t^1];
			if(tmp && mn[tmp]+x<=s) t^=1;
			res|=(t<<i);
			id=ch[id][t];
		}
		if(res+x>s) return -1;
		return res;
	}
	#undef type
}tr;
vector<int> res[MAX];
void init(int n)
{
	int i,j,mx,sum;
	mx=sum=0;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j+=i) res[j].push_back(i);
		mx=max(mx,(int)res[i].size());
		sum+=res[i].size();
	}
//	cout<<mx<<endl;
//	cout<<sum<<endl;
}
bool vis[MAX];
int main()
{
	int q,op,i,x,k,s;
	init(MAX-10);
	tr.init(MAX-10);
	memset(vis,0,sizeof vis);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&x);
			if(vis[x]) continue;
			vis[x]=1;
			for(auto &it:res[x]) tr[it].insert(x);
		}
		else
		{
			scanf("%d%d%d",&x,&k,&s);
			if(x%k) puts("-1");
			else printf("%d\n",tr[k].ask_max(x,s));
		}
	}
	return 0;
}
