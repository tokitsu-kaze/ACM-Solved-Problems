#include <stdio.h>
int main()
{
	int a,b,c,d;
    while(~scanf("%d.%d.%d.%d",&a,&b,&c,&d))
    {
		printf("%02X%02X%02X%02X\n",a,b,c,d);
    }
    return 0;
}