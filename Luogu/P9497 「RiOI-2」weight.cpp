#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,q,i,j,v;
	scanf("%d%d",&n,&q);
	vector<int> res;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&v);
			res.push_back(v);
		}
	}
	sort(res.begin(),res.end());
	while(q--)
	{
		scanf("%d",&v);
		printf("%d\n",min(n,
		int(res.end()-lower_bound(res.begin(),res.end(),v))));
	}
	return 0;
}
