#include <stdio.h>
int main()
{
	int m,n,i,j,s;
	char c;
    while(~scanf("%d%d",&m,&n))
    {
		
		if(m==0&&n==0) break;
		s=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf(" %c",&c);
				if(c=='*') s++;
			}
		}
		printf("%d\n",s);
    }
    return 0;
}