////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-15 14:29:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5365
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1700KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e6+10;
const ll mod=1e9+7;
struct node
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
}p[511];
int main()
{
    int n,i,j,ans;
    while(~scanf("%d",&n))
    {
        map<pair<int,int>,int> mp;
        for(i=0;i<n;i++)
        {
            p[i].input();
            mp[MP(p[i].x,p[i].y)]=1;
        }
        ans=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int a,b,c,d,e,f,g,h;
                a=p[i].x;
                b=p[i].y;
                c=p[j].x;
                d=p[j].y;
                e=a+b+c-d;
                f=-a+b+c+d;
                g=a-b+c+d;
                h=a+b-c+d;
                if(abs(e%2)+abs(f%2)+abs(g%2)+abs(h%2)==0)
                {
                    if(mp[MP(e/2,f/2)]&&mp[MP(g/2,h/2)]) ans++;
                }
            }
        }
        printf("%d\n",ans/2);
        
    }
    return 0;
}
