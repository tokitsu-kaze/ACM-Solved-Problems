#include <stdio.h>
int main()
{
    int n,m,i,j,a,b[10000];
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&a);
                b[i]=b[i]+a;
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d\n",b[i]);
        }
    }
    return 0;
}