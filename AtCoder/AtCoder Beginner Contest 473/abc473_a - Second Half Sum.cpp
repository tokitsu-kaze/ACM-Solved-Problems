#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1000+10;
int main()
{
	int n,i,x,sum;
	scanf("%d",&n);
	sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(i>n/2) sum+=x;
	}
	printf("%d\n",sum);
	return 0;
}
