////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-31 22:36:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2549
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1592KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int n,i,a,len;
	char c[101];
	while(cin>>n)
	{
		while(n--)
		{
			scanf("%s%d",c,&a);
			len=strlen(c);
			for(i=0;;i++)
			{
				if(c[i]=='.')
				{
					if(a+i+1>len) cout<<"0"<<endl;
					else cout<<c[a+i]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}