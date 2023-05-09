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
    int t,n,i,a,sta[1010],k=1;
    char c[11];
	while(cin>>t&&t)
	{
		queue<int> q[1010],qid;
		map<int,int> id;
		mem(sta,0);
		for(i=0;i<t;i++)
		{
			cin>>n;
			while(n--)
			{
				cin>>a;
				id[a]=i;
			}
		}
		printf("Scenario #%d\n",k++);
		while(1)
		{
			scanf("%s",c);
			if(c[0]=='S') break;
			if(c[0]=='E')
			{
				cin>>a;
				q[id[a]].push(a);
				if(sta[id[a]]==0)
				{
					sta[id[a]]=1;
					qid.push(id[a]);
				}
			}
			else if(c[0]=='D')
			{
				cout<<q[qid.front()].front()<<endl;
				q[qid.front()].pop();
				if(q[qid.front()].empty())
				{
					sta[qid.front()]=0;
					qid.pop();
				}
			}
		}
		puts("");
	} 
    return 0;
}