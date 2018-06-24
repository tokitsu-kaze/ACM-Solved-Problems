////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 18:10:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1877
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main ()  
{
    int m,a,b;
    char s[1001];
    while(cin>>m)
	{
		if(m==0) break;
		cin>>a>>b;
		itoa(a+b,s,m);
		cout<<s<<endl;
	}
    return 0;  
}