////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-15 21:03:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1907
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1572KB
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
	int t,n,a,sum,flag;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			flag=sum=0;
			while(n--)
			{
				cin>>a;
				if(a>1) flag=1;
				sum^=a;
			}
			if(!flag)
			{
				if(sum) cout<<"Brother"<<endl;
				else cout<<"John"<<endl;
			}
			else
			{
				if(sum) cout<<"John"<<endl;
				else cout<<"Brother"<<endl;
			}
		}
	}
    return 0;
}