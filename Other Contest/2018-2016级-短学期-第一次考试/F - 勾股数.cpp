#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
struct node
{
    ll a[5];
    node(){}
    node(ll x,ll y,ll z)
    {
        a[0]=x;
        a[1]=y;
        a[2]=z;
    }
    friend bool operator ==(node a,node b)
    {
        return a.a[0]==b.a[0]&&a.a[1]==b.a[1]&&a.a[2]==b.a[2];
    }
    friend bool operator <(node a,node b)
    {
        if(a.a[0]==b.a[0])
        {
            if(a.a[1]==b.a[1])
            {
                return a.a[2]<b.a[2];
            }
            return a.a[1]<b.a[1];
        }
        return a.a[0]<b.a[0];
    }
};
int main()
{
    ll i,j,a,b,c;
    vector<node> res;
    for(i=1;i<=1000000;i++)
    {
        for(j=i+1;j<=1000000;j++)
        {
            if(2*i*j>1000000) break;
            if(i*i+j*j>1000000) break;
            a=(j*j-i*i);
            b=2*i*j;
            c=j*j+i*i;
            if(a>b) swap(a,b);
            if(__gcd(__gcd(a,b),c)!=1) continue;
            res.pb(node(a,b,c));

        }
    }
    sort(all(res));
    res.resize(unique(all(res))-res.begin());
//    cout<<sz(res)<<endl;
    ll n,l,r;
    while(~scanf("%lld%lld%lld",&n,&l,&r))
    {
        l--;
        r--;
        vector<node> tmp,ans;
        for(auto it:res)
        {
            if(it.a[2]<n) ans.pb(it);
        }
        for(i=l;i<min(r+1,(ll)sz(ans));i++)
        {
            tmp.pb(ans[i]);
        }
        printf("%d\n",sz(tmp));
        int cas=0;
        for(i=0;i<sz(tmp);i++)
        {
            printf("Case: %d a=%lld,b=%lld,c=%lld\n",++cas,tmp[i].a[0],tmp[i].a[1],tmp[i].a[2]);
        }
    }
    return 0;
}