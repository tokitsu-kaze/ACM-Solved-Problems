#include <stdio.h>
#include <string.h>
int main()
{
    int i,len;
    char a[100],c[10001];
    while(gets(a))
    {
		if(strcmp(a,"ENDOFINPUT")==0) break;
		gets(c);
		len=strlen(c);
		for(i=0;i<len;i++)
		{
			if(c[i]>='A'&&c[i]<='E') c[i]=c[i]+21;
			else if(c[i]>='F'&&c[i]<='Z') c[i]=c[i]-5;
		}
		printf("%s\n",c);
		gets(a);
	}
    return 0;
}