////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-15 21:02:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2177
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:17440KB
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
	int a,b,i,j;
	map<int,int> m;
	while(cin>>a>>b)
	{
		if(a+b==0) break;
		if(int((b-a)*(1+sqrt(5.0)))/2==a) cout<<"0"<<endl;
		else
		{
			cout<<"1"<<endl;
			for(i=0,j=0;i<=a;i++)
			{
				if(!m[i]&&!m[i+j])
				{
					m[i]=m[i+j]=1;
					if(a-i==b-i-j&&a-i>0&&b-i-j>0) cout<<i<<" "<<i+j<<endl;
					j++;
				}
			}
			m.clear();
			for(i=0,j=0;i<=a;i++)
			{
				if(!m[i]&&!m[i+j])
				{
					m[i]=m[i+j]=1;
					if((a==i+j&&b-i>0)||(a==i&&b-i-j>0)||(b==i+j&&a-i>0)) cout<<i<<" "<<i+j<<endl;
					j++;
				}
			}
			m.clear();
		}		
	}
    return 0;
}