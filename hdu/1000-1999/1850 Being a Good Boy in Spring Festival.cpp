////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-10 22:25:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1850
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1588KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int main()  
{
	int n,m,a[101],i,count;
	while(cin>>n)
	{	
		if(n==0) break;
		m=count=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			m^=a[i];
		}
		for(i=0;i<n;i++)
		{
			if((m^a[i])<a[i]) count++;
		}
		cout<<count<<endl;
    }
    return 0;  
}  
  