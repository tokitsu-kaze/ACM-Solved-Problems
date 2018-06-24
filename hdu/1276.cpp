////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-03-05 09:22:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1276
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1832KB
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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 10000+10
using namespace std;
//typedef __int64 ll;
typedef long long ll;
int main()
{
	int n,i,m,cas;
	while(cin>>cas)
	{
		while(cas--)
		{
			cin>>n;
			list<int> l;
			list<int> ::iterator it,del;
			l.clear();
			for(i=1;i<=n;i++)
			{
				l.push_back(i);
			}
			m=l.size();
			while(m>3)
			{
				i=1;
				for(it=l.begin();it!=l.end();)
				{
					if(i==2)
					{
						i=1;
						del=it;
						it++;
						l.erase(del);
						m--;
					}
					else
					{
						i++;
						it++;
					}
				}
				i=1;
				if(m<=3) break;
				for(it=l.begin();it!=l.end();)
				{
					if(i==3)
					{
						i=1;
						del=it;
						it++;
						l.erase(del);
						m--;
					}
					else
					{
						i++;
						it++;
					}
				}
			}
			for(it=l.begin(),i=1;it!=l.end();it++,i++)
			{
				cout<<(*it);
				if(i!=m) cout<<" ";
				else puts("");
			}
		}
	}
    return 0; 
}