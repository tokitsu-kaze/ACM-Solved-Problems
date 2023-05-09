#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int b,c;
	char a[10],d[10],*end;
	while(~scanf("%s%d%d",a,&b,&c))
	{
		itoa(strtol(a,&end,b),d,c);
		if(strlen(d)>7) printf("  ERROR\n");
		else printf("%7s\n",strupr(d));
	}
    return 0;
}