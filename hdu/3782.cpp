////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-28 17:07:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3782
////Problem Title: 
////Run result: Accept
////Run time:46MS
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
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{ 
	int n,count;
    while(cin>>n)
	{  
		if(n==0) break;
		count=0;
		while(n!=1)
		{
			if(n&1) n=(3*n+1)>>1;
			else n>>=1;
			count++;
		}
		cout<<count<<endl;
    }  
    return 0;  
}  