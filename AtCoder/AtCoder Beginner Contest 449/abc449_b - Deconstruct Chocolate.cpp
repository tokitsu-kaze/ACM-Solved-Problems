#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
int main()
{
	int n,m,q,op,x,ans;
	scanf("%d%d%d",&n,&m,&q);
	while(q--)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
		{
			ans=x*m;
			n-=x;
		}
		else
		{
			ans=x*n;
			m-=x;
		}
		printf("%d\n",ans);
	}
	return 0;
}
