#include <stdio.h>
int fac(int n)
{
    int i,s=1;
    for(i=1;i<=n;i++)
    {
        s=s*i;
    }
    return s;
}
int main()
{
    int i;
    double e=0;
    printf("n e\n- -----------\n");
    for(i=0;i<=1;i++)
    {
        e=e+1.0/fac(i);
        printf("%d %.0lf\n",i,e);
    }
    for(i=2;i<=2;i++)
    {
        e=e+1.0/fac(i);
        printf("%d %.1lf\n",i,e);
    }
    for(i=3;i<=9;i++)
    {
        e=e+1.0/fac(i);
        printf("%d %.9lf\n",i,e);
    }
    return 0;
}