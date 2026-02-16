#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int t,x,y,z,ok;
	scanf("%d%d%d",&x,&y,&z);
	ok=0;
	t=1e5;
	while(t--)
	{
		if(y*z==x)
		{
			ok=1;
			break;
		}
		x++;
		y++;
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
