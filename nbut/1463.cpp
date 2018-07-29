#include <stdio.h>
#include <math.h>
#include <algorithm>
double powi(double a,int b)
{
    double sum=1;
    for(int i=1; i<=b; i++)
        sum*=a;
    return sum;
}
int main()
{

    int n;
    while(~scanf("%d",&n))
    {

        if(n==0)
            break;
        int a[10000];
        for(int i=1; i<=n+1; i++)
        {
            scanf("%d",&a[i]);
        }
        double sum=0;
        a[1]=-1*a[1];
        double high=1e6;
        double low=-1;
        double middle;
        while(fabs(sum-a[1])>1e-6)
        {
            sum=0;
            double f=1.0;
            middle=(high+low)/2;
            for(int i=2; i<=n+1; i++)
            {
                f=f/(1+middle);
                sum+=a[i]*f;
            }
            if(sum>a[1])  low=middle;
            if(sum<a[1])  high=middle;
        }
        printf("%.2lf\n",middle);
    }
}