#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,k,i;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=k;i++) s[i]='1';
		for(i=k+1;i<=n;i++) s[i]='0';
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
