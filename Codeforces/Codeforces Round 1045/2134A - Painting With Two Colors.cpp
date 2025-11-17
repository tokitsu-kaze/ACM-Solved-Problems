#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,a,b,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&a,&b);
		ok=1;
		if((n-b)%2) ok=0;
		if(a>b)
		{
			if((n-a)%2) ok=0;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
