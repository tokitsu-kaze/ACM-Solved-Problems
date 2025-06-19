#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int cnt[MAX],a[MAX];
int main()
{
	int T,n,i,tot,now,ans,pos,del;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) cnt[i]=0;
		tot=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
			if(cnt[a[i]]==1) tot++;
		}
		pos=n;
		ans=0;
		while(pos>=1)
		{
			map<int,int> mp;
			now=0;
			del=0;
			for(i=pos;i;i--)
			{
				cnt[a[i]]--;
				if(cnt[a[i]]==0) del++;
				if(!mp.count(a[i]))
				{
					now++;
					mp[a[i]]=1;
					if(now==tot)
					{
						pos=i-1;
						break;
					}
				}
			}
			tot-=del;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
