////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-01-22 15:12:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2137
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    int n,i,j;
    char a[101];
    while(~scanf("%s %d",a,&n))
    {
		n%=8;
		if(n==0)
		{
			cout<<a<<endl;
		}
		else if(n==4||n==-4)
		{
			for(i=strlen(a)-1;i>=0;i--)
			{
				cout<<a[i];
			}
			puts("");
		}
		else if(n==-2||n==6)
		{
			for(i=0;i<strlen(a);i++)
			{
				for(j=0;j<strlen(a)/2;j++)
				{  
                    printf(" ");  
                }  
				cout<<a[i]<<endl;
			}
		}
		else if(n==2||n==-6)
		{
			for(i=strlen(a)-1;i>=0;i--)
			{  
                for(j=0;j<strlen(a)/2;j++)
				{  
                    printf(" ");  
                }  
                cout<<a[i]<<endl;
            }  
		}
		else if(n==1||n==-7)
		{  
            for(i=strlen(a)-1;i>=0;i--)
			{  
                for(j=0;j<i;j++)
				{  
                    printf(" ");  
                }  
                cout<<a[i]<<endl;
            }  
        }
        else if(n==7||n==-1)
        {
			for(i=0;i<strlen(a);i++)
			{  
                for(j=0;j<i;j++)
				{  
                    printf(" ");  
                }  
                cout<<a[i]<<endl; 
            }  
		}
        else if(n==3||n==-5)
        {
			for(i=0;i<strlen(a);i++)
			{  
                for(j=0;j<i;j++)
				{  
                    printf(" ");  
                }  
               	cout<<a[strlen(a)-i-1]<<endl;
            }  
		}
		else if(n==5||n==-3)
		{
			for(i=0;i<strlen(a);i++)
			{  
                for(j=strlen(a)-1;j>i;j--)
				{  
                    printf(" ");  
                }  
                cout<<a[i]<<endl;
			}
		}
	}
    return 0;
}
