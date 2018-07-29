#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int n,a,b,i,flag,c[7];
	char x[7],y[7];
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			scanf("%s %s",x,y);
			a=atoi(x);
			b=atoi(y);
			for(;a<=b;a++)
			{
				if(a>=1000&&a<=6666)
				{
					c[0]=0;
					c[1]=0;
					c[2]=a/1000;
					c[3]=a/100%10;
					c[4]=a/10%10;
					c[5]=a%10;
				}
				else if(a>=10000&&a<=66666)
				{
					c[0]=0;
					c[1]=a/10000;
					c[2]=a/1000%10;
					c[3]=a/100%10;
					c[4]=a/10%10;
					c[5]=a%10;
				}
				else
				{
					c[0]=a/100000;
					c[1]=a/10000%10;
					c[2]=a/1000%10;
					c[3]=a/100%10;
					c[4]=a/10%10;
					c[5]=a%10;
				}
				flag=0;
				for(i=1;i<5;i++)
				{
					if(c[0]>6||c[1]>6||c[2]>6||c[3]>6||c[4]>6||c[5]>6)
					{
						flag=1;
						break;
					}
					if(c[i-1]==c[i]&&c[i]==c[i+1])
					{
						 flag=1;
						 break;
					}
					if(abs(c[i]-c[i-1])>4||abs(c[i]-c[i+1])>4)
					{
						flag=1;
						break;
					}
				}
				if(flag==0) printf("%06d\n",a);
			}
			if(n!=0) printf("\n");
		}
    }
    return 0;
}