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
const int MAX=2e3+10;
const ll mod=1e9+7;
int mp[MAX][MAX],tmp[MAX][MAX];
ll dp[MAX][MAX];
int main()
{
    int n,m,x,y,len,sz;
    scanf("%d%d",&n,&m);
    {
        for(int i=1;i<=n;i++)
        {
            dp[0][i]=dp[i][0]=0;
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&mp[i][j]);
                dp[i][j]=0;
            }
        }
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&len);
            sz=len*sizeof(int);
            for(int i=x;i<=x+len-1;i++) memcpy(tmp[i]+y+len,mp[i]+y,sz);
            for(int i=x;i<=x+len-1;i++) memcpy(tmp[i+len]+y+len,mp[i]+y+len,sz);
            for(int i=x+len-1;i<=x+2*len-1;i++) memcpy(tmp[i]+y,mp[i]+y+len,sz);
            for(int i=x+len-1;i<=x+2*len-1;i++) memcpy(tmp[i-len]+y,mp[i]+y,sz);
            sz*=2;
            for(int i=x;i<=x+2*len-1;i++) memcpy(mp[i]+y,tmp[i]+y,sz);
        }
    /*  for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%d ",mp[i][j]);
            }
            puts("");
        }*/
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=mp[i][j]+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%lld\n",dp[n][n]);
    }
    return 0;
}
