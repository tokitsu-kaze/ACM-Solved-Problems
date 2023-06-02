////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-28 16:59:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2568
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
	int n,a,count;
    while(cin>>n)
	{  
		while(n--)
		{
			cin>>a;
			count=0;
			while(a)
			{
				if(a&1) count++;
				a>>=1;
			}
			cout<<count<<endl;
		} 
    }  
    return 0;  
}  