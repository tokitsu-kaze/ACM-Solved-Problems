#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int n,i,ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	ans=0;
	for(i=1;i+2<=n;i++)
	{
		if(s[i]=='#' && s[i+1]=='.' && s[i+2]=='#') ans++;
	}
	printf("%d\n",ans);
	return 0;
}
