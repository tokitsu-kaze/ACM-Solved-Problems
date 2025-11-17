#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int pos[MAX];
int main()
{
	int T,n,x,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			pos[x]=i;
		}
		ans=0;
		for(i=2;i<=n;i++)
		{
			if(pos[i]<pos[i-1]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
