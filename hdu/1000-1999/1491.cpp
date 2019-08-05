////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 11:45:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1491
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,d,s;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d%d",&m,&d);
			switch(m)
			{
				case 1:s=273-d+21;break;
				case 2:s=242-d+21;break;
				case 3:s=214-d+21;break;
				case 4:s=183-d+21;break;
				case 5:s=153-d+21;break;
				case 6:s=122-d+21;break;
				case 7:s=92-d+21;break;
				case 8:s=61-d+21;break;
				case 9:s=30-d+21;break;
				case 10:s=21-d;break;
				default :s=-1;break;
			}
			if(m>10||(m==10&&d>21)) printf("What a pity, it has passed!\n");
			else if(s==0) printf("It's today!!\n");
			else printf("%d\n",s);
		}
	}
	return 0;
}