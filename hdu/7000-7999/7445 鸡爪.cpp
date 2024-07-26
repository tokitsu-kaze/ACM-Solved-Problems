#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e4+10;
const int mod=998244353;
int d[MAX];
int main()
{
	int t,n,i,j,k,tot;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		k=n/3;
		for(i=2;i<=k;i++) d[i]=2;
		vector<pair<int,int>> res;
		tot=k+3;
		tot+=n%3;
		for(i=2;i<=tot;i++)
		{
			if(res.size()>=n) break;
			res.push_back({1,i});
		}
		for(i=2;i<=tot;i++)
		{
			if(res.size()>=n) break;
			for(j=i+1;j<=tot;j++)
			{
				if(res.size()>=n) break;
				if(d[j]>0)
				{
					d[j]--;
					res.push_back({i,j});
				}
				else if(d[i]>0)
				{
					d[i]--;
					res.push_back({i,j});
				}
			}
		}
		assert(res.size()==n);
		for(auto &it:res) printf("%d %d\n",it.first,it.second);
	}
	return 0;
}
