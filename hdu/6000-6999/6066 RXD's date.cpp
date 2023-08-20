////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-08-01 19:06:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6066
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1512KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main(){int n,i,x,a;while(~scanf("%d",&n)){a=0;for(i=0;i<n;i++)scanf("%d",&x),a+=x<=35;printf("%d\n",a);}}