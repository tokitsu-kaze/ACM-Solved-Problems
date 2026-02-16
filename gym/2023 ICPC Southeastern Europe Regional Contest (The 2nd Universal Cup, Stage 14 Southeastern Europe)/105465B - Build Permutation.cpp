#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ans[MAX],a[MAX];
int main()
{
	int n,i,ok;
	scanf("%d",&n);
	vector<pair<int,int>> res;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		res.push_back({a[i],i});
	}
	sort(res.begin(),res.end());
	for(i=0;i<n;i++) ans[res[i].second]=res[n-i-1].second;
	ok=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]+a[ans[i]]!=a[1]+a[ans[1]]) ok=0;
//		printf("%d %d\n",i,ans[i]);
	}
	if(ok==0)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
/*
4
3 3 4 4
*/
