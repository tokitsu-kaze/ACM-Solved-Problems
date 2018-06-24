////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-02 20:45:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2148
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
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
typedef long long ll;
int main()
{
	int t,n,k,i,a[1010],cnt;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>k;
			cnt=0;
			for(i=1;i<=n;i++)
			{
				cin>>a[i];
			}
			for(i=1;i<=n;i++)
			{
				if(a[i]>a[k]) cnt++;
			}
			cout<<cnt<<endl;
		}	
	}
    return 0;
}