#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,i,cnta;
	ll ans;
	char s[55],t[55];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		cnta=0;
		for(i=1;i<=n;i++) cnta+=(s[i]=='a');
		if(cnta==0)
		{
			puts("1");
			continue;
		}
		cnta=0;
		for(i=1;i<=m;i++) cnta+=(t[i]=='a');
		if(cnta==1 && m==1)
		{
			puts("1");
			continue;
		}
		if(cnta>=1 && m>1)
		{
			puts("-1");
			continue;
		}
		ans=1;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='a') ans*=2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
