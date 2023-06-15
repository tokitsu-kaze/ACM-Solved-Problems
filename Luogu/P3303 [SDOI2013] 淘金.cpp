#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
struct hash_map
{
    static const int p=999917;
    ll val[MAX],w[MAX];
    int tot,head[p],nex[MAX];
    int top,st[MAX];
    void clear(){tot=0;while(top) head[st[top--]]=0;}
    void add(int x,ll y){val[++tot]=y;nex[tot]=head[x];head[x]=tot;w[tot]=0;}
    bool count(ll y)
    {
        int x=y%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return 1;
		}
        return 0;
    }
    ll& operator [](ll y)
    {
        int x=y%p;
        for(int i=head[x];i;i=nex[i])
        {
			if(y==val[i]) return w[i];
		}
        add(x,y);
        st[++top]=x;
		return w[tot];
    }
};
const int mod=1e9+7;
vector<ll> get_status(ll n)
{
	ll i,j,k,l;
	vector<ll> res;
	for(i=1;i<=n;i*=2)
	{
		for(j=1;i*j<=n;j*=3)
		{
			for(k=1;i*j*k<=n;k*=5)
			{
				for(l=1;i*j*k*l<=n;l*=7)
				{
					res.push_back(i*j*k*l);
				}
			}
		}
	}
	return res;
}
const int DIG=13+1;
hash_map dp[DIG];
ll pow9[DIG];
ll gao(ll x,ll k)
{
	const int base=10;
	int p[DIG],tot=0;
	if(x==-1) return 0;
	while(1)
	{
		p[tot++]=x%base;
		x/=base;
		if(!x) break;
	}
	function<ll(int,int,ll,int)> dfs=[&](int pos,int lead,ll now,int limt)->ll
	{
		if(pos==-1) return !lead&&now==1;
		if(now>pow9[pos]) return 0;
		if(!limt&&!lead&&dp[pos].count(now)) return dp[pos][now];
		ll res=0;
		for(int i=(limt?p[pos]:base-1);~i;i--)
		{
			if(!lead&&i==0) continue;
			if(i&&now%i) continue;
			res+=dfs(pos-1,
					 lead&&i==0,
					 (lead&&i==0)?now:now/i,
					 limt&&i==p[pos]);
		}
		if(!limt&&!lead) dp[pos][now]=res;
		return res;
	};
	return dfs(tot-1,1,k,1);
}
vector<ll> status,res;
struct node
{
	ll i,j;
	friend bool operator <(node a,node b)
	{
		return 1.0*res[a.i]/res[b.j]<1.0*res[b.i]/res[a.j];
	}
};
int main()
{
	int i,k;
	ll n,ans;
	pow9[0]=9;
	for(i=1;i<DIG;i++) pow9[i]=pow9[i-1]*9;
	scanf("%lld%d",&n,&k);
	status=get_status(n);
	res.clear();
	for(auto &it:status)
	{
		for(i=0;i<DIG;i++) dp[i].clear();
		res.push_back(gao(n,it));
	//	printf("%lld %lld\n",it,gao(n,it));
	}
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	priority_queue<node> q;
	for(i=0;i<res.size();i++) q.push({i,0});
	ans=0;
	while(k--&&!q.empty())
	{
		node t=q.top();
		q.pop();
		ans=(ans+(res[t.i]%mod)*(res[t.j]%mod))%mod;
		if(t.j+1<res.size())
		{
			t.j++;
			q.push(t);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
1000000000000 12
*/
