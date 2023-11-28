#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int n,c1,c2,i,ans;
	char s[11];
	scanf("%d%d%d",&n,&c1,&c2);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		sort(s,s+3);
		if(s[0]==s[1]||s[1]==s[2]) ans+=min({min(c1,c2)+c2,3*c1,3*c2});
		else ans+=min({3*c1,3*c2});
	}
	printf("%d\n",ans);
	return 0;
}
