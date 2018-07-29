#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
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
const int MAX=400*400+10;
const ll mod=1e9+7;
int main()
{
    int t;
    ll n,a,b,c,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        a=n/5;
        b=n/7;
        c=n/35;
        ans=0;
        if(a) ans+=(5+a*5)*(a)/2;
        if(b) ans+=(7+b*7)*(b)/2;
        if(c) ans-=(35+c*35)*(c)/2;
        printf("%lld\n",ans);
    }
    return 0;
}