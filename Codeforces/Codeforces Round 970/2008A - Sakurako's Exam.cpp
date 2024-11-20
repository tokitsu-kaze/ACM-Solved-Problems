#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		b%=2;
		if(b && a>1)
		{
			a-=2;
			b=0;
		}
		a%=2;
		if(a==0 && b==0) puts("YES");
		else puts("NO");
	}
	return 0;
}
