////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-10 20:36:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2031
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1424KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h> 
void exchange(int a,int b)
{
	int c;
	if(a==0) return;
	c=a%b;
	exchange(a/b,b);
	switch(c)
	{
		case 10:printf("A");break;
		case 11:printf("B");break;
		case 12:printf("C");break;
		case 13:printf("D");break;
		case 14:printf("E");break;
		case 15:printf("F");break;
		default :printf("%d",c);break;
	}
}
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
		if(a<0)
		{
			printf("-");
			exchange(abs(a),b);
		}
		else exchange(a,b);
		printf("\n");
    }
    return 0;
}