#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,cnt,ok;
	char s[11],t[11];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		scanf("%s",t+1);
		cnt=0;
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0' && t[i]=='1') ok=0;
			else if(s[i]=='1' && t[i]=='0') cnt++;
		}
		if(cnt%2==0 && ok) puts("Yes");
		else puts("No");
	}
	return 0;
}
