#include <stdio.h>
int main()
{
    int a;
    while(~scanf("%d",&a))
    {
        if(a==0) break;
        printf("%d\n",a&(-a));
    }
    return 0;
}