#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int n,k,a[15];
vector<vector<int>> res;
void dfs(int x,int now)
{
	int i;
	if(x==1)
	{
		a[1]=k-now;
		vector<int> tmp;
		for(i=1;i<=n;i++) tmp.push_back(a[i]);
		res.push_back(tmp);
		return;
	}
	for(i=(k-now)/x;~i;i--)
	{
		a[x]=i;
		dfs(x-1,now+i*x);
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&k);
	res.clear();
	dfs(n,0);
	sort(res.begin(),res.end());
	for(auto &it:res)
	{
		for(i=0;i<n;i++) printf("%d%c",it[i]," \n"[i+1==n]);
	}
	return 0;
}
