////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2016-11-28 17:14:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3783
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1560KB
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
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
int main()
{ 
	int z,o,j,i;
	char a[101];
    while(cin>>a)
	{  
		if(a[0]=='E') break;
		z=o=j=0;
		for(i=0;i<strlen(a);i++)
		{
			switch(a[i])
			{
				case 'Z':z++;break;
				case 'O':o++;break;
				case 'J':j++;break;
			}
		}
		while(z+o+j!=0)
		{
			if(z)
			{
				cout<<"Z";
				z--;
			}
			if(o)
			{
				cout<<"O";
				o--;
			}
			if(j)
			{
				cout<<"J";
				j--;
			}
		}
		puts("");
    }  
    return 0;  
}  