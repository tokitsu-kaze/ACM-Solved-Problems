////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-20 21:48:52
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1039
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1392KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int i,len,flag,a,b;
    char c[10001];
    while(gets(c))
    {
		if(strcmp(c,"end")==0) break;
		len=strlen(c);
		flag=a=b=0;
		for(i=0;i<len;i++)
		{
			if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u')
			{
				flag=1;
				a++;
				b=0;
			}
			else
			{
				a=0;
				b++;
			}
			if((a==2||b==2)&&(c[i]==c[i-1]&&(c[i]!='e'&&c[i]!='o'))||a==3||b==3) break;
		}
		if(flag==1&&i==len) printf("<%s> is acceptable.\n",c);
		else printf("<%s> is not acceptable.\n",c);
    }
    return 0;
}