#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int T,n,i,x,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ans=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(i==1) x--;
			ans=min(ans,(i-1)+max(0,x-(i-1)+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}
