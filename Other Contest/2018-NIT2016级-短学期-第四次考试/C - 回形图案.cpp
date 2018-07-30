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
int mp[111][111];
int main()
{
    int n,i,j,k,flag,x,y,tot;
    while(~scanf("%d",&n))
    {
        k=n;
        mem(mp,0);
        flag=1;
        x=y=n+1;
        tot=0;
        mp[x][y]=++tot;
        n=n*2+1;
        while(1)
        {
            if(tot>=n*n) break;
            x=(n-1)/2+1;
            y++;

            mp[x][y]=++tot;
            for(i=0;i<flag;i++)
            {
                mp[++x][y]=++tot;
            }
            for(i=0;i<flag*2;i++)
            {
                mp[x][--y]=++tot;
            }
            for(i=0;i<flag*2;i++)
            {
                mp[--x][y]=++tot;
            }
            for(i=0;i<flag*2;i++)
            {
                mp[x][++y]=++tot;
            }
            for(i=0;i<flag*2;i++)
            {
                if(mp[x+1][y]) break;
                mp[++x][y]=++tot;
            }

            flag++;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                printf("%4d",mp[i][j]);
            }
            puts("");
        }
        for(i=0;i<4*(2*k+1);i++) putchar('-');
        puts("");
    }
    return 0;
}
/*
1 1 2 2 3 3 4 4 5
*/
