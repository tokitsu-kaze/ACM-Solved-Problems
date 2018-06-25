////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-01-21 21:09:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5364
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2180KB
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
using namespace std;
typedef long long ll;
int main()
{
	int n,i,a,max,temp;
	map<int,int> m; 
	while(cin>>n)
	{
		m.clear();
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			m[a]++;
		}
		for(i=0;i<=9999;i++)
		{
			if(m[i]>max)
			{
				max=m[i];
				temp=i;
			}
		}
		if(max>n-max) cout<<temp<<endl;
		else puts("-1");
	}
	return 0;
}    