#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int T,n,i,vis[105],ok;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=1;i<=n;i++) vis[i]=0;
		for(i=2;i<n;i++)
		{
			if(s[i-1]=='1' && s[i]=='1' && s[i+1]=='1')
			{
				vis[i-1]=vis[i]=vis[i+1]=1;
			}
		}
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				if(vis[i]==0) ok=0;
			}
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}

