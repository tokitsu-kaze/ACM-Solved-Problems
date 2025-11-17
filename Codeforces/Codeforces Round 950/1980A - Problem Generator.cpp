#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,i,ans,cnt[26];
	char s[55];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		for(i=1;i<=n;i++) cnt[s[i]-'A']++;
		ans=0;
		for(i=0;i<='G'-'A';i++) ans+=max(0,m-cnt[i]);
		printf("%d\n",ans);
	}
	return 0;
}
