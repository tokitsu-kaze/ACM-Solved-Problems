#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX];
int main()
{
	int T,n,i,ans,sufmn,pre,premn;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		sufmn=pre=0;
		premn=INF;
		for(i=1;i<=n;i++)
		{
			if(a[i]==a[1])
			{
				pre++;
				sufmn++;
			}
			else
			{
				pre--;
				sufmn=min(sufmn-1,-1);
			}
			premn=min(premn,pre);
			if(premn>0 && sufmn>0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1 1 1 2 1 2 1 2 1 2 1 1 1
1 1 1 1 2 2 1 2 2 1 1 1 1
*/
