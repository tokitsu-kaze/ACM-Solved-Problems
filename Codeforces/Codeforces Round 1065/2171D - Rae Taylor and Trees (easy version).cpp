#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX];
int main()
{
	int T,n,i,mn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		vector<pair<int,int>> res;
		set<int> s;
		s.insert(INF);
		mn=p[1];
		for(i=2;i<=n;i++)
		{
			if(p[i]>=mn)
			{
				res.push_back({mn,p[i]});
				mn=min(mn,p[i]);
				auto it=s.lower_bound(p[i]);
				if(it!=s.begin())
				{
					it--;
					vector<int> del;
					while(1)
					{
						res.push_back({*it,p[i]});
						del.push_back(*it);
						mn=min(mn,*it);
						if(it==s.begin()) break;
						it--;
					}
					for(auto &it2:del) s.erase(it2);
				}
			}
			else s.insert(p[i]);
		}
		if(res.size()==n-1) puts("Yes");
		else puts("No");
	}
	return 0;
}
