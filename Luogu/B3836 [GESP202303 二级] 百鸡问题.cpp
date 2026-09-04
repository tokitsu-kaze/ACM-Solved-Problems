#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int x,y,z,n,m,i,j,ans;
	scanf("%d%d%d%d%d",&x,&y,&z,&n,&m);
	ans=0;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m-i;j++)
		{
			if((m-i-j)%z) continue;
			if(x*i+j*y+(m-i-j)/z==n) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
