#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node
{
	int mx,x;
	friend bool operator <(node a,node b)
	{
		return a.mx>b.mx;
	}
};
int a[MAX],in[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) in[i]=0;
	for(i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		in[a[i]]++;
	}
	priority_queue<node> q;
	for(i=1;i<=n;i++)
	{
		if(!in[i]) q.push({i,i});
	}
	printf("%d\n",a[1]);
	for(i=n-1;i;i--)
	{
		node t=q.top();
		q.pop();
		printf("%d %d\n",t.x,a[i]);
		in[a[i]]--;
		if(!in[a[i]]) q.push({max(t.mx,a[i]),a[i]});
	}
	return 0;
}
/*
感觉难点在读题。
发现通过输入能够直接得到哪些点是叶子。
从叶子向上推，用个堆维护子树权值的最小值，做一个类似拓扑排序的东西。
由于边权都是2^i，直接维护最高位就行。
*/
