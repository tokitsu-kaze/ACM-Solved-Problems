#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
int main()
{
	int t,a[5];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		printf("%d\n",a[1]);
	}
	return 0;
}
