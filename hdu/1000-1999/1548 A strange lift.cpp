////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-10 20:47:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1548
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1604KB
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
#define MAX 10000+10
using namespace std;
typedef long long ll;
int n,k[210],flag[210];
void bfs(int a,int b)
{
	int t,next;
	queue<int>q;
	q.push(a);
	flag[a]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t==b) break;
		next=t+k[t];
		if(next>=1&&next<=b&&!flag[next])
		{
			q.push(next);
			flag[next]=flag[t]+1;
		}
		next=t-k[t];
		if(next>=1&&next<=b&&!flag[next])
		{
			q.push(next);
			flag[next]=flag[t]+1;
		}
	}
	if(t!=b) flag[b]=0;
}
int main()
{
	int a,b,i; 
	while(cin>>n&&n)
	{
		cin>>a>>b;
		mem(k,0);
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			cin>>k[i];
		}
		bfs(a,b);
		cout<<flag[b]-1<<endl;
	}
    return 0;
}
