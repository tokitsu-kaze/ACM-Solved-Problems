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
int a[111][111],dp[111][111];
PII pre[111][111];
int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        mem(a,0);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++) scanf("%d",&a[i][j]);
        }
        mem(dp,0x3f);
        mem(dp[n+1],0);
        mem(pre,0);
        for(i=n;i;i--)
        {
            for(j=1;j<=i;j++)
            {
                if(dp[i+1][j]+a[i][j]<=dp[i+1][j+1]+a[i][j])
                {
                    dp[i][j]=dp[i+1][j]+a[i][j];
                    pre[i][j]=MP(i+1,j);
                }
                else
                {
                    dp[i][j]=dp[i+1][j+1]+a[i][j];
                    pre[i][j]=MP(i+1,j+1);
                }
            }
        }
        VI res;
        int x,y,tx,ty;
        x=y=1;
        while(x<=n&&y<=n)
        {
            res.pb(a[x][y]);
            tx=pre[x][y].fi;
            ty=pre[x][y].se;
            x=tx;
            y=ty;
        }
        cout<<dp[1][1]<<"\n";
        printf("%d",res[0]);
        for(i=1;i<sz(res);i++) printf("-->%d",res[i]);
        puts("");
    }
    return 0;
}
