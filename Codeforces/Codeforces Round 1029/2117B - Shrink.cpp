#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int p[MAX];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		p[1]=1;
		p[n]=2;
		for(i=2;i<n;i++) p[i]=i+1;
		for(i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
	}
	return 0;
}
