#include <stdio.h>
#include <string.h>
int a[1000001];
int main()
{
    int n,i,t,s;
    while(~scanf("%d",&n))
    {
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
		{
			scanf("%d",&t);
			a[t]++;
			if(a[t]==2) printf("%d\n",t);
		}
    }
    return 0;
}