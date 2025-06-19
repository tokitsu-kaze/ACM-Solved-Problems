#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int ans[MAX];
int main()
{
	int T,n,i,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		multiset<int> s;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&l,&r);
			auto it=s.upper_bound(r);
			if(it!=s.end()) s.erase(it);
			s.insert(l);
			ans[i]=s.size();
		}
		for(i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}

