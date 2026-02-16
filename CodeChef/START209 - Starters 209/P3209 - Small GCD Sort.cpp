#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<pair<int,int>> res;
		for(i=1;i<=n;i++) res.push_back({-__gcd(i,n),i});
		sort(res.begin(),res.end());
		for(i=1;i<=n;i++) printf("%d%c",res[i-1].second," \n"[i==n]);
	}
	return 0;
}
