#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int main()
{
	int n,m,i,c,s,mx[105];
	scanf("%d%d",&n,&m);
	memset(mx,-1,sizeof mx);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&c,&s);
		mx[c]=max(mx[c],s);
	}
	for(i=1;i<=m;i++) printf("%d%c",mx[i]," \n"[i==m]);
	return 0;
}
