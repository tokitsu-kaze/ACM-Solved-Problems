#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,h,i,mx[3],ans,s,d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&h);
		mx[1]=mx[2]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&s,&d);
			mx[s]=max(mx[s],d);
		}
		ans=0;
		if(mx[1]*2<mx[2])
		{
			ans+=h/mx[2]*2;
			h%=mx[2];
		}
		else
		{
			ans+=h/mx[1];
			h%=mx[1];
		}
		if(h>0)
		{
			if(h<=mx[1]) ans++;
			else ans+=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}

