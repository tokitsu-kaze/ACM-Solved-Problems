#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int mp[105][105];
int main()
{
	int n,i,j,ok,a,b,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++) scanf("%d",&mp[i][j]);
	}
	ok=0;
	for(a=1;a<=n;a++)
	{
		for(b=a+1;b<=n;b++)
		{
			for(c=b+1;c<=n;c++)
			{
				if(mp[a][b]+mp[b][c]<mp[a][c]) ok=1;
			}
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
