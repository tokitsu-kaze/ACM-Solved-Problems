#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,i,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		set<int> s;
		ans=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==k) s.clear();
			else if(x<k) s.insert(x);
			ans=min(ans,k+1-(int)s.size());
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
发现数组被k切分成若干块，每块互不影响。 
*/
