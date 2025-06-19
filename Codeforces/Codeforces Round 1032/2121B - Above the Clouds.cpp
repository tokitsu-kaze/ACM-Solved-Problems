#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,pre[256],suf[256],ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		memset(pre,0,sizeof pre);
		memset(suf,0,sizeof suf);
		for(i=n;i;i--) suf[s[i]]++;
		ok=0;
		for(i=1;i<=n;i++)
		{
			suf[s[i]]--;
			if(i>1 && i<n && (pre[s[i]]||suf[s[i]])) ok=1;
			pre[s[i]]++;
		}
		if(ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
