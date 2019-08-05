////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-05 13:37:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1896
////Problem Title: 
////Run result: Accept
////Run time:748MS
////Run memory:3416KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
struct stone
{
	int p,d;
	friend bool operator<(stone a,stone b)
	{
		if(a.p==b.p) return a.d>b.d;
		return a.p>b.p;
	}
}s;
int main()
{
    int t,n,i;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			priority_queue<stone> q;
			for(i=0;i<n;i++)
			{
				cin>>s.p>>s.d;
				q.push(s);
			}
			for(i=1;;i++)
			{
				if((!(i&1))&&q.size()==1)
				{
					cout<<q.top().p<<endl;
					break;
				}
				if(i&1)
				{
					s.p=q.top().p;
					s.d=q.top().d;
					q.pop();
					s.p+=s.d;
					q.push(s);
				}
				else
				{
					q.pop();
				}
			}
		} 
	}
    return 0;
}
