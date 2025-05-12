#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int a[MAX],id[MAX],cnt[MAX];
int main()
{
	int n,m,k,i,x,mx;
	scanf("%d%d",&n,&m);
	vector<vector<int>> res;
	while(m--)
	{
		scanf("%d",&k);
		vector<int> tmp(k);
		for(auto &it:tmp) scanf("%d",&it);
		res.push_back(tmp);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		id[a[i]]=i;
	}
	memset(cnt,0,sizeof cnt);
	for(auto &it:res)
	{
		mx=0;
		for(auto &it2:it) mx=max(mx,id[it2]);
		cnt[mx]++;
	}
	cnt[0]=0;
	for(i=1;i<=n;i++)
	{
		cnt[i]+=cnt[i-1];
		printf("%d\n",cnt[i]);
	}
	return 0;
}
