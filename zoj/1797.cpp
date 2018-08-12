#include <stdio.h>
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
} 
int main()
{
    int n,m,a,sum;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
			sum=1;
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&a);
				sum=sum/gcd(sum,a)*a;
			}
			printf("%d\n",sum);
		}
    }
    return 0;
}