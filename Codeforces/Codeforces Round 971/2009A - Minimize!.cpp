#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e6+10;
int main()
{
	int T,a,b,c,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		ans=INF;
		for(c=a;c<=b;c++) ans=min(ans,(c-a)+(b-c));
		printf("%d\n",ans);
	}
	return 0;
}
