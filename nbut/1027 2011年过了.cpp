#include <stdio.h>
int main()
{
	__int64 n,i,j,s[2011];
	for(i=1;i<=2010;i++)
	{
		for(j=1,s[i]=1;j<=i;j++)
		{
			s[i]=s[i]*j%2011;
		}
	}
	while(~scanf("%I64d",&n))
	{
		if(n==0) break;
		if(n>=2011) printf("0\n");
		else printf("%I64d\n",s[n]);
	}
    return 0;
}