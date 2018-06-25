////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-12 10:09:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6146
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:2896KB
//////////////////System Comment End//////////////////
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
const int MAX=1e5+10;
const ll mod=1e9+7;
typedef vector<int> VI;
namespace linear_seq
{
	#define rep(i,a,n) for (int i=a;i<n;i++)
	#define SZ(x) ((int)(x).size())
	const ll mod=1e9+7;
	ll powmod(ll a,ll b){ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
	const int N=10010;
	ll res[N],base[N],_c[N],_md[N];
	vector<int> Md;
	void mul(ll *a,ll *b,int k)
	{
		rep(i,0,k+k) _c[i]=0;
		rep(i,0,k) if (a[i]) rep(j,0,k) _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
		for (int i=k+k-1;i>=k;i--) if (_c[i])
			rep(j,0,SZ(Md)) _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%mod;
		rep(i,0,k) a[i]=_c[i];
	}
	int solve(ll n,VI a,VI b){
		ll ans=0,pnt=0;
		int k=SZ(a);
		assert(SZ(a)==SZ(b));
		rep(i,0,k) _md[k-1-i]=-a[i];_md[k]=1;
		Md.clear();
		rep(i,0,k) if (_md[i]!=0) Md.push_back(i);
		rep(i,0,k) res[i]=base[i]=0;
		res[0]=1;
		while ((1ll<<pnt)<=n) pnt++;
		for (int p=pnt;p>=0;p--) {
			mul(res,res,k);
			if ((n>>p)&1) {
				for (int i=k-1;i>=0;i--) res[i+1]=res[i];res[0]=0;
				rep(j,0,SZ(Md)) res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%mod;
			}
		}
		rep(i,0,k) ans=(ans+res[i]*b[i])%mod;
		if (ans<0) ans+=mod;
		return ans;
	}
	VI BM(VI s){
		VI C(1,1),B(1,1);
		int L=0,m=1,b=1;
		rep(n,0,SZ(s)){
			ll d=0;
			rep(i,0,L+1) d=(d+(ll)C[i]*s[n-i])%mod;
			if(d==0) ++m;
			else if(2*L<=n){
				VI T=C;
				ll c=mod-d*powmod(b,mod-2)%mod;
				while (SZ(C)<SZ(B)+m) C.pb(0);
				rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
				L=n+1-L; B=T; b=d; m=1;
			} else {
				ll c=mod-d*powmod(b,mod-2)%mod;
				while (SZ(C)<SZ(B)+m) C.pb(0);
				rep(i,0,SZ(B)) C[i+m]=(C[i+m]+c*B[i])%mod;
				++m;
			}
		}
		return C;
	}
	int gao(VI a,ll n)
	{
		VI c=BM(a);
		c.erase(c.begin());
		rep(i,0,SZ(c)) c[i]=(mod-c[i])%mod;
		return solve(n,c,VI(a.begin(),a.begin()+SZ(c)));
	}
};
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",linear_seq::gao(VI{2,24,96,416,1536,5504,18944,64000,212992,702464},n-1));
	} 
	return 0;
}