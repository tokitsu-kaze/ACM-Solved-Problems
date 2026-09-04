#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,d,i,j,ans,ok;
	char s[105];
	scanf("%d%d",&n,&d);
	scanf("%s",s+1);
	ans=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]!='.') continue;
		ok=1;
		for(j=1;j<=n;j++)
		{
			if(s[j]=='G' && abs(i-j)<=d) ok=0;
		}
		ans+=ok;
	}
	printf("%d\n",ans);
	return 0;
}
