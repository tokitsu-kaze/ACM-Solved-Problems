#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int T,n,a,b,i,x,y,ok;
	char s[12];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&a,&b);
		scanf("%s",s);
		x=y=ok=0;
		for(i=0;i<=1000;i++)
		{
			if(s[i%n]=='N') y++;
			else if(s[i%n]=='E') x++;
			else if(s[i%n]=='S') y--;
			else x--;
			if(x==a && y==b) ok=1;
		}
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
