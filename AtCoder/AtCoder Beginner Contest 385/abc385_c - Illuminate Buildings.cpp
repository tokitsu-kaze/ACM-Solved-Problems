#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3000+10;
int h[MAX];
int main()
{
	int n,i,j,k,ans,now;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&h[i]);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			now=0;
			for(k=j;k<=n;k+=i)
			{
				if(h[k]!=h[j]) break;
				now++;
			}
			ans=max(ans,now);
		}
	}
	printf("%d\n",ans);
	return 0;
}
