#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int mod=998244353;
int main()
{
	int T,n,i,ok;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ok=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]!='z') ok=1;
			s[i]='z';
		}
		s[n+1]='\0';
		if(ok) puts(s+1);
		else puts("-1");
	}
	return 0;
}
