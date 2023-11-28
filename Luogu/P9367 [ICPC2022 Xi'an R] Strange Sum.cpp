#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int n,i,x,mx,ans;
	scanf("%d",&n);
	ans=0;
	mx=-1e9;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		ans=max(ans,x);
		ans=max(ans,x+mx);
		mx=max(mx,x);
	}
	printf("%d\n",ans);
	return 0;
}
