#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int n,i,j,res[5],x;
	scanf("%d",&n);
	memset(res,0,sizeof res);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		x%=1000;
		x=1000-x;
		for(j=1;j<=3;j++)
		{
			res[j]+=x%10;
			x/=10;
		}
	}
	for(i=1;i<=3;i++) printf("%d%c",res[i]," \n"[i==3]);
	return 0;
}
