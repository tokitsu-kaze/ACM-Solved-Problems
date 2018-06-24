////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-05 14:52:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2160
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1688KB
//////////////////System Comment End//////////////////
#include<stdio.h>  
int main()  
{  
    int t,i,n,a[21]={1,2,3,5,8};  
    for(i=5;i<21;i++)  
    a[i]=a[i-1]+a[i-2];
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        printf("%d\n",a[n-1]);  
    }  
    return 0;  
}