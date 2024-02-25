#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int t,n,k,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		i=1;
		ans=0;
		while(i<=n)
		{
			if(s[i]=='W') i++;
			else
			{
				ans++;
				i+=k;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
