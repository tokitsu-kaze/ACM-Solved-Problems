#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],t[MAX];
int la[MAX],ra[MAX],lb[MAX],rb[MAX],na,nb;
int main()
{
	int T,n,i;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		if((!(s[1]==t[1])) || (!(s[n]==t[n])))
		{
			puts("-1");
			continue;
		}
		s[0]=t[0]='0';
		s[n+1]=t[n+1]='0';
		na=0;
		for(i=1;i<=n+1;i++)
		{
			if(s[i]=='1' && s[i-1]=='0')
			{
				na++;
				la[na]=i;
			}
			else if(s[i]=='0' && s[i-1]=='1') ra[na]=i;
		}
		nb=0;
		for(i=1;i<=n+1;i++)
		{
			if(t[i]=='1' && t[i-1]=='0')
			{
				nb++;
				lb[nb]=i;
			}
			else if(t[i]=='0' && t[i-1]=='1') rb[nb]=i;
		}
		if(na!=nb)
		{
			puts("-1");
			continue;
		}
		ans=0;
		for(i=1;i<=na;i++) ans+=abs(la[i]-lb[i])+abs(ra[i]-rb[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
