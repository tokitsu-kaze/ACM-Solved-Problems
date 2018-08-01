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
    int d,l,r,ans,s,t,cnt[33],mx,i;
    string ss;
    while(~scanf("%d",&d))
    {
        cin>>ss;
        l=r=s=t=0;
        ans=0;
        mem(cnt,0);
        for(r=0;r<len(ss);r++)
        {
            cnt[ss[r]-'a']++;
            mx=0;
            for(i=0;i<26;i++)
            {
                if(cnt[i])mx=max(mx,abs(ss[r]-'a'-i));
            }
            while(l<r&&mx>d)
            {
                cnt[ss[l]-'a']--;
                l++;
                mx=0;
                for(i=0;i<26;i++)
                {
                    if(cnt[i])mx=max(mx,abs(ss[r]-'a'-i));
                }
            }
            if(mx<=d)
            {
                if(ans<r-l+1)
                {
                    ans=r-l+1;
                    s=l+1;
                    t=r+1;
                }
            }
        }
        printf("From=%d,To=%d\n",s,t);
        printf("MaxLen=%d\n",ans);
    }
    return 0;
}



