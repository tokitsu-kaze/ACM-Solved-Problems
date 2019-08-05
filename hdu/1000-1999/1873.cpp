////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-05 11:29:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1873
////Problem Title: 
////Run result: Accept
////Run time:171MS
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
struct patient
{
	int id;
	int r;
	friend bool operator<(patient a,patient b)
	{
		if(a.r==b.r) return a.id>b.id;
		return a.r<b.r;
	}
}p;
int main()
{
    int n,i,d,k;
    char a[5];
    while(cin>>n)
    {
		k=1;
		priority_queue<patient> q[4];
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			if(a[0]=='I')
			{
				cin>>d>>p.r;
				p.id=k++;
				q[d].push(p);
			}
			else
			{
				cin>>d;
				if(q[d].empty()) puts("EMPTY");
				else
				{
					cout<<q[d].top().id<<endl;
					q[d].pop();
				}
			}
		}
	}
    return 0;
}
