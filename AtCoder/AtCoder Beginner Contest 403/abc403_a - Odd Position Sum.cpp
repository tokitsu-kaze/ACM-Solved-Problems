#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,s,x;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(i&1) s+=x;
	}
	printf("%d\n",s);
	return 0;
}
