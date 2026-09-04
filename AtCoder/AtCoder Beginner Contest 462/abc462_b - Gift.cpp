#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
vector<int> res[MAX];
int main()
{
	int n,k,i,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) res[i].clear();
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&x);
			res[x].push_back(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		sort(res[i].begin(),res[i].end());
		printf("%d",(int)res[i].size());
		for(auto &it:res[i]) printf(" %d",it);
		puts("");
	}
	return 0;
}
