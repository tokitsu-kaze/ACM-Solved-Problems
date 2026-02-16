#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
char s[MAX];
int main()
{
	int n,i,pre,now,prec;
	ll ans;
	scanf("%s",s+1);
	n=strlen(s+1);
	pre=now=ans=0;
	s[0]='\0';
	prec=-1;
	for(i=1;i<=n;i++)
	{
		if(s[i]==s[i-1]) now++;
		else
		{
			if(prec+1==s[i-1]) ans+=min(pre,now);
			pre=now;
			now=1;
			prec=s[i-1];
		}
	}
	if(prec+1==s[n]) ans+=min(pre,now);
	printf("%lld\n",ans);
	return 0;
}
