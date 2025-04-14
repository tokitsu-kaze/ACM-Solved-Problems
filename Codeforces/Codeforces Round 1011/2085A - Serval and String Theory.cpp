#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,i,eq,ok;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		eq=1;
		for(i=1;i<=n;i++)
		{
			if(s[i]!=s[1]) eq=0;
		}
		if(eq)
		{
			puts("NO");
			continue;
		}
		ok=0;
		for(i=1;i<n-i+1;i++)
		{
			if(s[i]<s[n-i+1])
			{
				ok=1;
				break;
			}
			if(s[i]>s[n-i+1])
			{
				ok=0;
				break;
			}
		}
		if(ok==1||k>0) puts("YES");
		else puts("NO");
	}
	return 0;
}

