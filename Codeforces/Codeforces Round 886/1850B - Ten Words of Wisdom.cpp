#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int t,n,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<pair<int,int>> res;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			if(a<=10) res.push_back({b,i});
		}
		sort(res.begin(),res.end());
		printf("%d\n",res.back().second);
	}
	return 0;
}
