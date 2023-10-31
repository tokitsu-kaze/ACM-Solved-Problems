#include <stdio.h>
int main()
{
	int n,a,b;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d%d",&a,&b);
			if(a-b==2||a==b)
			{
				if(a%2==0) printf("%d\n",a+b);
				else printf("%d\n",a+b-1);
			}
			else printf("No Number\n");
		}
	}
    return 0;
}