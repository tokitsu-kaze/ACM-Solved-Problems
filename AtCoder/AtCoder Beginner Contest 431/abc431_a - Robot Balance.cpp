#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int h,b;
	scanf("%d%d",&h,&b);
	printf("%d\n",max(0,h-b));
	return 0;
}
