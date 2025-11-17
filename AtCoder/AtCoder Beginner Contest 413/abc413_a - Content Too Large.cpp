#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e4+10;
int main()
{
	int n,m,i,x,s;
	scanf("%d%d",&n,&m);
	s=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s+=x;
	}
	if(s<=m) puts("Yes");
	else puts("No");
	return 0;
}
