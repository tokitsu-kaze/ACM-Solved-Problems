#include <stdio.h>
#include <string.h>
int main()
{
    int x,i,s;
    char a[10001];
    while(~scanf("%s",a))
    {
		if(a[0]-'0'==0) break;
		s=0;
		x=strlen(a);
		for(i=0;i<x;i++)
		{
			s+=a[i]-'0';
		}
		if(s%9==0) printf("9\n");
		else printf("%d\n",s%9);
    }
    return 0;
}