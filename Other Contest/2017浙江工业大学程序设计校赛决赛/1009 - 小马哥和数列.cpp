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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
//typedef __int64 ll;
typedef long long ll;
ll a[100010];
int main()
{
    ll n,p,i,j,cnt,t,ans;
    while(~scanf("%lld%lld",&n,&p))
    {
        mem(a,0);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        sort(a,a+n);
        ans=0;
        for(i=0;i<n-1;i++)
        {
            t=a[i]*p;
            cnt=1;
            for(j=i+1;j<n;j++)
            {
                if(a[j]<=t) cnt++;
                else break;
            }
            ans=max(ans,cnt);
            if(n-i<ans) break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
