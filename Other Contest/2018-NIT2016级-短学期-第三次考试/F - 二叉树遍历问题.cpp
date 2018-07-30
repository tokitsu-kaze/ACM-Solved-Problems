#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int)x.length()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
ll pow2(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    int t,i,j,pre,cnt;
    scanf("%d",&t);
    int pos[333];
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        int tot=0;
        for(i=0;i<len(a);i++) pos[a[i]]=++tot;
        cnt=0;
        for(i=1;i<len(b);i++)
        {
            if(pos[b[i-1]]-pos[b[i]]==1) cnt++;
        }
        printf("%lld\n",pow2(2,cnt));
    }
    return 0;
}

