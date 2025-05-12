#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,j,vis[105],cnt,res[105];
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+2);
		cnt=0;
		for(i=2;i<=n;i++) cnt+=(s[i]=='<');
		for(i=1;i<=n;i++) vis[i]=0;
		res[1]=cnt+1;
		vis[res[1]]=1;
		for(i=2;i<=n;i++)
		{
			if(s[i]=='<')
			{
				for(j=res[i-1]-1;j>=1;j--)
				{
					if(!vis[j])
					{
						res[i]=j;
						vis[j]=1;
						break;
					}
				}
			}
			else
			{
				for(j=res[i-1]+1;j<=n;j++)
				{
					if(!vis[j])
					{
						res[i]=j;
						vis[j]=1;
						break;
					}
				}
			}
		}
		for(i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	}
	return 0;
}

