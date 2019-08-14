#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
struct node
{
    char s[25];
    long long p;
    long long t;
}a[MAXN];
int T,n,d;
bool cmp(const node &A,const node &B)
{
    if(A.p!=B.p)
    {
        return A.p>B.p;
    }
    return A.t<B.t;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;++i)
        {
            scanf("%s %lld %lld",a[i].s,&a[i].p,&a[i].t);
        }
        sort(a+1,a+1+n,cmp);
        if((n*d*10)%100==50)
        {
            printf("%s\n",a[(n*d*10)/100+1].s);
        }
        else
        {
            printf("Quailty is very great\n");
        }
    }
    return 0;
}

