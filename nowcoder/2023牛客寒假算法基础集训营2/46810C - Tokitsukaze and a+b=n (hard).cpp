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
int l[MAX],r[MAX];
ll bit[MAX];
int cal(int a,int b,int c,int d)
{
	return max(0,min(d,b)-max(a,c)+1);
}
int main()
{
	int n,m,i,nl,nr;
	ll ans;
	scanf("%d%d",&n,&m);
	mem(bit,0);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		bit[l[i]]++;
		bit[r[i]+1]--;
	}
	for(i=1;i<=n;i++) bit[i]=(bit[i]+bit[i-1])%mod;
	for(i=1;i<=n;i++) bit[i]=(bit[i]+bit[i-1])%mod;
	ans=0;
	for(i=1;i<=m;i++)
	{
		nl=n-r[i];
		nr=n-l[i];
		if(nl>nr || nr<=0) continue;
		if(nl<=0) nl=1;
		ans=(ans+bit[nr]-bit[nl-1]-cal(l[i],r[i],nl,nr))%mod;
	}
	if(ans<0) ans+=mod;
	printf("%lld\n",ans);
	return 0;
}

