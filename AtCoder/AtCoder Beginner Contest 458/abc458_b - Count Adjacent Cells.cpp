#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int main()
{
	int n,m,i,j,cnt;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cnt=0;
			if(i-1>=1) cnt++;
			if(i+1<=n) cnt++;
			if(j-1>=1) cnt++;
			if(j+1<=m) cnt++;
			printf("%d%c",cnt," \n"[j==m]);
		}
	}
	return 0;
}
