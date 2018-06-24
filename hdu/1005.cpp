////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-23 23:28:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1400KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
     long int a,b,n,T,s[101];
     while(scanf("%ld%ld%ld",&a,&b,&n)&&(a!=0&&b!=0&&n!=0))
     {
        int i,j,T;
        s[0]=1;
        s[1]=1;
        for(i=2;i<101;i++)
		{

            s[i]=(a*s[i-1]+b*s[i-2])%7;
            for(j=1;j<i-1;j++)
            {
                if(s[j-1]==s[i-1]&&s[j]==s[i])
				{
                    T=i-j;
                    break;
                }
            }
        }
        n = n%T;
        printf("%ld\n",s[n-1]);
     }
     return 0;
}