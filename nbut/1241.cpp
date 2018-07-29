#include <stdio.h>
int main()
{
    int n,i,s,x;
    while(~scanf("%d",&n))
    {
        s=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            s=s+x;
        }
        printf("%d\n",s);
    }
    return 0;
}