#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=100+10;
int main()
{
	int T,n,k,x,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		set<int> s;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			s.insert(x);
		}
		if(s.size()>k)
		{
			puts("-1");
			continue;
		}
		vector<int> res;
		for(auto &it:s) res.push_back(it);
		while(res.size()<k) res.push_back(1);
		printf("%d\n",n*k);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<k;j++)
			{
				printf("%d%c",res[j]," \n"[(i-1)*k+j==n*k-1]);
			}
		}
	}
	return 0;
}
