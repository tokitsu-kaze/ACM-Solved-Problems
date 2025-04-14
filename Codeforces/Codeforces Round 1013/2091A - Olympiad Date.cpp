#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	string tmp="01032025";
	int T,cnt[22],i,j,x,n,ans,ok;
	scanf("%d",&T);
	while(T--)
	{
		memset(cnt,0,sizeof cnt);
		for(auto &it:tmp) cnt[it-'0']++;
		scanf("%d",&n);
		ans=n+1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			cnt[x]--;
			ok=1;
			for(j=0;j<=9;j++)
			{
				if(cnt[j]>0) ok=0;
			}
			if(ok) ans=min(ans,i);
		}
		if(ans==n+1) ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
