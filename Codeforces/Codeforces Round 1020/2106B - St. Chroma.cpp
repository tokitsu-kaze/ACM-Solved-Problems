#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX];
int main()
{
	int T,n,x,i,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		tot=0;
		for(i=0;i<x;i++) p[++tot]=i;
		for(i=n-1;i>=x;i--) p[++tot]=i;
		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	}
	return 0;
}
