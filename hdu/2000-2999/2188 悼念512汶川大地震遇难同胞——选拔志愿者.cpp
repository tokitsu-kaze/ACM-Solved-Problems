////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-17 21:42:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2188
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,c;
    while(~scanf("%d",&c))
    {
        while(c--)
        {
			scanf("%d%d",&n,&m);
			if(n%(m+1)!=0) printf("Grass\n");
			else printf("Rabbit\n");
		}
    }
    return 0;
}