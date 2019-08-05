////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-04-06 19:04:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1075
////Problem Title: 
////Run result: Accept
////Run time:1154MS
////Run memory:76436KB
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
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int i,k;
	char s[3011],c[3011],t[3011];
	map<string,string> mp;
	while(~scanf("%s",s))
	{
		if(strcmp(s,"START")==0)
		{
			mp.clear();
			continue;
		}
		if(strcmp(s,"END")==0) break;
		scanf(" %s",c);
		mp[c]=s;
//		cout<<mp[c]<<endl;
	}
	getchar();
	while(gets(s))
	{
		if(strcmp(s,"START")==0) continue;
		if(strcmp(s,"END")==0) break;
		mem(t,0);
		for(i=0,k=0;i<strlen(s);i++)
		{
			if(s[i]>='a'&&s[i]<='z') t[k++]=s[i];
			else
			{
				if(k)
				{
					if(mp[t].length())cout<<mp[t];
					else cout<<t;
					mem(t,0);
					k=0;
				}
				printf("%c",s[i]);
			}
		}
		if(k) cout<<t;
		puts("");
	}
	return 0;
}
