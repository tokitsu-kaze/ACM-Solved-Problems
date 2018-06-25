////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-04 13:34:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5224
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,s,i,ans;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>s;
			ans=INT_MAX;
			for(i=1;i*i<=s;i++)
			{
				if(s%i==0)
				{
					if(2*(i+s/i)<ans) ans=2*(i+s/i);
				}
			}
			cout<<ans<<endl;
		}
	}
    return 0;
}
