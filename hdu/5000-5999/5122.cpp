////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-05-11 17:05:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5122
////Problem Title: 
////Run result: Accept
////Run time:1092MS
////Run memory:13412KB
//////////////////System Comment End//////////////////
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int n,pos[MAXN],a[MAXN],ans,c[MAXN];
int lowbit(int x)
{
    return x&-x;
}
int sum(int x)
{
    int ans=0;
    while(x)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void add(int x,int y)
{
    while(x<=n)
    {
        c[x]+=y;
        x+=lowbit(x);
    }
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            c[i]=0;
            pos[a[i]]=i;
        }
        for(int i=n;i;--i)
        {
            int delta=sum(pos[i]);
            if(pos[i]-delta!=i)++ans;
            add(pos[i],1);
        }
        printf("Case #%d: %d\n",cas,ans);
    }

    return 0;
}