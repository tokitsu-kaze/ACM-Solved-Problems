////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-09 18:51:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:1045MS
////Run memory:4484KB
//////////////////System Comment End//////////////////
#include<stdio.h>  
#include<string.h>  
#define MAXN 100005  
struct ST  
{  
    int l,r,sum;  
}st[MAXN*3];  
int nn;  
void build(int ll,int rr,int n)  
{  
    st[n].l=ll;  
    st[n].r=rr;  
    st[n].sum=0;  
    if (ll==rr) return ;  
    int mid=(ll+rr)/2;  
    build(ll,mid,2*n);  
    build(mid+1,rr,2*n+1);  
};  
void color(int ll,int rr,int n)  
{  
    if (st[n].l==ll&&st[n].r==rr) {st[n].sum++;return ;}  
    int mid=(st[n].l+st[n].r)/2;  
    if (rr<=mid) color(ll,rr,2*n);  
    else  
    if (ll>=mid+1) color(ll,rr,2*n+1);  
    else  
    {  
        color(ll,mid,2*n);  
        color(mid+1,rr,2*n+1);  
    }  
}  
void out(int n,int sum)  
{  
    if (st[n].l==st[n].r) {printf("%d",sum+st[n].sum);if (st[n].l!=nn) printf(" ");return;}  
    out(2*n,sum+st[n].sum);  
    out(2*n+1,sum+st[n].sum);  
}  
int main()  
{  
    int i,p,q;  
    while (scanf("%d",&nn)&&nn)  
    {  
        build(1,nn,1);  
        for (i=1;i<=nn;++i)  
        {  
            scanf("%d%d",&p,&q);  
            color(p,q,1);  
        }  
        out(1,0);  
        printf("\n");  
    }  
    return 0;  
}  