#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int t,n,i,ans;
	char s[111];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ans=0;
		for(i=1;i<=n;i++) ans=max(ans,s[i]-'a'+1);
		printf("%d\n",ans);
	}
	return 0;
}
