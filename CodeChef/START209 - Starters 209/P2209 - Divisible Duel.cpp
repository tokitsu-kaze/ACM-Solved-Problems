#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,x,y,i,ra,rb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		ra=rb=0;
		for(i=x;i<=y;i+=x)
		{
			if(i%2==0) ra+=i;
			else rb+=i;
		}
		if(ra>=rb) puts("YES");
		else puts("NO");
	}
	return 0;
}
