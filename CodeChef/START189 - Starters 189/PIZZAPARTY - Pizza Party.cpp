#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	a++;
	printf("%d\n",(a*4+b*3+7)/8);
	return 0;
}
