#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const long long mod=1e9+7;
int T;
int n,a[MAXN];
bool ck()
{
    if(a[n]!=n-1)return false;
    for(int i=1;i<=n;++i)
    {
        if(a[i]<a[i-1])return false;
    }
    return true;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
        }
        if(!ck())
        {
            printf("0\n");
            continue;
        }
        long long sum=1;
        long long cnt=0;
        for(int i=2;i<=n;++i)
        {
            if(a[i]!=a[i-1])
            {
                cnt+=a[i]-a[i-1]-1;
                sum=sum*2%mod;
            }
            else
            {
                sum=sum*cnt%mod;
                cnt--;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
