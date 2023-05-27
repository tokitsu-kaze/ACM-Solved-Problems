////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-19 21:31:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2152
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1560KB
//////////////////System Comment End//////////////////
#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int main()  
{  
    int c1[120];  
    int c2[122];  
    int n,i,j,k,y,m;  
    int a[122];  
    int b[1022];  
    int sum;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
  
  
        for(i=1;i<=n;i++)  
        {  
        scanf("%d%d",&a[i],&b[i]);  
        }  
        memset(c1,0,sizeof(c1));  
        memset(c2,0,sizeof(c2));  
        for(i=a[1];i<=b[1];i++)  
        c1[i]=1;  
        for(i=2;i<=n;i++)  
        {  
            for(j=a[1];j<=m;j++)  
            {  
  
              for(k=a[i];k<=b[i]&&j+k<=m;k++)  
              {  
  
                  c2[j+k]=c2[j+k]+c1[j];  
  
  
              }  
  
  
            }  
            for(y=0;y<=102;y++)
            {  
                c1[y]=c2[y];  
                //printf("%d c1[i]",c1[i]);  
                c2[y]=0;  
            }  
  
        }  
  
        printf("%d\n",c1[m]);  
    }  
    return 0;  
}  