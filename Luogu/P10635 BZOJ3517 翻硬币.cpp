#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
char s[MAX][MAX];
int x[MAX],y[MAX];
int main()
{
	int n,i,j,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%s",s[i]+1);
	memset(x,0,sizeof x);
	memset(y,0,sizeof y);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s[i][j]=='1')
			{
				x[i]++;
				y[j]++;
			}
		}
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			ans+=(s[i][j]-'0'+x[i]+y[j])&1;
		}
	}
	printf("%d\n",min(n*n-ans,ans));
	return 0;
}
