#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int T,n,i;
	char s[105],ans[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=1;i<=n;i++) ans[i]=s[n];
		ans[n+1]='\0';
		puts(ans+1);
	}
	return 0;
}
