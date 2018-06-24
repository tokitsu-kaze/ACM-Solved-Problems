////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-10 15:01:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1868
////Problem Title: 
////Run result: Accept
////Run time:561MS
////Run memory:1604KB
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
#define MAX 10000+10
using namespace std;
typedef long long ll;
int main()
{
	ll n,ans,i;
	while(cin>>n)
	{
		ans=0;
		for(i=3;i<=sqrt(2*n);i++)
		{
			if(2*n%i==0)
			{
				if(i%2) ans++;
				if(2*n/i%2) ans++;
			}
		}
		if(n%2) ans++;
		cout<<ans<<endl;
	}
    return 0;
}
