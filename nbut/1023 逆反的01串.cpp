#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int len,i;
	char a[201];
    while(~scanf("%s",a))
    {
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]=='0') a[i]='1';
			else if(a[i]=='1') a[i]='0';
		}
		printf("%s\n",a);
    }
    return 0;
}