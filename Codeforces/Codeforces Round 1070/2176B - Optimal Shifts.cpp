#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
char s[MAX];
int main()
{
	int T,n,i,now,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(i=n+1;i<=2*n;i++) s[i]=s[i-n];
		ans=0;
		now=0;
		for(i=1;i<=2*n;i++)
		{
			if(s[i]=='0') now++;
			else now=0;
			ans=max(ans,now);
		}
		printf("%d\n",ans);
	}
	return 0;
}
