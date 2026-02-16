#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char s[MAX];
int main()
{
	int T,n,i,ok,mn,mx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		if(n==1)
		{
			puts("1");
			continue;
		}
		ok=0;
		mn=n+1;
		mx=0;
		s[0]=s[n+1]='0';
		for(i=1;i<=n;i++)
		{
			if(s[i]=='*' && (s[i-1]=='>' || s[i+1]=='<')) ok=1;
			else if(s[i]=='*' && s[i-1]=='*') ok=1;
			else if(s[i]=='<') mx=max(mx,i);
			else if(s[i]=='>') mn=min(mn,i);
		}
		if(ok || mn<mx) puts("-1");
		else printf("%d\n",max(mn-1,n-mx));
	}
	return 0;
}
