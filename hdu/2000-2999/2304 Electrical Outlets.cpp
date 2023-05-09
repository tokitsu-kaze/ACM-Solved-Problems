////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-28 16:51:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2304
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1588KB
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
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,a,i,sum;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			sum=0;
			for(i=0;i<n;i++)
			{
				cin>>a;
				sum+=a;
			}
			cout<<sum-n+1<<endl;
		}
	}
    return 0;
}