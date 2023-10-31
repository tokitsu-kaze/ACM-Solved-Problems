#include <stdio.h>
int main()
{
    int a,b,i,j,h,k;
    char c[501][501];
    while(~scanf("%d%d",&a,&b))
    {
		for(i=0;i<a;i++)
		{
			getchar();
			for(j=0;j<b;j++)
			{
				scanf("%c",&c[i][j]);
			}
		}
		for(h=i-1;h>=0;h--)
		{
			for(k=j-1;k>=0;k--)
			{
				printf("%c",c[h][k]);
			}
			printf("\n");
		}
    }
    return 0;
}