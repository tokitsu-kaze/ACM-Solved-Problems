#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,vis[26];
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		memset(vis,0,sizeof vis);
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(vis[s[i]-'a']) continue;
			vis[s[i]-'a']=1;
			ans+=n-i+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
