////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-10-31 21:41:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2700
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1568KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int len,i,sum;
	char s[35];
	while(~scanf("%s",s))
	{
		if(s[0]=='#') break;
		len=strlen(s);
		sum=0;
		for(i=0;i<len-1;i++)
		{
			if(s[i]=='1') sum++;
		}
		for(i=0;i<len-1;i++)
		{
			cout<<s[i];
		}
		if(sum%2!=0)
		{
			if(s[len-1]=='o') cout<<"0"<<endl;
			else cout<<"1"<<endl;
		}
		else if(sum%2==0)
		{
			if(s[len-1]=='e') cout<<"0"<<endl;
			else cout<<"1"<<endl;
		}
	}
	return 0;
}