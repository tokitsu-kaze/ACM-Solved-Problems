#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int T,n,m,i,ans,len;
	char s[12];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%s",s);
			len=strlen(s);
			m-=len;
			if(m>=0) ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
