#include "stdio.h"
 
int main()
{
    int A,B;
    while(scanf("%d%d",&A,&B)!=EOF)//���鰸������ĸ�ʽ��Ҳ����ʹ��while(~scanf("%d%d",&A,&B))
    {
        printf("%d\n",A+B);
    }
}