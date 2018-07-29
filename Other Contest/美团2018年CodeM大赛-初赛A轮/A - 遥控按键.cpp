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
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int dis[11][11];
char s[MAX];
int main()
{
    int pos[333],i,j,k,l;
    mem(pos,0);
    pos['@']=1;
    pos['!']=1;
    pos[':']=1;
    for(i=0;i<15;i++)
    {
        pos[i+'A']=1+(i+3)/3;
    }
    for(i=15;i<19;i++) pos[i+'A']=7;
    for(i=19;i<22;i++) pos[i+'A']=8;
    for(i=22;i<26;i++) pos[i+'A']=9;
//  for(i='A';i<='Z';i++) cout<<pos[i]<<endl;
    mem(dis,0);
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            for(k=1;k<=3;k++)
            {
                for(l=1;l<=3;l++)
                {
                    dis[(i-1)*3+j][(k-1)*3+l]=abs(k-i)+abs(l-j);
                }
            }
        }
    }
    int t,len,ans,pre;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        len=strlen(s);
        ans=0;
        pre=1;
        for(i=0;i<len;i++)
        {
            ans+=dis[pre][pos[s[i]]];
            pre=pos[s[i]];
        }
        printf("%d\n",ans);
    }
    return 0;
}