#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e5+10;
int main()
{
	int T,n,x,i,cnta,cntb,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnta=cntb=ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==1) cntb++;
			else
			{
				cnta+=cntb;
				cntb=0;
			}
			ans=max(ans,cntb+(cnta>0?cnta/2+1:0));
		}
		printf("%d\n",ans);
		
	}
	return 0;
}
