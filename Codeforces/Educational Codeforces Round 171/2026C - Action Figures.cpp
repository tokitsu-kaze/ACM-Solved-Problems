#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
char s[MAX];
int main()
{
	int T,n,i,cnt;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ans=0;
		for(i=1;i<=n;i++) ans+=i;
		cnt=n;
		for(i=n;i;i--)
		{
			if(s[i]=='0') continue;
			cnt=min(cnt,i);
			if(cnt>1)
			{
				ans-=i;
				cnt-=2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
