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
const int MAX=1e5+10;
const ll mod=1e6;
struct node
{
	int v;
	friend bool operator <(node a,node b)
	{
		if(a.v%10==b.v%10) return a.v>b.v;
		return a.v%10<b.v%10;
	}
}a[MAX];
int main()
{
	int n,k,i,ans;
	node t;
	while(~scanf("%d%d",&n,&k))
	{
		priority_queue<node> q;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].v);
			q.push(a[i]);
		}
		while(k>0)
		{
			t=q.top();
			if(t.v==100) break;
			q.pop();
			int temp=10-t.v%10;
			if(k>=temp)
			{
				t.v+=temp;
				k-=temp;
			}
			else
			{
				t.v+=k;
				k=0;
			}
			q.push(t);
		} 
		ans=0;
		while(!q.empty())
		{
			t=q.top();
			q.pop();
			ans+=(t.v/10);
		}
		printf("%d\n",ans);
	}
	return 0;
}