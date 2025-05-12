#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX],t[MAX];
int main()
{
	int T,n,m,i,j,ok,cnta,cntb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		ok=1;
		i=j=1;
		while(i<=n && j<=m)
		{
			if(s[i]!=t[j])
			{
				ok=0;
				break;
			}
			cnta=cntb=0;
			while(i+cnta<=n && s[i+cnta]==s[i]) cnta++;
			while(j+cntb<=m && t[j+cntb]==t[j]) cntb++;
			if(cntb>=cnta && cntb<=cnta*2);
			else
			{
				ok=0;
				break;
			}
			i+=cnta;
			j+=cntb;
		}
		if(i<=n||j<=m) ok=0;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
