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
const double eps=1e-8;
const int MAX=5e5+10;
const ll mod=1e9;
ll a[MAX];
int res[MAX][31];
int main()
{
	int t,n,m,kk;
	ll i,j,now,ans,p,k,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		a[n+1]=LLINF;
		for(i=1;i<=30;i++) res[0][i]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=30;j++)
			{
				res[i][j]=(res[i-1][j]+a[i]/j)%mod;
			}
		}
		ans=0;
		for(i=1;i<=m;i++)
		{
			scanf("%lld",&p);
			now=0;
			l=1;
			k=0;
			j=1;
			while(l<=n)
			{
				kk=log(a[l])/log(p)+eps;
				while(k<kk)
				{
					k++;
					j*=p;
				}
				if(j!=a[l])
				{
					k++;
					j*=p;
					r=upper_bound(a+l,a+2+n,j)-a-1;
				}
				else r=lower_bound(a+l,a+2+n,j)-a;
				now=(now+res[r][k]-res[l-1][k]+mod)%mod;
				l=r+1;
			}
			ans=(ans+i*now)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
