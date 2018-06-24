////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-04 18:20:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2072
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:2364KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    int x,i,j,k,h,g,u,t,s,f;
    char a[1000],b[1000][1000];
    while(gets(a))
    {
		memset(b,0,sizeof(b));
		k=0;
		h=0;
		u=0;
		t=0;
		s=0;
		f=0;
        if(a[0]=='#') break;
        x=strlen(a);
        for(i=0;i<x;i++)
        {
			if(a[i]!=' ')
			{
				if(k!=0) b[k][i-h-1]=a[i];
				else b[k][i]=a[i];
			}
			else if(a[i]==' ')
			{
				k++;
				h=i;
			}
		}
		for(g=k+1;g>0;g--)
		{
			for(i=0;i<g;i++)
			{
				for(j=0;j<x;j++)
				{
					if(b[t][j]==b[i+1+t][j]) u++;
				}
				if(u==x) s++;
				u=0;
			}
			if(s!=0) f++;
			t++;
			s=0;
		}
		printf("%d\n",k+1-f);
		memset(a,0,sizeof(a));
    }
    return 0;
}