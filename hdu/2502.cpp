////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-28 17:48:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2502
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1580KB
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
#include <bitset>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{
	int t,n;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			cout<<(1<<(n-1))+(n-1)*(1<<(n-2))<<endl;
		}
	}
	return 0;
}