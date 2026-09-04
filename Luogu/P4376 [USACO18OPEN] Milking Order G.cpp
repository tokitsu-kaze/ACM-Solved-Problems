#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
vector<int> mp[MAX],a[MAX],toplist;
int n,m,in[MAX];
void topsort()
{
	priority_queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(!in[i]) q.push(-i);
	}
	toplist.clear();
	while(!q.empty())
	{
		int x=-q.top();
		q.pop();
		toplist.push_back(x);
		for(auto &to:mp[x])
		{
			in[to]--;
			if(!in[to]) q.push(-to);
		}
	}
}
int ck(int x)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		mp[i].clear();
		in[i]=0;
	}
	for(i=1;i<=x;i++)
	{
		for(j=1;j<a[i].size();j++)
		{
			mp[a[i][j-1]].push_back(a[i][j]);
			in[a[i][j]]++;
		}
	}
	topsort();
	return toplist.size()==n;
}
int main()
{
	int i,k,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		a[i].clear();
		scanf("%d",&k);
		a[i].resize(k);
		for(auto &it:a[i]) scanf("%d",&it);
	}
	l=0;
	r=m;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1)) l=mid+1;
		else r=mid;
	}
	ck(l);
	for(i=0;i<n;i++) printf("%d%c",toplist[i]," \n"[i+1==n]);
	return 0;
}
/*
二分答案建图跑拓扑判环就做完了。
按题意模拟。
*/
