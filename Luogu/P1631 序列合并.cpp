#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int a[MAX],b[MAX];
struct node
{
	int i,j;
	friend bool operator<(node x,node y)
	{
		return a[x.i]+b[x.j]>a[y.i]+b[y.j];
	}
};
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	priority_queue<node> q;
	for(i=1;i<=n;i++) q.push({i,1});
	vector<int> res;
	while(res.size()<n)
	{
		node t=q.top();
		q.pop();
		res.push_back(a[t.i]+b[t.j]);
		if(t.j<n) q.push({t.i,t.j+1});
	}
	for(i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
	return 0;
}
