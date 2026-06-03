#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Trie
{
	#define type int
	static const int LOG=20;
	static const int K=LOG+2;
	static const type inf=INF;
	int rt,root[MAX],tot,ch[MAX*K][2],cnt[MAX*K];
	Trie &operator[](const int _rt){this->rt=_rt;return *this;}
	int newnode()
	{
		tot++;
		memset(ch[tot],0,sizeof ch[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init(int n=1)
	{
		ch[0][0]=ch[0][1]=cnt[0]=0;
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
			cnt[id]++;
			t=(x>>i)&1;
			if(!ch[id][t]) ch[id][t]=newnode();
			id=ch[id][t];
		}
		cnt[id]++;
	}
	type ask_max(type x)
	{
		int id,i;
		type res,t;
		if(!root[rt]) return -inf;
		id=root[rt];
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(ch[id][t^1]&&cnt[ch[id][t^1]]) t^=1;
			res|=(t<<i);
			id=ch[id][t];
		}
		return res^x;
	}
	type ask_min(type x)
	{
		int id,i;
		type res,t;
		if(!root[rt]) return inf;
		id=root[rt];
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(!ch[id][t]||!cnt[ch[id][t]]) t^=1;
			res|=(t<<i);
			id=ch[id][t];
		}
		return res^x;
	}
	#undef type
}tr;
int premx[MAX],premn[MAX],sufmx[MAX],sufmn[MAX],a[MAX];
int main()
{
	int n,i,now,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	premn[0]=INF;
	premx[0]=-INF;
	now=0;
	tr.init();
	tr.insert(now);
	for(i=1;i<=n;i++)
	{
		now^=a[i];
		premn[i]=min(premn[i-1],tr.ask_min(now));
		premx[i]=max(premx[i-1],tr.ask_max(now));
		tr.insert(now);
		
	}
	sufmn[n+1]=INF;
	sufmx[n+1]=-INF;
	now=0;
	tr.init();
	tr.insert(now);
	for(i=n;i;i--)
	{
		now^=a[i];
		sufmn[i]=min(sufmn[i+1],tr.ask_min(now));
		sufmx[i]=max(sufmx[i+1],tr.ask_max(now));
		tr.insert(now);
	}
	ans=0;
	for(i=1;i<n;i++)
	{
		ans=max(ans,premx[i]-sufmn[i+1]);
		ans=max(ans,sufmx[i+1]-premn[i]);
	}
	printf("%d\n",ans);
	return 0;
}
