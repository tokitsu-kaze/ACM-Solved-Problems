#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
int main()
{
	int T,n,x,i,now;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		x=0;
		now=-1;
		while(1)
		{
			x+=now;
			if(now<0) now=(abs(now)+2);
			else now=-(abs(now)+2);
			if(abs(x)>n) break;
		}
		if(now<0) puts("Kosuke");
		else puts("Sakurako");
	}
	return 0;
}
