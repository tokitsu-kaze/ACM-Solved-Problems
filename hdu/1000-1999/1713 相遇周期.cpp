////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-04 21:38:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1713
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1560KB
//////////////////System Comment End//////////////////
#include <cstdio>  
#include <string>  
#include <math.h>  
#include <string.h>  
#include <stdlib.h>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
typedef __int64 LL;  
LL gcd(LL a,LL b){return b==0?a:gcd(b,a%b);}  
int main(){  
    int cas;  
    LL fz1,fz2,fm1,fm2,fz,fm;  
    scanf("%d",&cas);  
    while(cas--){  
        scanf("%I64d/%I64d%I64d/%I64d",&fz1,&fm1,&fz2,&fm2);      
        fz1*=fm2,fz2*=fm1;  
        fm=fm1*fm2;  
        LL fz=fz1/gcd(fz1,fz2)*fz2;  
        LL gc2=gcd(fz,fm);  
        fz/=gc2,fm/=gc2;   
        if(fm!=1)printf("%I64d/%I64d\n",fz,fm);  
        else printf("%I64d\n",fz/fm);  
    }  
    //system("pause");  
    return 0;  
}  