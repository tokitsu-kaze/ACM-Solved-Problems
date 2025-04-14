#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Trie
{
	#define type int
	static const int LOG=30;
	static const int K=LOG+2;
	static const type inf=INF;
	int rt,root[MAX],tot,ch[MAX*K][2],cnt[MAX*K],mx[MAX*K];
	Trie &operator[](const int _rt){this->rt=_rt;return *this;}
	int newnode()
	{
		tot++;
		memset(ch[tot],0,sizeof ch[tot]);
		cnt[tot]=0;
		mx[tot]=-inf;
		return tot;
	}
	void init(int n=1)
	{
		ch[0][0]=ch[0][1]=cnt[0]=0;
		mx[0]=-inf;
		tot=1;
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
	}
	void insert(type x,int pos)
	{
		int id,t,i;
		if(!root[rt]) root[rt]=newnode();
		id=root[rt];
		for(i=LOG;~i;i--)
		{
			cnt[id]++;
			mx[id]=max(mx[id],pos);
			t=(x>>i)&1;
			if(!ch[id][t]) ch[id][t]=newnode();
			id=ch[id][t];
		}
		cnt[id]++;
		mx[id]=max(mx[id],pos);
	}
	type ask(type x,type k)
	{
		int id,i,t;
		type res;
		if(!root[rt]) return -inf;
		id=root[rt];
		res=-inf;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(!((k>>i)&1))
			{
				res=max(res,mx[ch[id][t^1]]);
				id=ch[id][t];
			}
			else id=ch[id][t^1];
		}
		res=max(res,mx[id]);
		return res;
	}
	#undef type
}tr;
int main()
{
	int T,n,k,i,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		tr.init();
		ans=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans=min(ans,i-tr.ask(x,k)+1);
//			cout<<i<<" "<<tr.ask(x,k)<<endl;
			tr.insert(x,i);
		}
		if(k==0) ans=1;
		if(ans==INF) ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}

