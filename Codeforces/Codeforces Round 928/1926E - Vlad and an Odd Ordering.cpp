#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int t,n,k,now,ans,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		now=0;
		while(k>0)
		{
			if(k-(n+1)/2<=0) break;
			k-=(n+1)/2;
			n-=(n+1)/2;
			now++;
		}
		ans=1<<now;
		for(i=0;i<k-1;i++) ans+=1<<(now+1);
		printf("%d\n",ans);
	}
	return 0;
}
