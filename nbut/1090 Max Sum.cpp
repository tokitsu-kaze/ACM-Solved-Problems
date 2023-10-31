#include <stdio.h> 
#define min(a,b) ((a)>(b)?(a):(b))
int main()
{  
    int t,n,i,sum,a,max,start,end,temp,k;  
    while(~scanf("%d",&t))  
    {
		k=1;
        while(t--)
        {
			scanf("%d",&n);
			sum=0;
			max=-1001;
			start=temp=end=1;
			for(i=1;i<=n;i++)
			{
				scanf("%d",&a);
				sum+=a;
				if(sum>max)
				{
					max=sum;
					start=temp;
					end=i;
				}
				if(sum<0)
				{
					sum=0;
					temp=i+1;
				}
			}
			printf("Case %d:\n",k);
			printf("%d %d %d\n",max,start,end);
			if(t!=0) printf("\n");
			k++;
		}
    }  
    return 0;
} 