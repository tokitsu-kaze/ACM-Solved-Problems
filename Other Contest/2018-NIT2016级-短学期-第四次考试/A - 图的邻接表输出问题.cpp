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

VI mp[111];
int main()
{
    int n,m,i,j,a,b;
    while(~scanf("%d%d",&n,&m))
    {
        for(i=1;i<=n;i++) mp[i].clear();
        while(m--)
        {
            scanf("%d%d",&a,&b);
            mp[a].pb(b);
            mp[b].pb(a);
        }
        for(i=1;i<=n;i++)
        {
            printf("Node %d:",i);
            if(!sz(mp[i]))
            {
                puts("No AdjNode");
                continue;
            }
            sort(all(mp[i]));
            printf("%d",mp[i][0]);
            for(j=1;j<sz(mp[i]);j++)
            {
                printf("-->%d",mp[i][j]);
            }
            puts("");
        }
        puts("============");
    }
    return 0;
}

