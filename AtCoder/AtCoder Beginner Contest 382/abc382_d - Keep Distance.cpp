#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
vector<vector<int>> res;
int n,m,a[22];
void dfs(int x,int now)
{
	int i;
	if(x==n)
	{
		vector<int> tmp;
		for(i=0;i<n;i++) tmp.push_back(a[i]);
		res.push_back(tmp);
		return;
	}
	if((n-x-1)*10+now>m) return;
	if(now>m) return;
	for(i=now;i<=m;i++)
	{
		a[x]=i;
		dfs(x+1,i+10);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	res.clear();
	dfs(0,1);
	printf("%d\n",res.size());
	for(auto &it:res)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d%c",it[i]," \n"[i==n-1]);
		}
	}
	return 0;
}
