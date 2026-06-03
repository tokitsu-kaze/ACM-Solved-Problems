#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int x;
	scanf("%d",&x);
	if(x%5<=2) x-=x%5;
	else x=x+5-x%5;
	printf("%d\n",x);
	return 0;
}
