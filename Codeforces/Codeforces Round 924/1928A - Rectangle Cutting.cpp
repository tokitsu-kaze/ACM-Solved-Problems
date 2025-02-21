#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int mod=1e9+7;
const int MAX=4e5+10;
int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		if(a%2==0 && b%2==0)
		{
			if(a/2==b && b/2==a) puts("No");
			else puts("Yes");
		}
		else if(a%2==0)
		{
			if(a/2==b) puts("No");
			else puts("Yes");
		}
		else if(b%2==0)
		{
			if(b/2==a) puts("No");
			else puts("Yes");
		}
		else puts("No");
	}
	return 0;
}
