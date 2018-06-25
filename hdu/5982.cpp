////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 15:11:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5982
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1596KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    int t,n,a,b,sum;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			sum=0;
			while(n--)
			{
				cin>>a>>b;
				sum+=a*b;
			}
			cout<<sum<<endl;
		}
	}
    return 0;
}
