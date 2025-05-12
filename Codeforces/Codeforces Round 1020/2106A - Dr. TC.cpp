#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,n,i,ans;
	char s[12];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0') ans++;
			else ans+=n-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
