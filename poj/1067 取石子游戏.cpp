#include <stdio.h> 
#include <math.h> 
#include <stdlib.h>
#define min(a,b) ((a)>(b)?(b):(a))
int main()  
{  
    int n,m;  
    while(~scanf("%d%d",&n,&m))  
    {
        if(int(abs(n-m)*(sqrt(5.0)+1))/2==min(n,m)) printf("0\n");
        else printf("1\n");
    }  
    return 0;
} 