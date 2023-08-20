////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-25 17:45:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6043
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1664KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
    ll n,k,cas=1,temp;
    while(~scanf("%lld%lld",&n,&k))
    {
        printf("Case #%d: ",cas++);
        if(k<=n)
        {
            printf("%d\n",k);
            continue;
        }
        temp=(k-(n-1))%(2*(n-1));
        if(temp==0) temp=2*(n-1);
        if(temp==1) printf("%d\n",n);
        else
        {
            temp--;
            if(temp<=n-1) printf("%d\n",temp);
            else
            {
                temp-=(n-1);
                printf("%d\n",temp);
            }
        }
    }
    return 0;
}