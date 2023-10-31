#include <stdio.h>
int main()
{
	__int64 a,b;
    while(~scanf("%I64d%I64d",&a,&b))
    {
		if(a==0&&b==0) break;
		printf("%I64d\n",(a+b)/2);
    }
    return 0;
}