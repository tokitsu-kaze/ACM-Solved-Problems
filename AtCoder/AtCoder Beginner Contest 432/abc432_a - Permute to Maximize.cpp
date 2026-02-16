#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int a[3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	reverse(a,a+3);
	for(int i=0;i<3;i++) printf("%d",a[i]);
	puts("");
	return 0;
}
