////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-05 23:25:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5455
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:1876KB
//////////////////System Comment End//////////////////
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
int main()
{
    int t,i,pos,cas=1,cnt,flag,ans;
    string s,tmp;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        printf("Case #%d: ",cas++);
        cnt=0;
        while(s[cnt]=='f'&&cnt<s.length()) cnt++;
        if(cnt==s.length())
        {
            printf("%d\n",(cnt+1)/2);
            continue;
        }
        tmp="";
        tmp=s.substr(cnt,s.length()-cnt);
        tmp+=string(cnt,'f');
        ans=0;
        pos=0;
        while(pos<tmp.length())
        {
            flag=0;
            for(i=pos+1;i<tmp.length();i++)
            {
                if(tmp[i]=='c')
                {
                    if(i-1-pos<2)
                    {
                        ans=-1;
                        goto end;
                    }
                    flag=1;
                    pos=i;
                    break;
                }
            }
            if(!flag)
            {
                if(tmp.length()-1-pos<2)
                {
                    ans=-1;
                    goto end;
                }
                pos=tmp.length()+1;
            }
            ans++;
        }
        end:;
        printf("%d\n",ans);
    }
    return 0;
}