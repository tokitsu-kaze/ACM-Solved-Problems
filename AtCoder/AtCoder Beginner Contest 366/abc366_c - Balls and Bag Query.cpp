#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+10;
int cnt[MAX];
int main()
{
	int q,op,x,ans;
	scanf("%d",&q);
	memset(cnt,0,sizeof cnt);
	ans=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op!=3) scanf("%d",&x);
		if(op==1)
		{
			cnt[x]++;
			if(cnt[x]==1) ans++;
		}
		else if(op==2)
		{
			cnt[x]--;
			if(cnt[x]==0) ans--;
		}
		else printf("%d\n",ans);
	}
	return 0;
}
