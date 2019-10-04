#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,m;
long long sum[MAXN][2],a[MAXN];
int lowbit(int x)
{
    return x&-x;
}
long long q(int x,int ki)
{
    long long ans=0;
    while(x)
    {
        ans+=sum[x][ki];
        x-=lowbit(x);
    }
    return ans;
}
void change(int x,long long val,int ki)
{
    while(x<=n)
    {
        sum[x][ki]+=val;
        x+=lowbit(x);
    }
    return;
}
long long qsum(int l,int r,int ki)
{
    return q(r,ki)-q(l-1,ki);
}
int type;
long long val,l,r;
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n;++i)
        {
            sum[i][0]=sum[i][1]=0;
        }
        for(long long i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
            change(i,a[i],0);
            change(i,a[i]*i,1);
        }
        while(m--)
        {
            scanf("%d",&type);
            if(type==1)
            {
                scanf("%lld %lld",&l,&r);
                long long ans=qsum(l,r,0)*(r+1)-qsum(l,r,1);
                printf("%lld\n",ans);
            }
            else
            {
                scanf("%lld %lld",&l,&val);
                change(l,-a[l],0);
                change(l,val,0);
                change(l,-a[l]*l,1);
                change(l,val*l,1);
                a[l]=val;
            }
        }
    }
    return 0;
}