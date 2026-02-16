#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,x;
	scanf("%d",&n);
	vector<pair<int,int>> res;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		res.push_back({x,i});
	}
	sort(res.begin(),res.end());
	printf("%d %d %d\n",res[0].second,res[1].second,res[2].second);
	return 0;
}
