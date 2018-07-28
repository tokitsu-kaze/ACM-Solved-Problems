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
const int MAX=2e5+10;
const int mod=1e9+7;
int main()
{
    int t;
    scanf("%d",&t);
    string tmp[5]={"Kanbara Akihito", "Kuriyama Mirai", "Nase Hiroomi","Nase Mitsuki"};
    while(t--)
    {
        vector<string> res;
        string s;
        cin>>s;
        for(int i=0;i<5;i++)
        {
            int pos=0;
            for(int j=0;pos<s.length()&&j<tmp[i].length();j++)
            {
                if(tmp[i][j]==s[pos]) pos++;
            }
            if(pos==s.length()) res.pb(tmp[i]);
        }
        sort(all(res));
        printf("%d\n",sz(res));
        for(int i=0;i<sz(res);i++) cout<<res[i]<<"\n";
    }
    return 0;
}