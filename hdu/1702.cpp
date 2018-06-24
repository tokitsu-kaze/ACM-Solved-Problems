////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-04 22:36:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1702
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1612KB
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
int main()
{
    int t,n,i,k;
    char a[11],b[5];
    while(cin>>t)
    {
		while(t--)
		{
			scanf("%d %s",&n,a);
			if(a[2]=='L')
			{
				stack<int> s;
				for(i=0;i<n;i++)
				{
					scanf("%s",b);
					if(b[0]=='I')
					{
						scanf("%d",&k);
						s.push(k);
					}
					else
					{
						if(s.empty()) puts("None");
						else
						{
							cout<<s.top()<<endl;
							s.pop();
						}
					}
				}
			}
			else
			{
				queue<int> q;
				for(i=0;i<n;i++)
				{
					scanf("%s",b);
					if(b[0]=='I')
					{
						scanf("%d",&k);
						q.push(k);
					}
					else
					{
						if(q.empty()) puts("None");
						else
						{
							cout<<q.front()<<endl;
							q.pop();
						}
					}
				}
			}
		}
	}
    return 0;
}
