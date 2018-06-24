////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-29 18:41:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4699
////Problem Title: 
////Run result: Accept
////Run time:1419MS
////Run memory:12272KB
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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int l[MAX],sum[MAX],maxx[MAX],topl;
int main()
{
	int t,i,x;
	char op[22];
	while(~scanf("%d",&t))
	{
		stack<int> r;
		topl=0;
		maxx[0]=0;
		sum[0]=0;
		while(t--)
		{
			scanf("%s",&op);
			if(op[0]=='I')
			{
				scanf("%d",&x);
				l[++topl]=x;
				sum[topl]=sum[topl-1]+x;
				if(topl!=1) maxx[topl]=max(maxx[topl-1],sum[topl]);
				else maxx[topl]=sum[topl];
			}
			else if(op[0]=='Q')
			{
				scanf("%d",&x);
				printf("%d\n",maxx[x]);
			}
			else if(op[0]=='L'&&topl>0)
			{
				r.push(l[topl]);
				topl--;
			}
			else if(op[0]=='R'&&r.size())
			{
				l[++topl]=r.top();
				sum[topl]=sum[topl-1]+r.top();
				maxx[topl]=max(maxx[topl-1],sum[topl]);
				r.pop();
			}
			else if(op[0]=='D')
			{
				topl--;
			}
		}
	}
	return 0;
}
/*
100
I -1000
I 500
Q 1
Q 2
*/