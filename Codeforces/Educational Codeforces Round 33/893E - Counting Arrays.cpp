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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=1e9+7;
ll fac[MAX],flag[MAX];
void init()
{
	ll i,j;
	fac[0]=1;
	for(i=1;i<=(ll)2e6;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		flag[i]=0;
	}
	for(i=2;i<=(ll)2e6;i++)
	{
		if(!flag[i])
		{
			flag[i]=i;
			for(j=i+i;j<=(ll)2e6;j+=i)
			{
				if(!flag[j]) flag[j]=i;
			}
		}
	}
//	for(i=0;i<sz(p);i++) cout<<p[i]<<endl;
}
ll pow2(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x)
{
	return pow2(x,mod-2);
}
ll C(ll n,ll m)
{
	if(m>n||m<0) return 0;
	return fac[n]*inv(fac[m]*fac[n-m]%mod)%mod;
}
vector<ll> res;
void dfs(ll x)
{
	if(x==1) return;
	ll cnt=0,temp=flag[x];
//	cout<<x<<" "<<temp<<endl;
	while(x%temp==0&&x>1)
	{
		x/=temp;
		cnt++;
	}
	res.pb(cnt);
	dfs(x);
}
int main()
{
	int t;
	ll ans,x,y,i,cnt;
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&x,&y);
		ans=pow2(2,y-1);
		res.clear();
		dfs(x);
		for(i=0;i<sz(res);i++)
		{
			ans=(ans*C(res[i]+y-1,y-1))%mod;
	//		cout<<res[i]<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}