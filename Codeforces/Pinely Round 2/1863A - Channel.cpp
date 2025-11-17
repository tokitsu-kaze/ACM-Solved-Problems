#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,a,q,i,now,tot,mx;
	char s[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&a,&q);
		scanf("%s",s+1);
		now=tot=a;
		mx=a;
		for(i=1;i<=q;i++)
		{
			if(s[i]=='+')
			{
				now++;
				tot++;
			}
			else now--;
			mx=max(mx,now);
		}
		if(mx==n) puts("YES");
		else if(tot<n) puts("NO");
		else puts("MAYBE");
	}
	return 0;
}
