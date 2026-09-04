#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int n,a,b,ans,i;
	char s[12];
	scanf("%d",&n);
	ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%s",&a,&b,s);
		if(s[0]=='k') ans+=b-a;
	}
	printf("%d\n",ans);
	return 0;
}
