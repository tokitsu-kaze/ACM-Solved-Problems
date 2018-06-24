////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-16 21:46:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2087
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1408KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int lena,lenb,i,j,flag,count;
    char a[1001],b[1001];
	while(~scanf("%s",a))
	{
		if(a[0]=='#') break;
		scanf("%s",b);
		count=0;
		lena=strlen(a);
		lenb=strlen(b);
		for(i=0,j=0;i<lena;i++)
		{
			if(a[i]==b[j])
			{
				flag=0;
				for(j=1;j<lenb;j++)
				{
					i++;
					if(a[i]!=b[j])
					{
						flag=1;
						break;
					}
				}
			}
			else flag=1;
			if(flag==0) count++;
			j=0;
		}
		printf("%d\n",count);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	return 0;
}
