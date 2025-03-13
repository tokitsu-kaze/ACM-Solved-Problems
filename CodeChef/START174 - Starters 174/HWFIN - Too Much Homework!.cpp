#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	if((100-x)<=10*y) puts("YES");
	else puts("NO");
	return 0;
}
