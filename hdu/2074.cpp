////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 22:28:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2074
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,j,g,h,flag=0;
    char a,b,c,x[100][100];
	while(~scanf("%d %c %c",&n,&a,&b))
	{
		if(flag==1) printf("\n");
		memset(x,' ',sizeof(x));
		if((n+1)/2%2!=0) c=a;
		else c=b;
		g=0;
		h=n;
		while(n-g!=-1)
		{
			for(i=g;i<h;i++)
			{
				for(j=g;j<h;j++)
				{
					if((i==0&&j==0)||(i==0&&j==n-1)||(i==n-1&&j==0)||(i==n-1&&j==n-1))
					{
						x[i][j]=' ';
					}
					else x[i][j]=c;
				}
			}
			if(c==a) c=b;
			else c=a;
			g++;
			h--;
		}
		if(n==1) printf("%c\n",a);
		else
		{
		for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					printf("%c",x[i][j]);
				}
				printf("\n");
			}
		}
		flag=1;
	}
	return 0;
}
