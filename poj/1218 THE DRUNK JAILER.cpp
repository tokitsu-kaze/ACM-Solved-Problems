#include <stdio.h>
#include <math.h>
int main()
{
    int n,i,a,s;
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%d",&a);
			for(i=1,s=0;i<=sqrt(a);i++)
			{
				if(i*i<=a) s++;
			}
			printf("%d\n",s);
		}
		
    }
    return 0;
}