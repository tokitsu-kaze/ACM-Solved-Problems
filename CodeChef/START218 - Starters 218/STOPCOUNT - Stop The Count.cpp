#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int T,n,i,now,ans;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		now=ans=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1') now++;
			else now--;
			if(now>0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
