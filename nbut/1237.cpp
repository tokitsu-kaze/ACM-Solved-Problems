#include <stdio.h>
int main()
{
    int n,a[10000],b[10000],i;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        for(i=0;i<n;i++)
        {
            printf("%d\n",a[i]+b[i]);
        }
    }
    return 0;
}