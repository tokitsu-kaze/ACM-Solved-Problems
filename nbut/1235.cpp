#include <stdio.h> 
int main()
{
	int m,n,i,a[]={153,370,371,407,1634,8208,9474,54748,92727,93084,548834}; 
    while(~scanf("%d%d",&m,&n))
    {
        for(i=0;i<11;i++)
        {
			if(a[i]>=m&&a[i]<=n) printf("%d\n",a[i]);
		}
    }
    return 0;
}