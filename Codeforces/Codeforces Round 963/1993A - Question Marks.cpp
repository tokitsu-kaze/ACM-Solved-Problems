#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=800+10;
int main()
{
	int T,n,i,cnt[5],ans;
	char s[405];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=4*n;i++)
		{
			if(s[i]=='?') continue;
			cnt[s[i]-'A']++;
		}
		ans=0;
		for(i=0;i<4;i++) ans+=min(n,cnt[i]);
		printf("%d\n",ans);
	}
	return 0;
}
