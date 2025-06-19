#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,cnt,now;
	char s[66];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		cnt=0;
		now=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0') now++;
			else now--;
			if(now==0) cnt++;
		}
		printf("%lld\n",1LL<<cnt);
	}
	return 0;
}
