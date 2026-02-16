#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=50+10;
int main()
{
	int a,b,x,y;
	scanf("%d%d",&a,&b);
	scanf("%d%d",&x,&y);
	if(a<=x && x<=a+100-1 && b<=y && y<=b+100-1) puts("Yes");
	else puts("No");
	return 0;
}
