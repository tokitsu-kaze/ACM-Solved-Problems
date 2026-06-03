#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int n,x,i,a;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a<x)
		{
			x=a;
			puts("1");
		}
		else puts("0");
	}
	return 0;
}
