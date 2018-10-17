#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct Hash_map
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
}mp;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll g,t;
	g=exgcd(b,a%b,x,y);
	t=x;
	x=y;
	y=t-a/b*y;
	return g;
}
ll exBSGS(ll a,ll b,ll c)
{
	ll i,g,d,num,now,sq,t,x,y;
	if(c==1) return b?-1:(a!=1);
	if(b==1) return a?0:-1;
	if(a%c==0) return b?-1:1;
	num=0;
	d=1;
	while((g=__gcd(a,c))>1)
	{
		if(b%g) return -1;
		num++;
		b/=g;
		c/=g;
		d=(d*a/g)%c;
		if(d==b) return num;
	}
	mp.clear();
	sq=ceil(sqrt(c));
	t=1;
	for(i=0;i<sq;i++)
	{
		if(!mp.count(t)) mp[t]=i;
		else mp[t]=min(mp[t],i);
		t=t*a%c;
	}
	for(i=0;i<sq;i++)
	{
		exgcd(d,c,x,y);
		x=(x*b%c+c)%c;
		if(mp.count(x)) return i*sq+mp[x]+num;
		d=d*t%c;
	}
	return -1;
}
ll pow2(ll a,ll b,ll p)
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
ll inv(ll a,ll p)
{
	ll g,x,y;
	g=exgcd(a,p,x,y);
	return g==1?(x+p)%p:-1;
}
void go()
{
	ll t,k,a,b,c,x,y,ans;
	while(~scanf("%lld%lld",&t,&k))
	{
		while(t--)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			if(k==1) printf("%lld\n",pow2(a,b,c));
			else if(k==2)
			{
				ans=inv(a,c);
				if(ans==-1) puts("Orz, I cannot find x!");
				else printf("%lld\n",ans*b%c);
			}
			else
			{
				ans=exBSGS(a,b,c);
				if(ans==-1) puts("Orz, I cannot find x!");
				else printf("%lld\n",ans);
			}
		}
	}
}
