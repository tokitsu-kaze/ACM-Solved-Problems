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
int main()
{
    string s;
    int i,len;
    while(cin>>s)
    {
        len=s.length();
        for(i=0;i<len;i++)
        {
            if(s[i]>='0'&&s[i]<='9') s[i]=s[i]-'0'+'a';
            if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
        }
        int ans,pos,now;
        ans=now=1;
        pos=0;
        for(i=1;i<len;i++)
        {
            if(s[i]==s[i-1]) now++;
            else
            {
                if(now>ans)
                {
                    ans=now;
                    pos=i-now;
                }
                now=1;
            }
        }
        if(now>ans)
        {
            ans=now;
            pos=i-now;
        }
        printf("From=%d,To=%d\n",pos+1,pos+ans);
        printf("MaxLen=%d\n",ans);
    }
    return 0;
}