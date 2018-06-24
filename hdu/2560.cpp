////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-02 23:33:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2560
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
int main()
{
    int t,n,m,i,j,a,cnt;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n>>m;
			cnt=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					cin>>a;
					if(a) cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
    return 0;
}
