#include<bits/stdc++.h>
using namespace std;
const double PI=3.14159;
int main()
{
    int t,n;
    double ans,a,b;
    char s[11];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        while(n--)
        {
            scanf("%s",s);
            if(s[0]=='T')
            {
                scanf("%lf%lf",&a,&b);
                ans=max(ans,a*b/2);
            }
            else if(s[0]=='R')
            {
                scanf("%lf%lf",&a,&b);
                ans=max(ans,a*b);
            }
            else if(s[0]=='C')
            {
                scanf("%lf",&a);
                ans=max(ans,a*a*PI);
            }
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}