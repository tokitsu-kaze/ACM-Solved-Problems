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
char s[1111][1111];
int main()
{
    int n,i,j,k;
    while(~scanf("%d",&n))
    {
        mem(s,0);
        int m=n*2-1;
        for(i=0;i<n*2;i++)
        {
            for(j=0;j<n;j++)
            {
                s[i][j]=' ';
            }
            for(j=n;j<n+m;j++)
            {
                s[i][j]='*';
            }
        }
        int flag=0;
        for(i=n*2;i<n*4;i++)
        {
            for(j=0;j<flag;j++) s[i][j]=' ';
            for(j=flag;j<m+2*n-flag;j++) s[i][j]='*';
            flag++;
        }
        for(i=0;i<n*4;i++)
        {
            puts(s[i]);
        }
    }
    return 0;
}


