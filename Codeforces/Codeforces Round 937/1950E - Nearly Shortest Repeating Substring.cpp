#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
char s[MAX];
int main()
{
	int T,n,i,j,k,ans,ra,rb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		ans=n;
		for(k=1;k<=n;k++)
		{
			if(n%k) continue;
			ra=rb=0;
			for(i=0;i<n;i++)
			{
				if(s[i]!=s[i%k]) ra++;
				if(i%k+k<n && s[i]!=s[i%k+k]) rb++;
			}
			if(ra<=1 || rb<=1) ans=min(ans,k);
		}
		printf("%d\n",ans);
	}
	return 0;
}
