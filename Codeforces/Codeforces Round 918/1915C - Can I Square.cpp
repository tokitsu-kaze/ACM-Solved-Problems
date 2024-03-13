#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int t,n,i,x;
	ll s,sq;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			s+=x;
		}
		sq=sqrt(s);
		while(sq*sq<s) sq++;
		while(sq*sq>s) sq--;
		if(sq*sq==s) puts("YES");
		else puts("NO");
	}
	return 0;
}
