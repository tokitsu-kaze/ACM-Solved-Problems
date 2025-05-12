#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
int main()
{
	int n,i,j,x,y,z,ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+2;j<=n;j++)
		{
			if(s[i]!=s[j]) continue;
			for(x=i+1;x<j;x++)
			{
				if(s[x]==s[i]) continue;
				for(y=j+1;y<=n;y++)
				{
					if(s[y]==s[x] || s[y]==s[i]) continue;
					for(z=y+1;z<=n;z++)
					{
						if(s[z]==s[y] || s[z]==s[x] || s[z]==s[i]) continue;
						ans++;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
