#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,q,d,i,x,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&q,&d);
		while(q--)
		{
			scanf("%d",&x);
			ok=0;
			for(i=1;i<=9;i++)
			{
				if(i*d<=x && x%10==(i*d)%10) ok=1;
			}
			if(x>=10*d) ok=1;
			if(ok) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
