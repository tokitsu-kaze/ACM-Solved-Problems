#include <stdio.h>  
int main()  
{  
    int n,m;  
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))  
    {  
        puts((n*m)&1?"What a pity!":"Wonderful!");  
    }  
    return 0;
} 