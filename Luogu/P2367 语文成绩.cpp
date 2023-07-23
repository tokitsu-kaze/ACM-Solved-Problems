#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e6+10;
int bit[MAX],a[MAX];
int main()
{
	int n,q,i,x,y,z,ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	while(q--)
	{
		scanf("%d%d%d",&x,&y,&z);
		bit[x]+=z;
		bit[y+1]-=z;
	}
	bit[0]=0;
	ans=INF;
	for(i=1;i<=n;i++)
	{
		bit[i]+=bit[i-1];
		a[i]+=bit[i];
		ans=min(ans,a[i]);
	}
	printf("%d\n",ans);
	return 0;
}
