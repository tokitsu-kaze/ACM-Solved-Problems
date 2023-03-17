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
const int MAX=2e5+10;
const ll mod=1e6;
struct node
{
	int x,v;
	node(){}
	node(int a,int b)
	{
		x=a;
		v=b;
	}
};
int ans[MAX],a[MAX],n;
void bfs()
{
	node t;
	queue<node> q;
	t.x=1;
	t.v=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
	//	cout<<t.x<<endl;
		if(ans[t.x]>t.v)
		{
			ans[t.x]=t.v;
			if(t.x>1) q.push(node(t.x-1,t.v+1));
			if(t.x<n) q.push(node(t.x+1,t.v+1));
			if(a[t.x]!=t.x) q.push(node(a[t.x],t.v+1));
		}
		
	}
}
int main()
{
	int i;
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)
		{
			ans[i]=INF;
			scanf("%d",&a[i]);
		}
		bfs();
		for(i=1;i<=n;i++)
		{
			if(i==n) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}