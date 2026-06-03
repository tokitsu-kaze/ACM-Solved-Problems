#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int c[MAX];
int main()
{
	int n,m,i,a,b,ans,tmp;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) scanf("%d",&c[i]);
	ans=0;
	while(n--)
	{
		scanf("%d%d",&a,&b);
		tmp=min(c[a],b);
		c[a]-=tmp;
		ans+=tmp;
	}
	printf("%d\n",ans);
	return 0;
}
