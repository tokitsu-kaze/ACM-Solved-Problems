#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
#define VI vector<int>
#define VL vector<ll>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=5e5+10;
const ll mod=998244353;
ll x,y,p;
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b>>=1;
	}
	return res;
}
map<ll,PLL> pre[2];
map<ll,int> flag[2];
queue<ll> q[2];
void add(ll t,ll a,int id,ll tag)
{
	if(!flag[id][a])
	{
		q[id].push(a);
		flag[id][a]=1;
		pre[id][a]=MP(t,tag);
	}
}
VL res;
void gao(ll t)
{
	ll tmp=t;
	while(t!=x)
	{
		res.pb(pre[0][t].se);
		t=pre[0][t].fi;
	}
	reverse(all(res));
	t=tmp;
	while(t!=y)
	{
		res.pb(pre[1][t].se);
		t=pre[1][t].fi;
	}
} 
void bfs()
{
	ll t,sz;
	for(int i=0;i<2;i++)
	{
		pre[i].clear();
		flag[i].clear();
		while(sz(q[0])) q[0].pop();
		while(sz(q[1])) q[1].pop();
	}
	q[0].push(x);
	q[1].push(y);
	flag[0][x]=1;
	flag[1][y]=1;
	pre[0][x]=MP(x,0);
	pre[1][y]=MP(y,0);
	res.clear();
	while(!q[0].empty()||!q[1].empty())
	{
		sz=sz(q[0]);
		while(sz--)
		{
			t=q[0].front();
			q[0].pop();
			if(flag[1][t])
			{
				gao(t);
				return;
			}
			add(t,(t+1)%mod,0,1);
			add(t,(t-1+mod)%mod,0,2);
			add(t,pow2(t,p-2),0,3);
		}
		sz=sz(q[1]);
		while(sz--)
		{
			t=q[1].front();
			q[1].pop();
			if(flag[0][t])
			{
				gao(t);
				return;
			}
			add(t,(t+1)%mod,1,2);
			add(t,(t-1+mod)%mod,1,1);
			add(t,pow2(t,p-2),1,3);
		}
	}
} 
int main()
{
	while(~scanf("%lld%lld%lld",&x,&y,&p))
	{
		bfs();
		printf("%d\n",sz(res));
		for(int i=0;i<sz(res);i++) printf("%lld%c",res[i]," \n"[i==sz(res)-1]);
	}
	return 0;
}