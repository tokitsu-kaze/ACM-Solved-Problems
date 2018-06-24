////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-11 17:02:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5112
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:1776KB
//////////////////System Comment End//////////////////
#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[10010];
int main()
{
    int t,n,i,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].first,&a[i].second);
        }
        sort(a,a+n);
        double ans=0;
        for(i=0;i<n-1;i++)
        {
            ans=max(ans,abs(a[i+1].second-a[i].second)*1.0/(a[i+1].first-a[i].first));
        }
        printf("Case #%d: %.2lf\n",cas++,ans);
    }
    return 0;
}