#include <stdio.h> 
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{  
    int n,i,j,a[102][102],dp[102][102];  
    while(~scanf("%d",&n))  
    {
        for(i=1;i<=n;i++)
        {
			for(j=1;j<=i;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(j=1;j<=n;j++)
		{
			dp[n][j]=a[n][j];
		}
		for(i=n-1;i>=1;i--)
		{
			for(j=1;j<=i;j++)
			{
				dp[i][j]=max(a[i][j]+dp[i+1][j],a[i][j]+dp[i+1][j+1]);
			}
		}
		printf("%d\n",dp[1][1]);
    }  
    return 0;
} 