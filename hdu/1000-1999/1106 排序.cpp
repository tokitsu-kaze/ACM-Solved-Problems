////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-11 16:21:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1396KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int i,j,c[1001],x,k,s;
	char *numchars,a[1001],b[1001];
	while(gets(a))
	{
		memset(b,0,sizeof(b));
		x=strlen(a);
		for(i=0,k=0,s=0,j=0;i<x;i++)
		{
			if(a[i]=='5')
			{
				if(a[i-1]!='5'&&i!=0)
				{
					numchars=b;
					c[k++]=atoi(numchars);
					memset(b,0,sizeof(b));
					j=0;
					s++;
				}
			}
			else b[j++]=a[i];
		}
		if(a[x-1]!='5')
		{
			numchars=b;
			c[k++]=atoi(numchars);
			memset(b,0,sizeof(b));
			j=0;
			s++;
		}
		for(i=0;i<s-1;i++)
		{
			for(j=0;j<s-1-i;j++)
			{
				if(c[j]>c[j+1]) swap(&c[j],&c[j+1]);
			}
		}
		for(i=0;i<s;i++)
		{
			printf("%d",c[i]);
			if(i!=s-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}