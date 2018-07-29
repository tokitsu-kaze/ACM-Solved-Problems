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
    int x,now,aa,bb,i;
    string a,b;
    int pos[333];
    mem(pos,0);
    for(i=0;i<=9;i++) pos[i+'0']=i;
    for(i='A';i<='Z';i++) pos[i]=i-'A'+10;
    while(~scanf("%d",&x))
    {
        cin>>a>>b;
        reverse(all(a));
        reverse(all(b));
        now=0;
        string ans="";
        if((int)a.length()>(int)b.length()) swap(a,b);
        for(i=0;i<a.length();i++)
        {
            aa=pos[a[i]];
            bb=pos[b[i]];
            aa+=bb+now;
            now=aa/x;
            aa%=x;
            if(aa<=9) ans+='0'+aa;
            else ans+='A'+aa-10;
        }
        for(i=a.length();i<b.length();i++)
        {
            bb=pos[b[i]];
            bb+=now;
            now=bb/x;
            bb%=x;
            if(bb<=9) ans+='0'+bb;
            else ans+='A'+bb-10;
        }
        if(now)
        {
            if(now<=9) ans+='0'+now;
            else ans+='A'+now-10;
        }
        reverse(all(ans));
        string s="";
        int f=0;
        for(i=0;i<ans.length()-1;i++)
        {
            if(ans[i]!='0') f=1;
            if(f) s+=ans[i];
        }
        s+=ans[ans.length()-1];
        cout<<s<<"\n";
    }
    return 0;
}