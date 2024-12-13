#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,m,k,i,ans,r,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		scanf("%s",s+1);
		r=0;
		ans=0;
		now=0;
		for(i=1;i<=n;i++)
		{
			if(i<=r) continue;
			if(s[i]=='0') now++;
			else now=0;
			if(now==m)
			{
				ans++;
				r=i+k-1;
				now=0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
