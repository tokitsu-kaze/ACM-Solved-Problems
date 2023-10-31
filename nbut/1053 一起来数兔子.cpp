#include <stdio.h>
int main()
{
	int a[100],n,i;
	a[1]=1;
	a[2]=2;
	a[3]=3;
	a[4]=4;
	for(i=5;i<56;i++)
	{
		a[i]=a[i-1]+a[i-3];
	}
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		printf("%d\n",a[n]);
	}
	return 0;
}