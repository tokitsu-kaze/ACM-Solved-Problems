////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-08 22:31:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2674
////Problem Title: 
////Run result: Accept
////Run time:31MS
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
using namespace std;
int main()  
{
	int n,i,fact[2011];
	fact[0]=1;
	for(i=1;i<2009;i++)
	{
		fact[i]=(fact[i-1]*i)%2009;
	}
	while(cin>>n)
	{	
		if(n>=2009) cout<<"0"<<endl;
		else cout<<fact[n]<<endl; 
    }
    return 0;  
}  
  