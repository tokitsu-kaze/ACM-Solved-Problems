////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-30 17:42:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5948
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
using namespace std; 
int main()
{
    int n,a,b;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>a>>b;
            if(a>b) cout<<2*a+b<<endl;
            else cout<<2*b+a<<endl;
        }
    } 
    return 0;
}