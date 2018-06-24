////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-01-22 14:06:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2133
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 1000000+10
using namespace std;
typedef long long ll;
int t[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int check(int y)
{
	return (y%4==0&&y%100!=0)||y%400==0;
}
int checkday(int y,int m,int d)
{
	if(m!=2)
	{
		if(d>t[m]) return 1;
	}
	else
	{
		if(check(y))
		{
			if(d>29) return 1;
		}
		else
		{
			if(d>28) return 1;
		}
	}
	return 0;
}
int main()
{
    int y,m,d,i,sum;
    while(cin>>y>>m>>d)
    {
		if(m==0||d==0)
		{
			puts("illegal");
			continue;
		}
		else if(checkday(y,m,d))
		{
			puts("illegal");
			continue;
		}
		sum=0;
		for(i=1;i<y;i++)
		{
			if(check(i))sum+=366;
			else sum+=365;
		}
		for(i=1;i<m;i++)
		{
			if(check(y)&&i==2) sum+=29;
			else sum+=t[i]; 
		} 
		sum+=d;
		sum%=7;
	//	cout<<sum<<endl;
		switch(sum)
		{
			case 1:puts("Monday");break;
			case 2:puts("Tuesday");break;
			case 3:puts("Wednesday");break;
			case 4:puts("Thursday");break;
			case 5:puts("Friday");break;
			case 6:puts("Saturday");break;
			case 0:puts("Sunday");break;
		}
	}
    return 0;
}