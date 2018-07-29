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
    int t,i,j,len,now;
    char s[111];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        vector<int> ans;
        i=0;
        len=strlen(s);
        while(i<len)
        {
            while(s[i]=='0') i++;
            if(i>=len) break;
            now=0;
            for(j=i;j<len;j++)
            {
                if(s[j]>'0')
                {
                    s[j]--;
                    now=now*10+1;
                }
                else now*=10;
            }
            ans.pb(now);
        }
        sort(all(ans));
        printf("%d\n",(int)sz(ans));
        printf("%d",ans[0]);
        for(i=1;i<sz(ans);i++) printf(" %d",ans[i]);
        puts("");
    }
    return 0;
}