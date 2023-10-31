#include <stdio.h>
int main()
{
    int n,i,a;
    __int64 f[52];
    f[1]=1;
    f[2]=2;
    for(i=3;i<=50;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    while(~scanf("%d",&n))
    {
        printf("%I64d\n",f[n]);
    }
    return 0;
}