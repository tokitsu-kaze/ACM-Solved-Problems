#include <stdio.h>
int main()
{
    int n,i;
    __int64 f[100];
    f[1]=0;
    f[2]=1;
    for(i=3;i<100;i++)
    {
		f[i]=(i-1)*(f[i-2]+f[i-1]);
	}
    while(~scanf("%d",&n))
    {
        printf("%I64d\n",f[n]);
    }
    return 0;
}