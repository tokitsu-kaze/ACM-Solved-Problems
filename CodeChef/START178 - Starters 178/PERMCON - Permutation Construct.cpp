#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,i,j,vis[105],res[105],ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		memset(vis,0,sizeof vis);
		ok=1;
		for(i=n;i;i--)
		{
			res[i]=0;
			for(j=i%k;j<=n;j+=k)
			{
				if(j==0 || j==i || vis[j]) continue;
				vis[j]=1;
				res[i]=j;
				break;
			}
			if(res[i]==0) ok=0;
		}
		if(!ok)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}

