////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-15 21:05:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2509
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
using namespace std;
int main()
{
	int n,a,sum,flag;
	while(cin>>n)
	{
		flag=sum=0;
		while(n--)
		{
			cin>>a;
			if(a>1) flag=1;
			sum^=a;
		}
		if(!flag)
		{
			if(sum) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
		else
		{
			if(sum) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
    return 0;
}