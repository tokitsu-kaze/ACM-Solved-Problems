#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int MAX=1e6+10;
int cnt[MAX],pos[MAX];
int main()
{
	int n,q,i,op,x,y,ans;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
	{
		cnt[i]=1;
		pos[i]=i;
	}
	ans=0;
	while(q--)
	{
		scanf("%d",&op);
		if(op==2)
		{
			printf("%d\n",ans);
			continue;
		}
		scanf("%d%d",&x,&y);
		cnt[pos[x]]--;
		if(cnt[pos[x]]==1) ans--;
		pos[x]=y;
		cnt[pos[x]]++;
		if(cnt[pos[x]]==2) ans++;
	}
	return 0;
}

