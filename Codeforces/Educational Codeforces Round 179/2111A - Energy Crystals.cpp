#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		vector<int> now(3,0);
		ans=0;
		while(1)
		{
			sort(now.begin(),now.end());
			if(now[0]==n) break;
			now[0]=min(n,(now[1]+1)*2-1);
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
