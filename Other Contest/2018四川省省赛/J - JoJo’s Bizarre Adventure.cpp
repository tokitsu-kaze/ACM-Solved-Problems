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
const int MAX=1e6+10;
const int mod=1e9+7;
int x[MAX];
int main()
{
    int t,n,i,ans,tt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        tt=n*(n-1)/2;
        for(i=0;i<tt;i++)
        {
            scanf("%d",&x[i]);
        }
        vector<int> res;
        hash_map<int,int> mp;
        ans=0;
        while((int)sz(res)<n-2)
        {
            while(mp[x[ans]]&&ans<tt) mp[x[ans++]]--;
            for(i=0;i<sz(res);i++) mp[res[i]+x[ans]]++;
            res.pb(x[ans]);
            ans++;
    /*      for(auto it:res) cout<<(it)<<" ";
            puts("");*/
        }
        while(mp[x[ans]]&&ans<tt) mp[x[ans++]]--;
        printf("%d\n",min(ans+1,tt));
    }
    return 0;
}