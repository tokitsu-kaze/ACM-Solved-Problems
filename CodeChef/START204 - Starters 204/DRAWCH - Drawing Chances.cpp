#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e6+10;
int main()
{
	int T,n,m,i,cnt;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		cnt=0;
		for(i=1;i<=m;i++)
		{
			if(s[i]=='0') cnt++;
			else cnt--;
		}
		cnt=abs(cnt);
		if(n&1)
		{
			puts("No");
			continue;
		}
		if(n-m>=cnt) puts("Yes");
		else puts("No");
	}
	return 0;
}
