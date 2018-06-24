////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-16 15:50:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1113
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1620KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int flag;
	char a[111],b[111];
	map<string,string> m;
	while(~scanf("%s",a))
	{
		if(strcmp(a,"XXXXXX")==0) break;
		strcpy(b,a);
		sort(a,a+strlen(a));
		m[b]=a;
	}
	while(~scanf("%s",a))
	{
		if(strcmp(a,"XXXXXX")==0) break;
		sort(a,a+strlen(a));
		map<string,string> ::iterator it;
		flag=0;
		for(it=m.begin();it!=m.end();it++)
		{
			if(it->second.compare(a)==0)
			{
				cout<<it->first<<endl;
				flag=1;
			}
		}
		if(!flag) puts("NOT A VALID WORD");
		puts("******");
	}
	return 0;
}
