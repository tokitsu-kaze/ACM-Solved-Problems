////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-07-27 18:54:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6047
////Problem Title: 
////Run result: Accept
////Run time:717MS
////Run memory:8288KB
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
const int MAX=3e5+10;
const ll mod=1e9+7;
int a[MAX],b[MAX];
struct node
{
	int pos,v;
	node(){}
	node(int a,int b)
	{
		pos=a;
		v=b;
	}
	friend bool operator<(node a,node b)
	{
		return a.v<b.v;
	}
};
int main()
{
	int n,i;
	ll ans;
	while(~scanf("%d",&n))
	{
		priority_queue<node> q;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			q.push(node(i,a[i]-i));
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
		}
		sort(b+1,b+1+n);
		ans=0;
		for(i=1;i<=n;i++)
		{
			node temp=q.top();
			while(temp.pos<b[i])
			{
				q.pop(); 
				temp=q.top();
			}
			ans=(ans+(ll)temp.v)%mod;
			q.push(node(n+i,temp.v-(n+i)));
		}
		printf("%lld\n",ans);
	}
	return 0;
}