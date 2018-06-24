////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-09-24 00:06:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2001
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1444KB
//////////////////System Comment End//////////////////
#include<stdio.h>   
#include<math.h>   
int main()   
{   
   double x1,x2,y1,y2;   
   while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF)
   {   
       printf("%.2lf\n",sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));   
   }   
   return 0;   
}  