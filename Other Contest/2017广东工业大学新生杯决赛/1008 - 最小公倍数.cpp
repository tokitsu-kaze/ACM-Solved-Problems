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
const int MAX=2e6+10;
const ll mod=1e9+7;
int main()
{
    int t,i,j,x,n,k,flag[1111];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        mem(flag,0);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            for(j=x;j<=1000;j+=x)
            {
                flag[j]++;
            }
        }
        for(i=1;i<=1000;i++)
        {
            if(flag[i]>=k)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}