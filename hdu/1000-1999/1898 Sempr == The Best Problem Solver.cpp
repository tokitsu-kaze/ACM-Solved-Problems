////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-28 18:21:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1898
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1584KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
using namespace std;
int main ()  
{
    int n,a,b,t;
    while(cin>>n)
	{
		while(n--)
		{
			cin>>a>>b>>t;
			if(t%a<t%b) cout<<"Sempr!"<<endl;
			else if(t%a==t%b) cout<<"Both!"<<endl;
			else cout<<"Xiangsanzi!"<<endl;
		}
	}
    return 0;  
}