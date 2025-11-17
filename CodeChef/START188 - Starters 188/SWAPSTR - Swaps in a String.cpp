#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int mx[MAX];
char s[MAX];
int main()
{
	int T,n,i,now;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=1;i<=n;i++) mx[i]=0;
		now=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='A') now++;
			else if(s[i]=='B') mx[i]=max(mx[i],now);
			else now=0;
		}
		now=0;
		for(i=n;i;i--)
		{
			if(s[i]=='C') now++;
			else if(s[i]=='B') mx[i]=max(mx[i],now);
			else now=0;
		}
		ans=0;
		for(i=1;i<=n;i++) ans+=mx[i];
		printf("%lld\n",ans);
	}
	return 0;
}

