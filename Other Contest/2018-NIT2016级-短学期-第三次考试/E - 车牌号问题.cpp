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
int main()
{
    ll n,stp,pos[333],i,tot,now,lim;
    char re[333];
    string s;
    mem(pos,0);
    for(i=0;i<=9;i++) pos[i+'0']=i,re[i]='0'+i;
    tot=10;
    for(i='A';i<='Z';i++)
    {
        if(i==(int)'O'||i==(int)'Q'||i==(int)'I'||i==(int)'B') continue;
        pos[i]=tot++;
        re[tot-1]=i-'A'+'A';
    }
//    cout<<tot<<endl;
    lim=0;
    now=1;
    for(i=0;i<5;i++)
    {
        lim+=(tot-1)*now;
        now*=tot;
    }
    lim++;
    while(cin>>s>>stp)
    {
        stp%=lim;
        n=0;
        reverse(all(s));
        now=1;
        for(i=0;i<len(s);i++)
        {
            n+=pos[s[i]]*now;
            now*=tot;
        }
   //     cout<<n<<endl;
        n+=stp;
        (n+=lim)%=lim;
   //     cout<<n<<endl;
        string ans="";
        function<void(ll)> dfs=[&](ll x)
        {
            if(!x) return;
            dfs(x/tot);
            ans+=re[x%tot];
        };
        dfs(n);
    //    cout<<ans<<endl;
        for(i=0;i<5-len(ans);i++) putchar('0');
        cout<<ans<<"\n";
    }
    return 0;
}
