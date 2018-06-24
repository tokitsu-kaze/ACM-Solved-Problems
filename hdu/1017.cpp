////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-18 22:09:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1017
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
#include <stdio.h> 
int main()
{  
    int n,k,count,a,b,i,j;  
    while(~scanf("%d",&n))  
    {
		while(n--)
		{
			k=1;
			while(~scanf("%d%d",&a,&b))
			{
				count=0;
				if(a==0&&b==0) break;
				for(i=1;i<a-1;i++)
				{
					for(j=i+1;j<a;j++)
					{
						if((i*i+j*j+b)%(i*j)==0) count++;
					}
				}
				printf("Case %d: %d\n",k++,count);
			}
			if(n!=0) printf("\n");
		}
    }  
    return 0;
} 