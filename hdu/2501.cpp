////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-28 17:36:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2501
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
	int i,t,n,f[33];
	f[1]=1;
	f[2]=3;
	for(i=3;i<=30;i++)
	{
		f[i]=f[i-1]+2*f[i-2];
	}
    while(cin>>t)
	{  
		while(t--)
		{
			cin>>n;
			cout<<f[n]<<endl;
		}
    }  
    return 0;  
}  