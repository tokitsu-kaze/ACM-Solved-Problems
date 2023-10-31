#include <stdio.h>
int main()
{
	int a,b,i;
	while(~scanf("%d%d",&a,&b))
	{
		if(a==0&&b==0) break;
		for(i=1;i<=100;i++)
		{
			a=(a+a*b)%60;
			if(a==0) break; 
		}
		if(a==0) printf("%d\n",i);
		else printf("Impossible\n");
	}
}