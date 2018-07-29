#include<bits/stdc++.h>
using namespace std;
int a[5010],bit[5010];
int main()
{
    int t,n,k,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        bit[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            bit[i]=bit[i-1]+a[i];
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(bit[j]-bit[i-1]==k)
                {
                    printf("%d %d\n",i,j);
                    goto end;
                }
            }
        }
        end:;
    }
    return 0;
}