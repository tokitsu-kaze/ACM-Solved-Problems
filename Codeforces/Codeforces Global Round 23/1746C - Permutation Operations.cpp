#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX],pos[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&p[i]);
		for(i=1;i<=n;i++) pos[p[i]]=i;
		for(i=1;i<=n;i++) printf("%d%c",min(pos[i]+1,n)," \n"[i==n]);
	}
	return 0;
}
