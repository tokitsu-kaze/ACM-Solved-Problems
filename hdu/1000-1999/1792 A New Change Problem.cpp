////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-01-24 16:33:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1792
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1604KB
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
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    ll a,b;
    while(cin>>a>>b)
    {
		cout<<a*b-a-b<<" "<<(a-1)*(b-1)/2<<endl;
	}
    return 0;
}
