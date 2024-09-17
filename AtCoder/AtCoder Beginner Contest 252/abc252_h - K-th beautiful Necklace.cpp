#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
struct Trie
{
	#define type ll
	static const int LOG=60;
	static const int K=LOG+2;
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
	type kth(type k,vector<ll> &b)
	{
		int i,j;
		type res,now;
		vector<int> pos(b.size(),root[rt]);
		res=0;
		for(i=LOG;~i;i--)
		{
			now=0;
			j=0;
			for(auto &it:pos)
			{
				now+=cnt[ch[it][(b[j]>>i)&1]];
				j++;
			}
	//		debug(i,now)
			if(now<k)
			{
				res|=(1LL<<i);
				k-=now;
				j=0;
				for(auto &it:pos)
				{
					it=ch[it][!((b[j]>>i)&1)];
					j++;
				}
			}
			else
			{
				j=0;
				for(auto &it:pos)
				{
					it=ch[it][(b[j]>>i)&1];
					j++;
				}
			}
		}
		return res;
	}
	#undef type
}tr;
const int LIMT=4e5;
vector<ll> a[77],res;
void dfs(int x,ll now,vector<int> &id,bool f)
{
	if(x==id.size())
	{
		if(!f) tr.insert(now);
		else res.push_back(now);
		return;
	}
	for(auto &it:a[id[x]]) dfs(x+1,now^it,id,f);
}
int main()
{
	srand(time(0));
	int n,c,i,d,random_cnt,now,mx;
	ll k,v,tot;
	scanf("%d%d%lld",&n,&c,&k);
	for(i=1;i<=c;i++) a[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d%lld",&d,&v);
		a[d].push_back(v);
	}
	vector<int> id,ra,rb,ta,tb;
	tot=1;
	for(i=1;i<=c;i++)
	{
		if(a[i].size())
		{
			id.push_back(i);
			tot*=a[i].size();
		}
	}
	
	random_cnt=50;
	mx=0;
	while(random_cnt--)
	{
		random_shuffle(id.begin(),id.end());
		now=1;
		ta.clear();
		tb.clear();
		for(auto &it:id)
		{
			if(1LL*now*a[it].size()<=LIMT)
			{
				now*=a[it].size();
				ta.push_back(it);
			}
			else tb.push_back(it);
		}
		if(now>mx)
		{
			swap(now,mx);
			swap(ta,ra);
			swap(tb,rb);
		}
	}
//	debug(ra)
//	debug(rb)
	tr.init();
	dfs(0,0,ra,0);
	
	res.clear();
	dfs(0,0,rb,1);
	if(res.size()==0) res.push_back(0);
	printf("%lld\n",tr.kth(tot-k+1,res));
	return 0;
}
