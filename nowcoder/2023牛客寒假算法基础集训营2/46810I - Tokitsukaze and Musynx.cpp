#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<string> VS;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=4e5+10;
const ll mod=998244353;
/********************************* std-head *********************************/
int n,a,b,c,d,v[6];
VL x;
ll gao(ll delta)
{
	int i,pos,pre;
	ll res,now,tmp;
	res=-LLINF;
	for(i=0;i<n;i++)
	{
		now=0;
		pre=0;
		tmp=x[i]-delta;
		pos=upper_bound(all(x),tmp)-x.begin();
		now+=1ll*(pos-pre)*v[1];
		pre=pos;
		
		tmp+=b-a;
		pos=upper_bound(all(x),tmp)-x.begin();
		now+=1ll*(pos-pre)*v[2];
		pre=pos;
		
		tmp+=c-b;
		pos=upper_bound(all(x),tmp)-x.begin();
		now+=1ll*(pos-pre)*v[3];
		pre=pos;
		
		tmp+=d-c+1;
		pos=upper_bound(all(x),tmp)-x.begin();
		now+=1ll*(pos-pre)*v[4];
		pre=pos;
		
		pos=n;
		now+=1ll*(pos-pre)*v[5];
		
		res=max(res,now);
	}
	return res;
}
int main()
{
	int T,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		x=VL(n);
		for(auto &it:x) scanf("%lld",&it);
		x.pb(LLINF);
		sort(all(x));
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(i=1;i<=5;i++) scanf("%d",&v[i]);
		
		ans=-LLINF;
		
		VI tmp;
		tmp.pb(a-1);
		tmp.pb(a);
		tmp.pb(b);
		tmp.pb(c);
		tmp.pb(d+1);
		
		for(auto it:tmp) ans=max(ans,gao(it-(a-1)));
		
		printf("%lld\n",ans);
	}
	return 0;
}


