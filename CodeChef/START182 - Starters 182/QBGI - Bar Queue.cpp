#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char s[MAX];
int main()
{
	int T,n,i,b,g;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		b=g=0;
		for(i=1;i<=n;i++)
		{
			if(s[i]=='B') b++;
			else g++;
			if(b>g*2) break;
		}
		printf("%d\n",b+g);
	}
	return 0;
}
