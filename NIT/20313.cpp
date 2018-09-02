#include "stdio.h"
 
int main()
{
    int A,B;
    while(scanf("%d%d",&A,&B)!=EOF)//多组案例输入的格式，也可以使用while(~scanf("%d%d",&A,&B))
    {
        printf("%d\n",A+B);
    }
}