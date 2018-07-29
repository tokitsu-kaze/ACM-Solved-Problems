#include<bits/stdc++.h>
using namespace std;
const double PI=3.14159;
typedef long long ll;
int main()
{
    int t,n,i;
    ll f[22];
    f[1]=0;
    f[2]=1;
    for(i=3;i<=18;i++)
    {
        f[i]=(i-1)*(f[i-2]+f[i-1]);
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",f[n]);
    }
    return 0;
}
