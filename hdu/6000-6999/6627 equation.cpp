#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int T;
struct node
{
    long long a,b;
}a[MAXN];
bool cmp(const node &A,const node &B)
{
    return -A.b*B.a<-B.b*A.a;
}
bool le(long long up1,long long down1,long long up2,long long down2)
{
    if(down1<0)
    {
        up1=-up1;
        down1=-down1;
    }
    if(down2<0)
    {
        up2=-up2;
        down2=-down2;
    }
    return up1*down2<up2*down1;
}
bool leq(long long up1,long long down1,long long up2,long long down2)
{
    if(down1<0)
    {
        up1=-up1;
        down1=-down1;
    }
    if(down2<0)
    {
        up2=-up2;
        down2=-down2;
    }
    return up1*down2<=up2*down1;
}
bool eq(long long up1,long long down1,long long up2,long long down2)
{
    return up1*down2==up2*down1;
}
int n;
long long A,B,c;
vector<pair<long long,long long> >v;
bool inf;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        v.clear();
        inf=false;
        A=0;
        B=0;
        scanf("%d %d",&n,&c);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld %lld",&a[i].a,&a[i].b);
            A-=a[i].a;
            B-=a[i].b;
        }
        sort(a+1,a+1+n,cmp);
        long long nowup=-1000000000;
        long long nowdown=1;
        /*
        for(int i=1;i<=n;++i)
        {
            cout<<"lin:"<<-a[i].b<<"/"<<a[i].a<<endl;
        }
        */
        if(A==0)
        {
            if(B==c)
            {
                inf=true;
            }
        }
        else
        {
            long long xup=c-B;
            long long xdown=A;
            //cout<<xup<<"-"<<xdown<<endl;
            if(leq(xup,xdown,-a[1].b,a[1].a))
            {
                long long g=abs(__gcd(xup,xdown));
                xup/=g;
                xdown/=g;
                if(xdown<0)
                {
                    xup=-xup;
                    xdown=-xdown;
                }
                v.push_back(make_pair(xup,xdown));
            }
        }
        if(!inf)
        {
            for(int i=1;i<=n;++i)
            {
                A=A+a[i].a*2;
                B=B+a[i].b*2;
                if(i+1<=n&&(-a[i].b*a[i+1].a==-a[i+1].b*a[i].a))continue;
                nowup=-a[i].b;
                nowdown=a[i].a;
                if(A==0)
                {
                    if(B==c)
                    {
                        inf=true;
                        break;
                    }
                }
                else
                {
                    long long xup=c-B;
                    long long xdown=A;
                    if(le(nowup,nowdown,xup,xdown)&&(i==n||(leq(xup,xdown,-a[i+1].b,a[i+1].a))))
                    {
                        long long g=abs(__gcd(xup,xdown));
                        xup/=g;
                        xdown/=g;
                        if(xdown<0)
                        {
                            xup=-xup;
                            xdown=-xdown;
                        }
                        v.push_back(make_pair(xup,xdown));
                    }
                }
            }
        }
        if(inf)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d",v.size());
            for(int i=0;i<v.size();++i)
            {
                printf(" ");
                printf("%lld/%lld",v[i].first,v[i].second);
            }
            printf("\n");
        }
    }
    return 0;
}

