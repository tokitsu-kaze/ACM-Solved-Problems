////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-06 11:20:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2178
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	__int64 n,t,s;
	while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			s=1L<<n;
			cout<<s-1<<endl;
		}
    }
    return 0;
}
