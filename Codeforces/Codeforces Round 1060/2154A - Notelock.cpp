#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
char s[MAX];
int main()
{
	int T,n,k,i,ans,pre;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		pre=-INF;
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='0') continue;
			if(pre+k-1<i) ans++;
			pre=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
