#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,ok;
	char s[55];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		if(s[1]=='A' && s[n]=='A') puts("Alice");
		else if(s[n]=='A' && s[n-1]=='A') puts("Alice");
		else
		{
			ok=1;
			for(i=1;i<=n-1;i++) ok&=(s[i]=='A');
			if(ok) puts("Alice");
			else puts("Bob");
		}
	}
	return 0;
}

