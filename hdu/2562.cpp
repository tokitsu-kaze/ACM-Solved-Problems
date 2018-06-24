////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-03 09:43:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2562
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
    int t,i;
    char a[51];
    while(cin>>t)
    {
		getchar();
		while(t--)
		{
			mem(a,0);
			gets(a);
			for(i=0;i<strlen(a);i+=2)
			{
				if(a[i]!='/0') swap(a[i],a[i+1]);
			}
			cout<<a<<endl;
		}
	}
    return 0;
}
