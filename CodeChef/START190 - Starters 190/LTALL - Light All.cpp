#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,vis[105],ok;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		memset(vis,0,sizeof vis);
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0') continue;
			if(i==1) vis[i+1]=1;
			else
			{
				if(!vis[i-1]) vis[i-1]=1;
				else vis[i+1]=1;
			}
			vis[i]=1;
		}
		ok=1;
		for(i=1;i<=n;i++) ok&=vis[i];
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}

