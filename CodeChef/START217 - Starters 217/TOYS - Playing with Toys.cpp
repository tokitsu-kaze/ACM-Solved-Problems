#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5000+10;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",max(0,a-b));
	return 0;
}
