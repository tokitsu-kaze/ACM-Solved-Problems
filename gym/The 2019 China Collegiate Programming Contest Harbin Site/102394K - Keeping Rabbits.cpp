#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
double k,a[MAXN],sum;
int n;
int T;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d %lf",&n,&k);
        for(int i=1;i<=n;++i)
        {
            scanf("%lf",&a[i]);
            sum+=a[i];
        }
        for(int i=1;i<=n;++i)
        {
            printf("%.8lf%c",a[i]+a[i]/sum*k,i==n?'\n':' ');
        }
    }
    return 0;
}
