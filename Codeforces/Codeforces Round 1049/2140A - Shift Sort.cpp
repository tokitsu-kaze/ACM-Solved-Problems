#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,cnt0,ans;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		cnt0=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0') cnt0++;
		}
		ans=0;
		for(i=1;i<=cnt0;i++)
		{
			if(s[i]=='1') ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
