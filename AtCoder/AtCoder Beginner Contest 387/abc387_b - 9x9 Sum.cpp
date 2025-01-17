#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=3e5+10;
const int mod=1e9+7;
int main()
{
	int n=9;
	int i,j,x,ans;
	scanf("%d",&x);
	ans=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i*j!=x) ans+=i*j;
		}
	}
	printf("%d\n",ans);
	return 0;
}
