#include<stdio.h>
int main()
{
    int A,B,i,k,T,n,a[101];
    while(scanf("%d%d%d",&A,&B,&n)&&(A!=0&&B!=0&n!=0))
    {
        a[0]=a[1]=1;
        for(i=2;i<101;i++)
        {
            a[i]=(A*a[i-1]+B*a[i-2])%7;
            for(k=1;k<i-1;k++)
            {
                if(a[k-1]==a[i-1]&&a[k]==a[i])
                {
                    T=i-k;
                    break;
                }
            }
        }
        n=n%T;
        printf("%d\n",a[n-1]);
    }
    return 0;
}