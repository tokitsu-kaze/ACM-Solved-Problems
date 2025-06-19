#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1.5e5+10;
int a[MAX],pre[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(pre,0,sizeof pre);
		ans=-1;
		for(i=1;i<=n;i++)
		{
			if(pre[a[i]]) ans=max(ans,pre[a[i]]+(n-i));
			pre[a[i]]=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
