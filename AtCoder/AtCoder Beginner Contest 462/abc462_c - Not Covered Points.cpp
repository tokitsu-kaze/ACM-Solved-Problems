#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int p[MAX];
int main()
{
	int n,i,x,y,mn,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		p[x]=y;
	}
	ans=0;
	mn=n+1;
	for(i=1;i<=n;i++)
	{
		if(mn>p[i]) ans++;
		mn=min(mn,p[i]);
	}
	printf("%d\n",ans);
	return 0;
}
