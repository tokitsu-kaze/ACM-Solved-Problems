#include<bits/stdc++.h>
using namespace std;
int T;
long long a[28],ans1,ans2;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans1=0;
        for(int i=0;i<26;++i)
        {
            scanf("%lld",&a[i]);
            if(a[i]>=2)ans1+=2;
        }
        for(int i=0;i<26;++i)
        {
            if(a[i]==1)
            {
                ++ans1;
                break;
            }
        }
        if(ans1&1)
        {
            ans2=0;
            for(int i=0;i<26;++i)
            {
                if(a[i]==1)++ans2;
            }
            for(int i=0;i<26;++i)
            {
                if(a[i]>=2)
                {
                    ans2=min(ans2,a[i]/2);
                }
            }
        }
        else
        {
            ans2=9223372036854775807LL;
            for(int i=0;i<26;++i)
            {
                if(a[i]>=2)
                {
                    ans2=min(ans2,a[i]/2);
                }
            }
            if(ans2==9223372036854775807LL)ans2=0;
        }
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}