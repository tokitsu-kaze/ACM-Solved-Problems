#include <stdio.h>
int a[1001][1001];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0)
            break;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=a[i][i];
        }
        int flag=1;
        for(int k=0,j=0; k<n; k++,j++)
        {
            int sum1=0;
            for(int i=0,j1=j; i<n; i++,j1++)
            {
                if(j1>=n)
                    j1=j1-n;
                sum1+=a[i][j1];
            }
            if(sum1!=sum)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            printf("homogeneous\n");
        }
        else
            printf("not homogeneous\n");
    }
}