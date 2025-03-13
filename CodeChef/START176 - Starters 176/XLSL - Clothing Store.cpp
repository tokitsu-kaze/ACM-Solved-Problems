#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	int T,x,y,z,a,b,c,ans,tmp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
		ans=0;
		
		tmp=min(c,z);
		ans+=tmp;
		c-=tmp;
		z-=tmp;
		
		y+=z;
		z=0;
		tmp=min(b,y);
		ans+=tmp;
		b-=tmp;
		y-=tmp;
		
		x+=y;
		y=0;
		tmp=min(a,x);
		ans+=tmp;
		a-=tmp;
		x-=tmp;
		
		printf("%d\n",ans);
	}
	return 0;
}
