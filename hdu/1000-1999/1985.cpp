////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-28 16:34:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1985
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1624KB
//////////////////System Comment End//////////////////
#include<iostream>  
#include<string>  
#include<stdio.h>  
#include<algorithm>  
using namespace std;  
  
int main()  
{  
    int N;  
    double a;  
    string s;  
    cin >> N;  
    for(int i = 1; i <= N; ++i)  
    {  
        cin >> a >> s;  
        printf("%d ",i);  
        if(s == "kg")  
            printf("%.4lf lb\n",2.2046*a);  
        else if(s == "l")  
            printf("%.4lf g\n",0.2642*a);  
        else if(s == "lb")  
            printf("%.4lf kg\n",a*0.4536);  
        else if(s == "g")  
            printf("%.4lf l\n",a*3.7854);  
    }  
    return 0;  
}  