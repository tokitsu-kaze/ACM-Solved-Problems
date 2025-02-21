#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=1e9+7;
const int MAX=5e5+10;
char s[MAX];
int main()
{
	int n,i,precnt,sufcnt;
	ll pre,suf,ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	suf=sufcnt=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			suf+=i;
			sufcnt++;
		}
	}
	ans=LLINF;
	pre=precnt=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='0') continue;
		suf-=i;
		sufcnt--;
		ans=min(ans,suf-1LL*i*sufcnt-1LL*(sufcnt+1)*sufcnt/2
				   +1LL*i*precnt-pre-1LL*(precnt+1)*precnt/2);
		pre+=i;
		precnt++;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
x4 x5 x6 i x1 x2 x3
x1-i-1
x2-i-2
x3-i-3

*/
