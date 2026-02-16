#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=500+10;
int main()
{
	int T,n,i,ans;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		ans=n;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='1')
			{
				ans=i-1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
