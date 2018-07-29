#include <stdio.h> 
int main()
{
    int i=0;
    double a[13],s=0;
    while(i<12)
    {
        scanf("%lf",&a[i]);
        s=s+a[i];
        i++;
    }
    printf("$%.2lf\n",s/12);
    return 0;
}