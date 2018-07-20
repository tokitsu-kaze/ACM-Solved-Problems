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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
struct node
{
	int n,k;
	friend bool operator<(node a,node b)
	{
		if(a.k==b.k) return a.n<b.n;
		return a.k<b.k;
	}
}m[MAX];
int a[MAX],ans[MAX];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,i,k,t,tempa[4];
	node x,y,z,temp;
	while(~scanf("%d",&n))
	{
		map<int,int> mp;
		map<int,int> ::iterator it;
		priority_queue<node> q;
		mem(ans,0);
		k=1;
		t=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(!mp[a[i]])
			{
				m[k].n=a[i];
				mp[a[i]]=k;
				k++;
			}
			m[mp[a[i]]].k++;
		}
		for(it=mp.begin();it!=mp.end();it++)
		{
			q.push(m[(it->second)]);
		}
		while(q.size()>=3)
		{
			mem(tempa,0);
			x=q.top();
			q.pop();
			y=q.top();
			q.pop();
			z=q.top();
			q.pop();
			tempa[0]=x.n;
			tempa[1]=y.n;
			tempa[2]=z.n;
			x.k--;
			y.k--;
			z.k--;
			if(x.k>0) q.push(x);
			if(y.k>0) q.push(y);
			if(z.k>0) q.push(z);
			sort(tempa,tempa+3,cmp);
			for(i=0;i<3;i++)
			{
				ans[t++]=tempa[i];
			}
		}
		printf("%d\n",t/3);
		for(i=0;i<t;i+=3)
		{
			printf("%d %d %d\n",ans[i],ans[i+1],ans[i+2]);
		}
	}
	return 0;
}